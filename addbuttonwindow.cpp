#include "addbuttonwindow.h"
#include <QApplication>
AddButtonWindow::AddButtonWindow():ShowOrSetData(QString(""),QString(""),QString(""),QString(""),QString("img/poll.jpg"))
{
    setWindowTitle(QApplication::translate("toplevel", "Add Data"));
}
