#ifndef TESTCONSTAINER_H
#define TESTCONSTAINER_H

#include <QMainWindow>
#include <cstdlib>
#include "qcustomplot.h"
#include "specan.h"

class TestConstainer
{
public:
    TestConstainer(QMainWindow* PARENT, QCustomPlot* PLOT, Specan* SPECAN,
                   int TESTNUM, QString NAME, double RBW,
                   double SWEEPTIME ,int SWEEPNUM,
                   double FREQCENTER, double FREQSPAN, float THRESHOLD);
    void RunSweep();
    QString getName();
private:

    QMainWindow *parent;
    QCustomPlot *plot;
    Specan *specan;
    int testNum;
    double rbw;
    double sweepTime;
    int sweepNum;
    QString name;
    double freqCenter;
    double freqSpan;
    float threshold;
    QVector<double> dataReturn;
    QVector<float> dataHold;
    QVector<uint32_t> freqArray;
    QVector<float> peakArray;
    QVector<uint32_t> peakFreqArray;
    QString title;
    int dataMax=-20;
    int dataMin=-100;
};

#endif // TESTCONSTAINER_H
