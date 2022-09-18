#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QRect>
#include <QRegion>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    SaveButtonStatus = false;
    MyList = new QListWidget;
    AddButon = new QPushButton(MyList);
    AddButon->setFixedSize(70,70);
    AddButon->setGeometry(QRect(MyList->width()-(-55),MyList->height()-(-25),70,70));
    QRect rect(0,0,69,69);
    QRegion region(rect,QRegion::Ellipse);
    AddButon->setMask(region);
    QImage * img = new QImage;
    bool Case =  img->load("img/add.png");
    if (Case){
        QIcon ic ;
        ic.addPixmap(QPixmap::fromImage(*img));
        AddButon->setIcon(ic);
        AddButon->setIconSize(QSize(69,69));
    }
    delete img;
    connect(AddButon,SIGNAL(clicked()),this, SLOT(ShowAddWindow()));
    SwapButtonData = new Data;

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
    QObject::connect(secondWindow,&ShowOrSetData::SendStatusSave,this,&MainWindow::IsClickedSave);
    secondWindow->exec();
    if (SaveButtonStatus)
    SetButtonD(button,secondWindow->getData());
    delete secondWindow;
    SaveButtonStatus = false;
}

void MainWindow::ShowAddWindow()
{
    CustomButton * button = new CustomButton;
    button->setImage("img/poll.jpg");
    secondWindow = new AddButtonWindow();
    secondWindow->setModal(true);
    QObject::connect(secondWindow,&ShowOrSetData::saveBtn_signal,this,&MainWindow::AddNewData);
    QObject::connect(secondWindow,&ShowOrSetData::SendStatusSave,this,&MainWindow::IsClickedSave);
    secondWindow->exec();
    if (SaveButtonStatus){
    SetButtonD(button,secondWindow->getData());
    QListWidgetItem * itemN = new QListWidgetItem() ;
    itemN->setSizeHint(QSize(400,90));
    MyList->addItem(itemN);
    MyList->setItemWidget(itemN,button);
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(ShowInfoWindow()));
    SaveButtonStatus = false;
    }
    delete secondWindow;
   // delete button;


}

void MainWindow::UpdateData(Data * data)
{

    SwapButtonData->code = data->code;
    SwapButtonData->description = data->description;
    SwapButtonData->name = data->name;
    SwapButtonData->pathImg = data->pathImg;
    SwapButtonData->quantity = data->quantity;
    IDB.UpdateRow(SwapButtonData);

}

void MainWindow::AddNewData(Data *data)
{
    SwapButtonData->code = data->code;
    SwapButtonData->description = data->description;
    SwapButtonData->name = data->name;
    SwapButtonData->pathImg = data->pathImg;
    SwapButtonData->quantity = data->quantity;
    IDB.addData(*SwapButtonData);
}

void MainWindow::SetButtonD(CustomButton *button, Data *data)
{
    button->setImage(data->pathImg);
    button->setDescription_Info(data->name,QString(std::to_string(data->code).c_str()),data->description);
    button->setQuantity(data->quantity);
}

void MainWindow::IsClickedSave(bool a)
{
    SaveButtonStatus = a;
}

MainWindow::~MainWindow()
{
    delete SwapButtonData;
    delete ui;
}


