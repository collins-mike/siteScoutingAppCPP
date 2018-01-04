#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "specan.h"
#include <QtCharts>

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int openSignalHound();
    void buttonsEnabled(bool);
    void drawAChart();

private slots:
    void on_btn_FindSpecan_clicked();

private:
    Ui::MainWindow *ui;
    Specan specan;
};

#endif // MAINWINDOW_H
