#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_btn_FindSpecan_clicked();

private:
    Ui::MainWindow *ui;
    int handle;
};

#endif // MAINWINDOW_H
