#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QRect>
#include <QRegion>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    MyList = new QListWidget;
    AddButon = new QPushButton("Button",MyList);
   // DeletButton = new QPushButton(this);

    AddButon->setFixedSize(70,70);
    AddButon->setGeometry(QRect(this->width()-5,this->height()-10,70,70));
    //DeletButton->setFixedSize(50,50);
    QRect rect(0,0,69,69);
    QRegion region(rect,QRegion::Ellipse);
    AddButon->setMask(region);


    UpadteButtonData = new Data;

    ui->setupUi(this);

    this->PutData();

    MyList->setSpacing(0);
    MyList->setParent(this);
    MyList->setContentsMargins(0,0,0,0);
    MyList->setMinimumSize(this->size());
    MyList->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    MyList->verticalScrollBar()->hide();



}
void MainWindow::PutData(){

   const QVector<Data> * myData ;
    QString Pathimg;
   myData = IDB.getAllData();
   for( QVector<Data>::const_iterator it = myData->cbegin(); it<myData->end();it++){
       if(!QFileInfo::exists(it->pathImg)){
           Pathimg = "img/poll.jpg";
       }else{
            Pathimg=it->pathImg;
       }
        CustomButton * button = new CustomButton(Pathimg,it->name,QString(std::to_string(it->code).c_str()),it->description,it->quantity);
        QListWidgetItem * itemN = new QListWidgetItem() ;
        itemN->setSizeHint(QSize(400,90));
        MyList->addItem(itemN);
        MyList->setItemWidget(itemN,button);
        QObject::connect(button,SIGNAL(clicked()),this,SLOT(ShowInfoWindow()));


   }

}

void MainWindow::ShowInfoWindow()
{
    CustomButton * button = static_cast<CustomButton *>(QObject::sender());
    secondWindow = new ShowOrSetData(button->getName(),button->getCode(),button->getDescription()
                                          ,button->getQuantity(), button->getImgPath());
    secondWindow->setModal(true);
    QObject::connect(secondWindow,&ShowOrSetData::saveBtn_signal,this,&MainWindow::UpdateData);
    secondWindow->exec();
    SetButtonD(button,secondWindow->getData());
    delete secondWindow;
}

void MainWindow::UpdateData(Data * data)
{

    UpadteButtonData->code = data->code;
    UpadteButtonData->description = data->description;
    UpadteButtonData->name = data->name;
    UpadteButtonData->pathImg = data->pathImg;
    UpadteButtonData->quantity = data->quantity;
    IDB.UpdateRow(UpadteButtonData);

}

void MainWindow::SetButtonD(CustomButton *button, Data *data)
{
    button->setImage(data->pathImg);
    button->setDescription_Info(data->name,QString(std::to_string(data->code).c_str()),data->description);
    button->setQuantity(data->quantity);
}

MainWindow::~MainWindow()
{
    delete UpadteButtonData;
    delete ui;
}


