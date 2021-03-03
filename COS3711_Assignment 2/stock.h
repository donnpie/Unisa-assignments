#ifndef STOCK_H
#define STOCK_H
//stock.h
//provides an abstract base class for stock items

#include <QDebug>
#include <QString>
#include <QObject>
//#include <iostream>


class Stock : public QObject
{
    Q_OBJECT

public:
    Stock();
    Stock(QString i, int q);
        //sets _item to i and _quantity to q
    virtual ~Stock();

public:
    QString getItem();
    int getQuantity();
    void setItem(QString i);
    void setQuantity(int q);
    virtual QString toString() = 0; //make this a pure virtual function so the class cannot be instantiated


protected:
    QString _item;
    int _quantity;
};

#endif // STOCK_H
