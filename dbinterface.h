#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVector>

struct Data{                //   My own data structure for easier work with data in DB
    int code;
    QString name;
    QString description;
    int quantity;
    QString pathImg;
};

class DBInterface
{
    QVector<Data> * AllData = nullptr; //  Temporarily stored data from DB
    QSqlDatabase db;

public:
    DBInterface();
    bool addData(const int code,const QString name,const QString description,const int quantity,const QString pathImg);
    bool addData(const Data MyData);

    const QVector<Data> * getAllData (void);

    void UpdateDB();
    void UpdateRow(Data * change);
    void DeleteRow(int idRow);
    ~DBInterface();

};

#endif // DBINTERFACE_H
