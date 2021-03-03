#include "filewriter.h"

FileWriter::FileWriter(QObject *parent) : QObject(parent)
{
    this->setParent(parent);
}

FileWriter::FileWriter(QObject *parent, QObjectList list, QString filename) :
    _list(list), _filename(filename)
{
    this->setParent(parent);
}

int FileWriter::write()
{
    QFile file(_filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cout << "Error: File could not be opened\n";
        return 0;
    }

    QTextStream out(&file);
    const char * pname;
    QVariant p; //A variant that holds the specified property

    int counter = 0;
    foreach (auto obj, _list)
    {

        //const QMetaObject * mo = obj->metaObject();
        /* Can't get this to work
        for (int i = mo->propertyOffset(); i < mo->propertyCount(); i++)
        {
            pname = mo->property(i).name();
            p = obj->property(pname);
            out << p.toString();
        }
        */

        //this is a workaround
        pname = "model";
        p = obj->property(pname);
        out << "Model: " << p.toString() << "\n";

        pname = "year";
        p = obj->property(pname);
        out << "Year: " << p.toString() << "\n";



        //PassengerVehicle *pv = qobject_cast<PassengerVehicle*>(obj);
        PassengerVehicle *pv = dynamic_cast<PassengerVehicle*>(obj);
        if (pv != 0)
        {
            QVariant p = pv->property("passengerCount");
            out << "Passenger count: " << p.toInt() << "\n"; //This doesn't work!

        }

        //TransportVehicle *tv = qobject_cast<TransportVehicle*>(obj);
        TransportVehicle *tv = dynamic_cast<TransportVehicle*>(obj);
        if (tv != 0)
        {
            QVariant p = tv->property("capacityKg");
            out << "Carry capacity kg: " << p.toInt() << "\n"; //This doesn't work!

        }

        counter++;
    }

    file.close();

    return counter;

}
