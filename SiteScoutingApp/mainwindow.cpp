#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bb_api.h"
#include <QtCharts>
#include "testconstainer.h"
#include <cstdlib>

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_FindSpecan->setEnabled(true);
    ui->btn_RunTest->setEnabled(false);
    ui->btn_SaveAs->setEnabled(false);

    this->createDefaultTests();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::openSignalHound()
{
    ui->specInfoLabel->setText("Finding Devices...");
    buttonsEnabled(false);
    qApp->processEvents();

    this->drawPlot();
    bool status = specan->findSpecan();
    if(!status) {
        ui->specInfoLabel->setText("Error Finding Device");
        ui->btn_FindSpecan->setEnabled(true);
        ui->btn_RunTest->setEnabled(false);
        ui->btn_SaveAs->setEnabled(false);
        return 0;
    }

    ui->specInfoLabel->setText("Device found!");
    buttonsEnabled(true);
    return 1;
}

void MainWindow::buttonsEnabled(bool trueFalse)
{
    if(trueFalse)
    {
        ui->btn_FindSpecan->setEnabled(true);
        ui->btn_RunTest->setEnabled(true);
        ui->btn_SaveAs->setEnabled(true);
    }
    else
    {
        ui->btn_FindSpecan->setEnabled(false);
        ui->btn_RunTest->setEnabled(false);
        ui->btn_SaveAs->setEnabled(false);
    }
}

void MainWindow::createDefaultTests()
{
    while(!testList.empty())
    {
        testList.pop_back();
    }

    testList.push_back(new TestConstainer(this, ui->plot, specan, 0, "test1", 100e6, .010, 20, 1000e6, 1000e6, -75 ));
    testList.push_back(new TestConstainer(this, ui->plot, specan, 0, "test2", 100e6, .010, 20, 1000e6, 1000e6, -75 ));
    testList.push_back(new TestConstainer(this, ui->plot, specan, 0, "test3", 100e6, .010, 20, 1000e6, 1000e6, -75 ));
    testList.push_back(new TestConstainer(this, ui->plot, specan, 0, "test4", 100e6, .010, 20, 1000e6, 1000e6, -75 ));
    testList.push_back(new TestConstainer(this, ui->plot, specan, 0, "test5", 100e6, .010, 20, 1000e6, 1000e6, -75 ));
}

void MainWindow::on_btn_FindSpecan_clicked()
{
    openSignalHound();
}

void MainWindow::drawPlot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->plot->xAxis->setRange(-1, 1);
    ui->plot->yAxis->setRange(0, 1);
    ui->plot->replot();

    QString msg="";
    for(int i=0; i<testList.size();i++)
    {
        msg+=testList[i]->getName();
    }
    ui->runInfoLabel->setText(msg);
}


void MainWindow::on_btn_RunTest_clicked()
{
    for(int i=0; i<testList.size();i++)
    {
        testList[i]->RunSweep();
    }
}
