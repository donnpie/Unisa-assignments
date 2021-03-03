#include "confectionery.h"

Confectionery::Confectionery() : Stock ()
{
    setWeight(-1); //set to invalid weight
}

Confectionery::Confectionery(QString i, int q, int w)
    : Stock(i, q)
{
    setWeight(w);
}

void Confectionery::operator=(Confectionery &other)
{
    qDebug() << "calling overloaded operator=";
    this->_item = other._item;
    this->_quantity = other._quantity;
    this->_weight = other._weight;
}

int Confectionery::getWeight()
{
    return _weight;
}

void Confectionery::setWeight(int w)
{
    if (_weight != w)
    {
        _weight = w;
    }
    else {
        qDebug() << "New value is the same as the old value. Weight not set.";
    }
}

QString Confectionery::toString()
{
    QString head = "Confectionery item:\n";
    QString item = "\tItem: " + _item + "\n";
    QString quantity = "\tQuantity: " + QString::number(_quantity) + "\n";
    QString weight = "\tWeight: " + QString::number(_weight) + "\n";

    return head + item + quantity + weight;
}
