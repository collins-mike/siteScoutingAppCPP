#include "specan.h"
#include "bb_api.h"
#include <cstdlib>

Specan::Specan()
{

}

bool Specan::findSpecan()
{
    bbStatus openStatus = bbOpenDevice(&handle);
    if(openStatus != bbNoError) {
        return false;
    }
    return true;
}

void Specan::getFullSweep(float* sweepReturn)
{
    // Configure a sweep from 850MHz to 950MHz with an
    //  RBW and VBW of 10kHz and an expected input of -20dBm
    bbConfigureAcquisition(handle, BB_MIN_AND_MAX, BB_LOG_SCALE);
    bbConfigureCenterSpan(handle, freqCenter, freqSpan);
    bbConfigureLevel(handle, -20.0, BB_AUTO_ATTEN);
    bbConfigureGain(handle, BB_AUTO_GAIN);
    bbConfigureSweepCoupling(handle, rbw, rbw, sweepTime, BB_RBW_SHAPE_FLATTOP, BB_NO_SPUR_REJECT);
    bbConfigureProcUnits(handle, BB_POWER);

    // Configuration complete, initialize the device
    if(bbInitiate(handle, BB_SWEEPING, 0) != bbNoError) {
        // Handle error
    }

    // Get sweep characteristics and allocate memory for sweep
    unsigned int sweepSize;
    double binSize, startFreq;
    bbQueryTraceInfo(handle, &sweepSize, &binSize, &startFreq);

    float *min = new float[sweepSize];
    float *max = new float[sweepSize];

    // Get one or many sweeps with these configurations
    bbFetchTrace_32f(handle, sweepSize, min, max);

    delete [] min;
    delete [] max;
}

void Specan::setRBW(double RBW)
{
    this->rbw = RBW;
}

void Specan::setSweepTime(double ST)
{
    this->sweepTime=ST;
}

void Specan::setFreqCenter(double FC)
{
    this->freqCenter=FC;
}

void Specan::setFreqSpan(double FS)
{
    this->freqSpan=FS;
}
