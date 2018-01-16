/********************************************************************************
** Form generated from reading UI file 'advsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVSETTINGS_H
#define UI_ADVSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_advSettings
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *table;

    void setupUi(QDialog *advSettings)
    {
        if (advSettings->objectName().isEmpty())
            advSettings->setObjectName(QStringLiteral("advSettings"));
        advSettings->resize(792, 333);
        buttonBox = new QDialogButtonBox(advSettings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(440, 300, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        table = new QTableWidget(advSettings);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(10, 20, 771, 211));

        retranslateUi(advSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), advSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), advSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(advSettings);
    } // setupUi

    void retranslateUi(QDialog *advSettings)
    {
        advSettings->setWindowTitle(QApplication::translate("advSettings", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class advSettings: public Ui_advSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVSETTINGS_H
