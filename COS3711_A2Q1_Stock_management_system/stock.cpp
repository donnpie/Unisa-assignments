#include "stock.h"

Stock::Stock()
{
    setItem("Unspecified item");
    setQuantity(0);
}

Stock::Stock(QString i, int q)
{
    setItem(i);
    setQuantity(q);
}

Stock::~Stock()
{

}

QString Stock::getItem()
{
    return _item;
}

int Stock::getQuantity()
{
    return  _quantity;
}

void Stock::setItem(QString i)
{
    if (_item != i)
    {
        _item = i;
    }
    else {
        qDebug() << "New value is the same as the old value. Item not set.";
    }

}

void Stock::setQuantity(int q)
{
    if (_quantity != q)
    {
        _quantity = q;
    }
    else {
        qDebug() << "New value is the same as the old value. Quantity not set.";
    }
}
