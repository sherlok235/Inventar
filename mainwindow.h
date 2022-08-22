#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QScrollBar>
#include <QListView>
#include <QLayout>
#include <QLabel>
#include <QDebug>

#include "dbinterface.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    DBInterface IDB;
    QListWidget * MyList;
    QVBoxLayout * mainLayout;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void PutData(void);
};

#endif // MAINWINDOW_H
