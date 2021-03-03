#ifndef STOCKFACTORY_H
#define STOCKFACTORY_H

#include <QObject>
#include "stock.h"
#include "confectionery.h"
#include "readingmaterial.h"



class StockFactory : public QObject
{
    Q_OBJECT
public:
    explicit StockFactory(QObject *parent = nullptr);

public:
    Stock *createStock(QString type);
    Stock *createStock(QString type, QString i, int q, int w);
    Stock *createStock(QString type, QString i, int q, QString f);
    Stock *createConfectionery(QString i, int q, int w);
    Stock *createReadingMaterial(QString i, int q, QString f);

signals:

public slots:
};

#endif // STOCKFACTORY_H
