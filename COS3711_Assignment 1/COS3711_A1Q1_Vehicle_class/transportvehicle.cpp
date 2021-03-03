#include "transportvehicle.h"

const int MIN_CAPACITY_KG = 1;
const int MAX_CAPACITY_KG = 40000;

//Contructors and destructors**************************************************************
TransportVehicle::TransportVehicle() : Vehicle ()
{

}

TransportVehicle::TransportVehicle(QObject *parent, QString model, int year, int capacityKg) :
    Vehicle (parent, model, year)
{
    setCapacityKg(capacityKg);
}

//Getters**********************************************************************************
int TransportVehicle::getCapacityKg()
{
    return _capacityKg;
}

//Setters**********************************************************************************
void TransportVehicle::setCapacityKg(int capacityKg)
{
    //< "MIN_CAPACITY_KG is: " << MIN_CAPACITY_KG << "\n";
    //std::cout << "MAX_CAPACITY_KG is: " << MAX_CAPACITY_KG << "\n";

    if ((capacityKg < MIN_CAPACITY_KG) || (capacityKg > MAX_CAPACITY_KG))
    {
        std::cout << "Error: the capacity is not valid\n";
        exit(-2);
    }
    else {
        _capacityKg = capacityKg;
        //std::cout << "...Carry capacity in kg was set to: " << _capacityKg << "\n";
    }
}

//Overloaded operators*********************************************************************

//Member functions*************************************************************************
void TransportVehicle::print()
{
    Vehicle::print();
    std::cout << "\tCarry capacity: " << _capacityKg << "\n";
}
