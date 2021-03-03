#ifndef CONFECTIONERY_H
#define CONFECTIONERY_H

//confectionery.h
#include "stock.h"


class Confectionery : public Stock
{
    Q_OBJECT

public:
    Confectionery();
    Confectionery(QString i, int q, int w);
        //sets _item to i and _quantity to q and _weight to w

public:
    void operator=(Confectionery& other);

public:
    int getWeight();
    void setWeight(int w);
    QString toString();

private:
    int _weight;
};

#endif // CONFECTIONERY_H
