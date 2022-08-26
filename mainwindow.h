#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QScrollBar>
#include <QFileInfo>
#include <QLayout>
#include <QLabel>

#include "dbinterface.h"
#include "showorsetdata.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    DBInterface IDB;
    QListWidget * MyList;
    ShowOrSetData * secondWindow = nullptr;
public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void ShowInfoWindow();
    void UpdateData(CustomButton * button);

private:
    Ui::MainWindow *ui;
    void PutData(void);
};

#endif // MAINWINDOW_H
