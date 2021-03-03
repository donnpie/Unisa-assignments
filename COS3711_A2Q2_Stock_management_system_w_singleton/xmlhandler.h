#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <QXmlDefaultHandler>
#include <QDebug>
#include "stock.h"
#include "confectionery.h"
#include "readingmaterial.h"

class XmlHandler : public QXmlDefaultHandler
{
public:
    XmlHandler();
    //bool startDocument();
    bool startElement(const QString &namespaceURI,
                      const QString &localName,
                      const QString &qName,
                      const QXmlAttributes &atts);
    bool characters(const QString &ch);
    bool endElement(const QString &namespaceURI,
                    const QString &localName,
                    const QString &qName);
    QVector<Stock *> getStockList();
private:
    QString _currentType;
    QString _elementName;
    QString _item;
    int _quantity;
    int _weight;
    QString _frequency;
    Stock *_s;
    QVector<Stock*> _list;
};

#endif // XMLHANDLER_H
