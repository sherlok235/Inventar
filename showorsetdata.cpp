#include <QFileDialog>

#include "showorsetdata.h"
#include "ui_showorsetdata.h"

ShowOrSetData::ShowOrSetData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowOrSetData)
{
    button = new CustomButton;
    ui->setupUi(this);
    ui->img->setVisible(false);
    QObject::connect(this->ui->choseButton,SIGNAL(clicked()),this,SLOT(chose()));
    QObject::connect(this->ui->saveButton,SIGNAL(clicked()),this,SLOT(save()));
    //QObject::connect(this,&ShowOrSetData::saveBtn_signal,this,&MainWindow::UpdateData);

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

ShowOrSetData::ShowOrSetData(CustomButton *button)
{
this->button = button;
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
    button->setDescription_Info(ui->nameLine->text(),ui->barcodeLine->text(),ui->descriptionLine->text());
    button->setImage(ChoseImgPath);
    button->setQuantity(ui->qantityLine->text().toInt());
    emit saveBtn_signal(this->button);
    this->close();
}

ShowOrSetData::~ShowOrSetData()
{
    delete ui;
}


