#include "advsettings.h"
#include "ui_advsettings.h"

advSettings::advSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::advSettings)
{
    ui->setupUi(this);
}

advSettings::~advSettings()
{
    delete ui;
}
