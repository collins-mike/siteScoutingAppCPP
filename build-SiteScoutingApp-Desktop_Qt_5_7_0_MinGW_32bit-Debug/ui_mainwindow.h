/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_FindSpecan;
    QLabel *specInfoLabel;
    QPushButton *btn_RunTest;
    QPushButton *btn_SaveAs;
    QLabel *runInfoLabel;
    QLabel *saveInfoLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(869, 453);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_FindSpecan = new QPushButton(centralWidget);
        btn_FindSpecan->setObjectName(QStringLiteral("btn_FindSpecan"));
        btn_FindSpecan->setGeometry(QRect(20, 30, 171, 81));
        specInfoLabel = new QLabel(centralWidget);
        specInfoLabel->setObjectName(QStringLiteral("specInfoLabel"));
        specInfoLabel->setGeometry(QRect(200, 30, 221, 81));
        btn_RunTest = new QPushButton(centralWidget);
        btn_RunTest->setObjectName(QStringLiteral("btn_RunTest"));
        btn_RunTest->setGeometry(QRect(20, 120, 171, 81));
        btn_SaveAs = new QPushButton(centralWidget);
        btn_SaveAs->setObjectName(QStringLiteral("btn_SaveAs"));
        btn_SaveAs->setGeometry(QRect(20, 210, 171, 81));
        runInfoLabel = new QLabel(centralWidget);
        runInfoLabel->setObjectName(QStringLiteral("runInfoLabel"));
        runInfoLabel->setGeometry(QRect(200, 120, 221, 81));
        saveInfoLabel = new QLabel(centralWidget);
        saveInfoLabel->setObjectName(QStringLiteral("saveInfoLabel"));
        saveInfoLabel->setGeometry(QRect(200, 210, 221, 81));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 869, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_FindSpecan->setText(QApplication::translate("MainWindow", "Find Spectrum Analyzer", 0));
        specInfoLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        btn_RunTest->setText(QApplication::translate("MainWindow", "Run Test", 0));
        btn_SaveAs->setText(QApplication::translate("MainWindow", "Save As", 0));
        runInfoLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        saveInfoLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
