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
#include "custombutton.h"
#include "addbuttonwindow.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    DBInterface IDB;
    QListWidget * MyList;
    ShowOrSetData * secondWindow = nullptr;
    Data * SwapButtonData;
    QPushButton * AddButon, * DeletButton;
    QHBoxLayout * AddButtonLayout,* DeleteButtonLayout;
    bool SaveButtonStatus;
public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void ShowInfoWindow();
    void ShowAddWindow();
    void UpdateData(Data * data);
    void AddNewData(Data * data);
    void SetButtonD(CustomButton * button, Data * data);
    void IsClickedSave(bool a);


private:
    Ui::MainWindow *ui;
    void PutData(void);
};

#endif // MAINWINDOW_H
