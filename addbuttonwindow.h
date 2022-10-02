/*
This class is used to create a new button and add it in the main window and to add new data in DB (Data Base)

*/
#ifndef ADDBUTTONWINDOW_H
#define ADDBUTTONWINDOW_H

#include "showorsetdata.h"

class AddButtonWindow : public ShowOrSetData //Simple inherit
{
public:

    AddButtonWindow();

private slots:

    void save();

};

#endif // ADDBUTTONWINDOW_H
