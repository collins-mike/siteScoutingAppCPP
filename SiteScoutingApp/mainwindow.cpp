#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bb_api.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_FindSpecan->setEnabled(true);
    ui->btn_RunTest->setEnabled(false);
    ui->btn_SaveAs->setEnabled(false);
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

    bbStatus openStatus = bbOpenDevice(&handle);
    if(openStatus != bbNoError) {
        ui->specInfoLabel->setText("Error Finding Device");
        ui->btn_FindSpecan->setEnabled(true);
        ui->btn_RunTest->setEnabled(false);
        ui->btn_SaveAs->setEnabled(false);
        return 0;
    }

    ui->specInfoLabel->setText(bbGetErrorString(openStatus));
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
