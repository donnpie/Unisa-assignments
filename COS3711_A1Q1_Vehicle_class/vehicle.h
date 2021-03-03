#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>
#include <stdlib.h> //exit
#include <iostream> //cout

class Vehicle : public QObject
{
    Q_OBJECT
public:
//Contructors and destructors**************************************************************
    Vehicle(QObject *parent = nullptr, QString model = "No Model specified", int year = 2020);

//Signals and Slots************************************************************************
signals:

public slots:

//Getters and setters**********************************************************************
QString getModel();
int getYear();

void setModel(QString model); //Set _model to model
void setYear(int year); //Set _year to year. year must be between 1900 and 2050

//Overloaded operators*********************************************************************

//Member functions*************************************************************************
public:
    virtual void print(); //Prints the details for this instance

//Data members*****************************************************************************
private:
    QString _model;
    int _year;
};

#endif // VEHICLE_H


