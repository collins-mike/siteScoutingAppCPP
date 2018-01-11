#ifndef ADVSETTINGS_H
#define ADVSETTINGS_H

#include <QDialog>

namespace Ui {
class advSettings;
}

class advSettings : public QDialog
{
    Q_OBJECT

public:
    explicit advSettings(QWidget *parent = 0);
    ~advSettings();

private:
    Ui::advSettings *ui;
};

#endif // ADVSETTINGS_H
