#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custombutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    MyList = new QListWidget;

    ui->setupUi(this);

    this->PutData();

    MyList->setSpacing(0);
    MyList->setParent(this);
    MyList->setContentsMargins(0,0,0,0);
    MyList->setMinimumSize(this->size());
    MyList->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    MyList->verticalScrollBar()->hide();

  //  QObject::connect(secondWindow,&ShowOrSetData::saveBtn_signal,this,&MainWindow::UpdateData);

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
     delete secondWindow;
}

void MainWindow::UpdateData(CustomButton  * button)
{
    Data * data = new Data ;
    data->code =button->getCode().toInt();
    data->description = button->getDescription();
    data->name = button->getName();
    data->pathImg = button->getImgPath();
    data->quantity = button->getQuantity().toInt();
    IDB.UpdateRow(data);
    delete data;
}

MainWindow::~MainWindow()
{
    //MyList->clear();
    //delete MyList;
    delete ui;
}


