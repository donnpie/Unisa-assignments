#include "vehiclelist.h"

VehicleList::VehicleList(QObject *parent) : QObject(parent)
{

}

void VehicleList::printAll()
{
    //int vehicleCount = this->children().count();
    //for (int i = 0; i < vehicleCount; i++)
    //{
    //    this->children().at(i)->print();
    //}

    std::cout << "Printing list of all vehicles:\n";
    QList<Vehicle*> list = this->findChildren<Vehicle*>();
    foreach (auto obj, list)
    {
        obj->print();
    }
}

QObjectList VehicleList::getList()
{
    return this->children();
}



//Getters**********************************************************************************
//Setters**********************************************************************************
