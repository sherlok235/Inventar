#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRect rec = a.primaryScreen()->geometry();
    int height = rec.height();
    int width = rec.width();
    MainWindow w;
    w.setMinimumWidth(width*0.25);
    w.setMinimumHeight(height*0.25);
    w.show();
    return a.exec();
}
