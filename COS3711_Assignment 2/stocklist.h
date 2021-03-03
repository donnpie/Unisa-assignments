#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <QObject>
#include <QDebug>
#include "stock.h"
#include "confectionery.h"
#include "readingmaterial.h"



class StockList : public QObject
{
    Q_OBJECT

private:
    explicit StockList(QObject *parent = nullptr);

signals:

public slots:

public:
    static StockList *getInstance();
    void addStock(Stock *s);
    QVector<Stock *> getList(const char* type);
    void appendStockList(QVector<Stock *> &list);


private:
    static int _instanceCount;
    //QVector<Confectionery*> _confectioneryList;
    //QVector<ReadingMaterial*> _readingMaterialList;
    QVector<Stock*> _confectioneryList;
    QVector<Stock*> _readingMaterialList;
};



#endif // STOCKLIST_H
