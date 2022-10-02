#include "mainwindow.h"

#include <QApplication>
#include <QInputDialog>
#include <QTranslator>
#include <QStringList>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRect rec = a.primaryScreen()->geometry();

    int height = rec.height();
    int width = rec.width();


    QTranslator t;
    QStringList Languages;
    Languages << "English" << "Русский" << "Română";
    QString Lang = QInputDialog::getItem(NULL, "Select Language","Language",Languages);//created a dialog window
    // Chose language
    if(Lang == "English")
        if( t.load(":/translation/English.qm"))
            a.installTranslator(&t);

    if (Lang == "Русский")
        if(t.load(":/translation/Russia.qm"))
            a.installTranslator(&t);

    if (Lang == "Română")
        if(t.load(":/translation/Romanian.qm"))
            a.installTranslator(&t);


    MainWindow w;
    //set window size
    w.setMinimumWidth(width*0.25);
    w.setMinimumHeight(height*0.25);
    w.show();
    return a.exec();
}
