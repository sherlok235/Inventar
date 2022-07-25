#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    MyList = new QListWidget;
    mainLayout = new QVBoxLayout;
    exemplar = new item(MyList);
    ui->setupUi(this);

    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb.sqlite");
    this->initDb();

    //MyList.add
    MyList->addItem(exemplar);
    exemplar->setSizeHint(QSize(125,24));
  //  exemplar->btn->setSizeIncrement(125,25);
   // exemplar->btn->show();
    mainLayout->addWidget(MyList);
   // MyList->addItem(&it);
    ui->centralwidget->setLayout(mainLayout);
    db.close();
}
void MainWindow::initDb(){
    std::fstream obj("somename.txt");
    db.open();
    QSqlQuery q ;
    QString data="" ;

    q.exec("insert into items values(?,?,?, ?,?)");
    q.bindValue(0,908890);
    q.bindValue(1,"kolo");
    q.bindValue(2,"jucari pentru copii");
    q.bindValue(3,65);
    q.bindValue(4,"tottr/titro/rorj");
    q.exec();

    q.exec("insert into items values(?,?,?, ?,?)");
    q.bindValue(0,934890);
    q.bindValue(1,"apa");
    q.bindValue(2,"apa distilata");
    q.bindValue(3,95);
    q.bindValue(4,"tottr/titro/rorj");
    q.exec();
    q.exec(".save mydb.sqlite");

    q.exec("select * from items");
    if( q.isValid()){
        exemplar->setText(q.executedQuery());
    }
      exemplar->setText(db.lastError().text());
    while(q.next()){
       data+=q.value(0).toString()+"  " +q.value(1).toString()+"\n";
       data+=q.value(2).toString()+"  "+ q.value(3).toString()+"\n";
       data+=q.value(4).toString()+"\n";

    }

    if(!q.lastError().text().isEmpty()){
        data = q.lastError().text();
    }
    obj<<data.toStdString();
    exemplar->setText(data);

    q.clear();
    db.close();

}
MainWindow::~MainWindow()
{

    delete ui;
}

