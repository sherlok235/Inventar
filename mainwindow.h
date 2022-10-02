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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    DBInterface IDB;
    ShowOrSetData * secondWindow = nullptr;//   Destined to edit data
    Data * SwapButtonData;

    QListWidget * MyList;
    QPushButton * AddButon, * DeletButton;
    QHBoxLayout * AddButtonLayout,* DeleteButtonLayout;

    bool SaveButtonStatus;

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void ShowInfoWindow();
    void ShowAddWindow();
    void UpdateData(Data * data);// update data on the main window
    void AddNewData(Data * data);// add new data on the main window
    void SetButtonD(CustomButton * button, Data * data); //set for the button Y the data X
    void IsClickedSave(bool a);

private:

    Ui::MainWindow *ui;
    void PutData(void);
};

#endif // MAINWINDOW_H
