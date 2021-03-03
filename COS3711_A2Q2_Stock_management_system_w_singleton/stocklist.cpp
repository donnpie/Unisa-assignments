#include "stocklist.h"
#include <cstring>
#include <iostream>

int StockList::_instanceCount = 0; //initialise static variable, note that we must use the int keyword again, eventhough it has been declared in the class


StockList::StockList(QObject *parent) : QObject(parent)
{
    //_instanceCount = 1;  //Apparently static variables cannot be initialised in the constructor
    _instanceCount++;
}

StockList *StockList::getInstance()
{
    if (_instanceCount == 0)
    {
        //_instanceCount++; //moved this to the constructor
        return new StockList;
    }
    else {
        qDebug() << "Error: There can be only one instance of the StockList class\n";
        return nullptr;
    }

}

void StockList::addStock(Stock *s)
{
    std::cout << "Stock type: " << s->metaObject()->className() << "\n";

    if (std::strncmp(s->metaObject()->className(), "Confectionery", 50) == 0)
    {
        //_confectioneryList.push_back(dynamic_cast<Confectionery*>(s));
        _confectioneryList.push_back(s);
        qDebug() << "Object " << s->getItem() << " was added to Confectionery list\n";
    }
    else if (std::strncmp(s->metaObject()->className(), "ReadingMaterial", 50) == 0)
    {
        //_readingMaterialList.push_back(dynamic_cast<Confectionery*>(s));
        _readingMaterialList.push_back(s);
        qDebug() << "Object " << s->getItem() << " was added to ReadingList list\n";
    }
    else {
        qDebug() << "Error: Stock object could not be allocated to a list becuase the specified stock type does not exist. (did you make a typo?)";
    }
}

QVector<Stock *> StockList::getList(const char *type)
{
    if (std::strncmp(type, "Confectionery", 50) == 0)
        return _confectioneryList;
    else if (std::strncmp(type, "ReadingMaterial", 50) == 0)
        return _readingMaterialList;
    else {
        qDebug() << "Error: Could not return the required list becuase the specified stock type does not exist. (did you make a typo?)";
    }
}

void StockList::appendStockList(QVector<Stock *> &list)
{
    for (int i = 0; i < list.count(); i++)
    {
        this->addStock(list[i]);
    }
}



