#include "dbinterface.h"
#include <fstream>
DBInterface::DBInterface()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("newmydb.sqlite");
  {//  AllData = new QVector<Data>;
    // db.open();
//    QSqlQuery q;
//    size_t i =0;
//    q.exec("SELECT * FROM items");
//    while(q.next()){
//        AllData->push_front( Data());
//        AllData[i].data()->code = q.value(0).toInt();
//        AllData[i].data()->name = q.value(1).toString();
//        AllData[i].data()->description = q.value(2).toString();
//        AllData[i].data()->quantity = q.value(3).toInt();
//        AllData[i].data()->pathImg = q.value(4).toString();
//    }

//    q.clear();
//    db.close();
}
    UpdateDB();
}

bool DBInterface::addData(const int code, const QString name, const QString description, const int quantity, const QString pathImg)
{
    std::fstream f ("sometext.txt",std::ios_base::out);//delete////////////////
    bool result =false;
    db.open();

    QSqlQuery q ;
    q.prepare(QString("INSERT INTO items VALUES(?,?,?,?,?)"));
    q.bindValue(0,code);
    q.bindValue(1,name);
    q.bindValue(2,description);
    q.bindValue(3,quantity);
    q.bindValue(4,pathImg);
    if(  q.exec()){
        q.clear();
        result = true;
    }
    f<<q.lastError().text().toStdString();//delete//////////////////////////
    q.clear();
    db.close();
    f.close();//delete ///////////////////////////////////////
    return result;
}

bool DBInterface::addData(const Data MyData)
{
return addData(MyData.code,MyData.name,MyData.description,MyData.quantity,MyData.pathImg);
}

const QVector<Data> * DBInterface::getAllData()
{
    return this->AllData;
}

void DBInterface::UpdateDB()
{
    if(AllData != nullptr)
        delete AllData ;
    AllData = new QVector<Data>;
    db.open();
    QSqlQuery q;
    size_t i =0;
    q.exec("SELECT * FROM items");
    while(q.next()){
        AllData->push_front( Data());
        AllData[i].data()->code = q.value(0).toInt();
        AllData[i].data()->name = q.value(1).toString();
        AllData[i].data()->description = q.value(2).toString();
        AllData[i].data()->quantity = q.value(3).toInt();
        AllData[i].data()->pathImg = q.value(4).toString();
    }

    q.clear();
    db.close();


}

void DBInterface::UpdateRow(Data * change)
{
    db.open();
    QSqlQuery q;

    q.prepare("UPDATE items SET name = ?, descriere = ?,cantitate = ?,i_path = ? WHERE id = ?");
    q.bindValue(0,change->name);
    q.bindValue(1,change->description);
    q.bindValue(2,change->quantity);
    q.bindValue(3,change->pathImg);
    q.bindValue(4,change->code);
    q.exec();

    q.clear();
    db.close();

}

DBInterface::~DBInterface(){
    delete AllData;
}
