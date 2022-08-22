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


}
void MainWindow::PutData(){
//    QString * data=new QString(" ") ;
//    bool bo = IDB.addData(90097808,"lllko","ouitkt tt",98,"puoou//y/uu//maaaaama");


//    data->append( QString::number(bo )+IDB.getAllData()->at(0).name+"  ");
//    data->append( IDB.getAllData( )->at(0).description + "pol");
    //exemplar->setText(*data);

   const QVector<Data> * myData ;

   myData = IDB.getAllData();
   //const  QVector<Data>::const_iterator it;
   for( QVector<Data>::const_iterator it = myData->cbegin(); it<myData->end();it++){
        QListWidgetItem * itemN = new QListWidgetItem() ;
        itemN->setSizeHint(QSize(400,90));
      // mainLayout->addWidget(new CustomButton(QString(std::string("poll.jpg").c_str()),it->name,QString(std::to_string(it->code).c_str()),it->description,it->quantity));
       MyList->addItem(itemN);
       MyList->setItemWidget(itemN,new CustomButton(QString(std::string("img/poll.jpg").c_str()),it->name,QString(std::to_string(it->code).c_str()),it->description,it->quantity));

   }

}
MainWindow::~MainWindow()
{
    delete ui;
}

