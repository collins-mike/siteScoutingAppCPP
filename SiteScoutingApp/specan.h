#ifndef SPECAN_H
#define SPECAN_H
#include <vector>

class Specan
{
public:
    Specan();
    bool findSpecan();
    void getFullSweep(std::vector<float>* sweepReturn);

    void setRBW(double);
    void setSweepTime(double);
    void setFreqCenter(double);
    void setFreqSpan(double);
    int handle;

private:

    double rbw;
    double sweepTime;
    double freqCenter;
    double freqSpan;
};

#endif // SPECAN_H
