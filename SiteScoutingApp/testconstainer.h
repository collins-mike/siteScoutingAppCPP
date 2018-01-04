#ifndef TESTCONSTAINER_H
#define TESTCONSTAINER_H

#include <QMainWindow>
#include <cstdlib>

class TestConstainer
{
public:
    TestConstainer();
    void RunSweep();
private:
    int testNum;
    uint16_t rbw;
    float sweepTime;
    uint16_t sweepNum;
    QString name;
    uint32_t freqCenter;
    uint32_t freqSpan;
    float threshold;
    std::vector<float> dataReturn;
    std::vector<float> dataHold;
    std::vector<uint32_t> freqArray;
    std::vector<float> peakArray;
    std::vector<uint32_t> peakFreqArray;
    QString title;
    int dataMax=-20;
    int dataMin=-100;
};

#endif // TESTCONSTAINER_H
