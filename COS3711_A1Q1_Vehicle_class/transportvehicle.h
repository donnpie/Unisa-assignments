#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include "vehicle.h"

class TransportVehicle : public Vehicle
{
public:
//Contructors and destructors**************************************************************
        TransportVehicle();
        TransportVehicle(QObject* parent, QString model, int year, int capacityKg);


//Getters**********************************************************************************
public:
    int getCapacityKg();


//Setters**********************************************************************************
public:
    void setCapacityKg(int capacityKg); //Set _passengerCount to passengerCount. passengerCount must be between 1 and 100
                                        //_passengerCount exludes the driver
//Overloaded operators*********************************************************************
//Signals and Slots************************************************************************
//Member functions*************************************************************************
public:
    void print(); //vitual

//Data members*****************************************************************************
private:
    int _capacityKg;
};

#endif // TRANSPORTVEHICLE_H
