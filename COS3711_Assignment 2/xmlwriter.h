#ifndef XMLWRITER_H
#define XMLWRITER_H
//XmlWriter.h
//Provides functionality to write stock list to xml file

#include <QObject>
#include <QFile>
#include <QXmlStreamWriter>
#include <QString>
#include "stock.h"
#include "confectionery.h"
#include "readingmaterial.h"
#include "stocklist.h"

class XmlWriter : public QObject
{
    Q_OBJECT
public:
    explicit XmlWriter(QObject *parent = nullptr);
    XmlWriter(QObject *parent = nullptr, StockList *stockList = nullptr, QString fileName = "");

signals:

public slots:

public:

    void setFileName(QString fileName);
    void writeToFile();

private:
    StockList *_stockList;
    QString _fileName;
    QFile _file;
    QXmlStreamWriter _writer;
};

#endif // XMLWRITER_H
