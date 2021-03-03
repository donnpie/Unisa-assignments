#ifndef READINGMATERIAL_H
#define READINGMATERIAL_H
//readingmaterial.h
#include "stock.h"

class ReadingMaterial : public Stock
{
    Q_OBJECT

public:
    ReadingMaterial();
    ReadingMaterial(QString i, int q, QString f);
        //sets _item to i and _quantity to q and _frequency to f

public:
    QString getFrequency();
    void setFrequency(QString f);
    QString toString();

private:
    QString _frequency;
};

#endif // READINGMATERIAL_H
