#ifndef SHOWORSETDATA_H
#define SHOWORSETDATA_H

#include <QDialog>
#include <QImage>
#include <QString>
#include "dbinterface.h"
#include "custombutton.h"

namespace Ui {
class ShowOrSetData;
}

class ShowOrSetData : public QDialog
{
    Q_OBJECT
    QString Pathimg, ChoseImgPath;
    QImage image ;
    CustomButton * button;

public:
    explicit ShowOrSetData(QWidget *parent = nullptr);
    explicit ShowOrSetData(QString name,QString code,QString qescription,QString quantity,QString imgPath);
    explicit ShowOrSetData(CustomButton * button);
    ~ShowOrSetData();

private slots:

void chose();
void save();

signals:
void saveBtn_signal(CustomButton * button);
private:
    Ui::ShowOrSetData *ui;
};

#endif // SHOWORSETDATA_H
