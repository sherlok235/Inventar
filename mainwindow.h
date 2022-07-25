#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QSqlDatabase>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QSqlQuery>
#include <QSqlError>
#include <QListView>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    class item : public QListWidgetItem
    {
       // Q_OBJECT
    public:
        QPushButton * btn ;
        QLabel lb;
        item(QWidget *parent){
           btn = new QPushButton("push",parent);
            btn->show();
            lb.show();

        }
        void setText(QString s){
            lb.setText(s);
        }
        ~item(){
            delete btn;
        }
    };
    item * exemplar;
    QSqlDatabase db;
    QListWidget * MyList;
    QVBoxLayout * mainLayout;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initDb(void);
};

#endif // MAINWINDOW_H
