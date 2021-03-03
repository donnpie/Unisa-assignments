#ifndef PASSENGERVEHICLE_H
#define PASSENGERVEHICLE_H
#include "vehicle.h"


class PassengerVehicle : public Vehicle
{
    //Q_OBJECT
//QProperties
    Q_PROPERTY(int passengerCount READ getPassengerCount WRITE setPassengerCount)
public:
//Contructors and destructors**************************************************************
    PassengerVehicle();
    PassengerVehicle(QObject* parent, QString model, int year, int passengerCount);


//Getters**********************************************************************************
public:
    int getPassengerCount();


//Setters**********************************************************************************
public:
    void setPassengerCount(int passengerCount); //Set _passengerCount to passengerCount. passengerCount must be between 1 and 100
                                        //_passengerCount exludes the driver
//Overloaded operators*********************************************************************
//Signals and Slots************************************************************************
//Member functions*************************************************************************
public:
    void print(); //vitual

//Data members*****************************************************************************
private:
    int _passengerCount;
};

#endif // PASSENGERVEHICLE_H


