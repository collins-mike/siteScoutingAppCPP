#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bb_api.h"
#include <QtCharts>

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_FindSpecan->setEnabled(true);
    ui->btn_RunTest->setEnabled(false);
    ui->btn_SaveAs->setEnabled(false);
    ui->mainToolBar->addWidget(ui->chart);
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

    bool status = specan.findSpecan();
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

void MainWindow::on_btn_FindSpecan_clicked()
{
    openSignalHound();
}

void MainWindow::drawAChart()
{
    QLineSeries *series = new QLineSeries();

    series->append(0, 6);
      series->append(2, 4);
      series->append(3, 8);
      series->append(7, 4);
      series->append(10, 5);
      *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

     QChart *chart = new QChart();
     chart->legend()->hide();
     chart->addSeries(series);
     chart->createDefaultAxes();
     chart->setTitle("Simple line chart example");

     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     ui->chart->setAutoFillBackground(true);

}
