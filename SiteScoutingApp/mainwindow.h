#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdlib>
#include <QMainWindow>
#include "specan.h"
#include "testconstainer.h"

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
    void drawPlot();
    void createDefaultTests();

private slots:
    void on_btn_FindSpecan_clicked();

    void on_btn_RunTest_clicked();

private:
    Ui::MainWindow *ui;
    Specan* specan = new Specan;
    std::vector<TestConstainer*> testList;
};

#endif // MAINWINDOW_H
