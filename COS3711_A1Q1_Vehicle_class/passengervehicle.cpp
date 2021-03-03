#include "passengervehicle.h"

const int MIN_PASSENGER_COUNT = 1;
const int MAX_PASSENGER_COUNT = 100;

//Contructors and destructors**************************************************************
PassengerVehicle::PassengerVehicle() : Vehicle(), _passengerCount(1)
{

}

PassengerVehicle::PassengerVehicle(QObject *parent, QString model, int year, int passengerCount)
 :Vehicle (parent, model, year)
{
    setPassengerCount(passengerCount);
}

//Getters**********************************************************************************
int PassengerVehicle::getPassengerCount()
{
    return _passengerCount;
}

//Setters**********************************************************************************
void PassengerVehicle::setPassengerCount(int passengerCount)
{
    //std::cout << "Setting passenger count...\n";
    //std::cout << "MIN_PASSENGER_COUNT is: " << MIN_PASSENGER_COUNT << "\n";
    //std::cout << "MAX_PASSENGER_COUNT is: " << MAX_PASSENGER_COUNT << "\n";

    if ((passengerCount < MIN_PASSENGER_COUNT) || (passengerCount > MAX_PASSENGER_COUNT))
    {
        std::cout << "Error: the passenger count is not valid\n";
        exit(-2);
    }
    else {
        _passengerCount = passengerCount;
        //std::cout << "...Passenger count was set to: " << _passengerCount << "\n";
    }
}


//Overloaded operators*********************************************************************
//Member functions*************************************************************************
void PassengerVehicle::print()
{
    Vehicle::print();
    std::cout << "\tPassengers: " << _passengerCount << "\n";
}





