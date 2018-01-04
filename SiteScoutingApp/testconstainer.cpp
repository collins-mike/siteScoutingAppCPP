#include "testconstainer.h"
#include "qcustomplot.h"

TestConstainer::TestConstainer(QMainWindow *PARENT, QCustomPlot *PLOT, Specan *SPECAN,
                               int TESTNUM, QString NAME, double RBW,
                               double SWEEPTIME ,int SWEEPNUM,
                               double FREQCENTER, double FREQSPAN, float THRESHOLD)
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
}

void TestConstainer::RunSweep()
{
    //clear vectors/arrays
    dataReturn.clear();
    dataHold.clear();
    freqArray.clear();
    peakArray.clear();
    peakFreqArray.clear();
    double startFreq  = this->freqCenter - this->freqSpan/2;
    double endFreq    = this->freqCenter + this->freqSpan/2;


    for(int i=0;i<this->sweepNum;i++)
    {
        //specan->getFullSweep();


    }


}

QString TestConstainer::getName()
{
    return name;
}
