#include "readingmaterial.h"

ReadingMaterial::ReadingMaterial() : Stock ()
{
    setFrequency("Unspecified frequency");
}

ReadingMaterial::ReadingMaterial(QString i, int q, QString f)
    : Stock (i, q)
{
    setFrequency(f);
}

QString ReadingMaterial::getFrequency()
{
    return _frequency;
}

void ReadingMaterial::setFrequency(QString f)
{
    if (_frequency != f)
    {
        _frequency = f;
    }
    else {
        qDebug() << "New value is the same as the old value. Frequency not set.";
    }
}

QString ReadingMaterial::toString()
{
    QString head = "Reading material item:\n";
    QString item = "\tItem: " + _item + "\n";
    QString quantity = "\tQuantity: " + QString::number(_quantity) + "\n";
    QString frequency = "\tFrequency: " + _frequency + "\n";

    return head + item + quantity + frequency;
}
