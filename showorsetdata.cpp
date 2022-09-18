#include <QFileDialog>

#include "showorsetdata.h"
#include "ui_showorsetdata.h"

ShowOrSetData::ShowOrSetData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowOrSetData)
{
    SaveIsCliked = false;
    mydata = new Data;
    ui->setupUi(this);
    ui->img->setVisible(false);
    QObject::connect(this->ui->choseButton,SIGNAL(clicked()),this,SLOT(chose()));
    QObject::connect(this->ui->saveButton,SIGNAL(clicked()),this,SLOT(save()));

}

ShowOrSetData::ShowOrSetData(QString name, QString code, QString description, QString quantity,QString imgPath):ShowOrSetData()
{
    ui->nameLine->setText(name);
    ui->barcodeLine->setText(code);
    ui->descriptionLine->setText(description);
    ui->qantityLine->setText(quantity);
    Pathimg=imgPath;
    this->image.load(imgPath);
    ui->img->setPixmap(QPixmap::fromImage(this->image));

}

void ShowOrSetData::chose()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("chose"),"",tr("Images(*.png *.jpg *jpeg *bmp *gif)"));
    ChoseImgPath = fileName;
    if(QString::compare(fileName,QString())!=0){
        QImage image ;
        bool valid = image.load(fileName);
        if(valid){
        ui->img->setVisible(true);
        ui->img->setPixmap(QPixmap::fromImage(image));
        }
    }
}

 void ShowOrSetData::save()
{
    mydata->quantity =  ui->qantityLine->text().toInt();
    mydata->code = ui->barcodeLine->text().toInt();
    mydata->description = ui->descriptionLine->text();
    mydata->name = ui->nameLine->text();
    if(!QFileInfo::exists(ChoseImgPath)){
        mydata->pathImg = Pathimg;
    }else{
         mydata->pathImg = ChoseImgPath;
    }
    emit SendStatusSave(true);
    emit saveBtn_signal(mydata);
    this->close();
}

ShowOrSetData::~ShowOrSetData()
{
    delete mydata;
    delete ui;
}

QString ShowOrSetData::getImage()
{
    return Pathimg;
}

Data *ShowOrSetData::getData()
{
 return mydata;
}


