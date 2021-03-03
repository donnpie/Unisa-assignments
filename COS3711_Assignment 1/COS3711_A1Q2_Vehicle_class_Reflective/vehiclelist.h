#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <QObject>
#include "vehicle.h"

class VehicleList : public QObject
{
    Q_OBJECT
//Contructors and destructors**************************************************************
public:
    explicit VehicleList(QObject *parent = nullptr);

//Getters and setters**********************************************************************
//Overloaded operators*********************************************************************
//Signals and Slots************************************************************************
signals:

public slots:


//Member functions*************************************************************************
    void printAll(); //Prints all the vehicles on the children list
    QObjectList getList(); //Returns the list of child objects
//Data members*****************************************************************************
};

#endif // VEHICLELIST_H





