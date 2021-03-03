#include "vehicle.h"

const int MIN_YEAR = 1900;
const int MAX_YEAR = 2500;

Vehicle::Vehicle(QObject *parent, QString model, int year)
{
    this->setParent(parent);
    setModel(model);
    setYear(year);
    //std::cout << "Vehicle object created\n";
}

QString Vehicle::getModel()
{
    return _model;
}

int Vehicle::getYear()
{
    return  _year;
}

void Vehicle::setModel(QString model)
{
    //std::cout << "Setting model...\n";
    _model = model;
    //std::cout << "...model was set to: " << _model.toStdString() << "\n";
}

void Vehicle::setYear(int year)
{
    //std::cout << "Setting year...\n";
    //std::cout << "MIN_YEAR is: " << MIN_YEAR << "\n";
    //std::cout << "MAX_YEAR is: " << MAX_YEAR << "\n";

    if ((year < MIN_YEAR) || (year > MAX_YEAR))
    {
        std::cout << "Error: the year is not valid\n";
        exit(-1);
    }
    else {
        _year = year;
        //std::cout << "...Year was set to: " << _year << "\n";
    }
}


void Vehicle::print()
{
    std::cout << "Vehice details:\n";
    std::cout << "\tModel: " << _model.toStdString() << "\n";
    std::cout << "\tYear: " << _year << "\n";
}
