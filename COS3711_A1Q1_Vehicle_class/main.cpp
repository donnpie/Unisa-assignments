#include <QCoreApplication>
#include <QDebug>
#include "vehicle.h"
#include "passengervehicle.h"
#include "vehiclelist.h"
#include "transportvehicle.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Test code for vehicleList class
    VehicleList vl1;


    //Test code for vechile class
    Vehicle v1; //test default constructor
    Vehicle v2(nullptr, "New Model", 1999); //test default constructors with parameters
    v2.print();

    //Test code for PassengerVehicle class
    PassengerVehicle pv1; //default
    PassengerVehicle pv2(&vl1, "T-Rex 2000", 2001, 5);
    pv2.print();
    PassengerVehicle pv3(&vl1, "T-Rex 2001", 2002, 6);

    //Test code for TransportVehicle class
    TransportVehicle tv1; //default
    TransportVehicle tv2(&vl1, "SuperLoad 5000", 2003, 5000);
    tv2.print();
    TransportVehicle tv3(&vl1, "SuperLoad 10000", 2004, 10000);

    vl1.printAll(); //print all vehicles in list

    //Test the list function
    QObjectList list = vl1.getList();
    std::cout << "Number of vehicles in list: " << list.count() << "\n";


    return a.exec();
}
