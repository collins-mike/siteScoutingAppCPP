#include "testconstainer.h"
#include "qcustomplot.h"
#include "bb_api.h"

TestConstainer::TestConstainer(QMainWindow *PARENT, QCustomPlot *PLOT, Specan *SPECAN,
                               int TESTNUM, QString NAME, double RBW,
                               double SWEEPTIME ,int SWEEPNUM,
                               double FREQCENTER, double FREQSPAN, float THRESHOLD, double REFERENCE)
{
    this->parent    = PARENT;
    this->plot      = PLOT;
    this->specan    = SPECAN;

    testNum         = TESTNUM;
    name            = NAME;
    rbw             = RBW;
    sweepTime       = SWEEPTIME;
    sweepNum        = SWEEPNUM;
    freqCenter      = FREQCENTER;
    freqSpan        = FREQSPAN;
    threshold       = THRESHOLD;
    reference       = REFERENCE;
}

void TestConstainer::RunSweep()
{
    //clear vectors/arrays
    dataReturn.clear();
    dataHold.clear();
    freqArray.clear();
    peakArray.clear();
    peakFreqArray.clear();
    //double startFreq  = this->freqCenter - this->freqSpan/2;
    double endFreq    = this->freqCenter + this->freqSpan/2;


    for(int i=0;i<this->sweepNum;i++)
    {

        //specan->getFullSweep(&dataReturn);
        // Configure a sweep from 850MHz to 950MHz with an
        //  RBW and VBW of 10kHz and an expected input of -20dBm
        bbConfigureAcquisition(specan->handle, BB_MIN_AND_MAX, BB_LOG_SCALE);
        bbConfigureCenterSpan(specan->handle, freqCenter, freqSpan);
        bbConfigureLevel(specan->handle, reference, BB_AUTO_ATTEN);
        bbConfigureGain(specan->handle, BB_AUTO_GAIN);
        bbConfigureSweepCoupling(specan->handle, rbw, rbw, sweepTime, BB_RBW_SHAPE_FLATTOP, BB_NO_SPUR_REJECT);
        bbConfigureProcUnits(specan->handle, BB_POWER);

        // Configuration complete, initialize the device
        if(bbInitiate(specan->handle, BB_SWEEPING, 0) != bbNoError) {
            // Handle error
        }

        // Get sweep characteristics and allocate memory for sweep
        unsigned int sweepSize;
        double binSize, startFreq;
        bbQueryTraceInfo(specan->handle, &sweepSize, &binSize, &startFreq);

        float *min = new float[sweepSize];
        float *max = new float[sweepSize];

        // Get one or many sweeps with these configurations
        bbFetchTrace_32f(specan->handle, sweepSize, min, max);

        for(unsigned int i=0;i<sweepSize;i++)
        {
            dataReturn.push_back(max[i]);
        }


        QVector<double> freqs;
        for (double i=0; i<sweepSize; ++i)
        {
          freqs.push_back(startFreq+i*binSize);
        }

        double plotMinY=getDoubleVectorMin(dataReturn);
        // create graph and assign data to it:
        plot->addGraph();
        plot->graph(0)->setData(freqs, dataReturn);
        // give the axes some labels:
        plot->xAxis->setLabel("x");
        plot->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        plot->xAxis->setRange(startFreq,endFreq);
        plot->yAxis->setRange(plotMinY-10,0);
        plot->replot();

        freqs.clear();
        dataReturn.clear();

        delete [] min;
        delete [] max;

    }
}

double TestConstainer::getDoubleVectorMin(QVector<double> &vect)
{
    double min=vect[0];
    for(int i=0;i<vect.length();i++)
    {
        if(vect[i]<min)
        {
            min=vect[i];
        }
    }
    return min;
}

QString TestConstainer::getName()
{
    return name;
}
