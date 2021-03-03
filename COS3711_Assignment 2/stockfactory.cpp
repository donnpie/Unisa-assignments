#include "stockfactory.h"



StockFactory::StockFactory(QObject *parent) : QObject(parent)
{

}

Stock *StockFactory::createStock(QString type)
{
    if (type == "Confectionery")
        return new Confectionery;
    if (type == "ReadingMaterial")
        return  new ReadingMaterial;
    else {
        qDebug() << "Error: Stock object could not be created becuase the specified stock type does not exist. (did you make a typo?)";
        return nullptr;
    }

}

Stock *StockFactory::createStock(QString type, QString i, int q, int w)
{
    if (type == "Confectionery")
        return new Confectionery(i, q, w);
    else {
        qDebug() << "Error: Stock object could not be created becuase the specified stock type does not exist. (did you make a typo?)";
        return nullptr;
    }
}

Stock *StockFactory::createStock(QString type, QString i, int q, QString f)
{
    if (type == "ReadingMaterial")
        return new ReadingMaterial(i, q, f);
    else {
        qDebug() << "Error: Stock object could not be created becuase the specified stock type does not exist. (did you make a typo?)";
        return nullptr;
    }
}

Stock *StockFactory::createConfectionery(QString i, int q, int w)
{
    return new Confectionery(i, q, w);
}

Stock *StockFactory::createReadingMaterial(QString i, int q, QString f)
{
    return new ReadingMaterial(i, q, f);
}
