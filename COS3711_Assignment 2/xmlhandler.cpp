#include "xmlhandler.h"


XmlHandler::XmlHandler()
{

}

bool XmlHandler::startElement(const QString &,
                              const QString &localName,
                              const QString &,
                              const QXmlAttributes &atts)
{
    //StockItem
    if (QString::compare(localName, "StockItem",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "start element is " << localName << "\n";

        if (QString::compare(atts.value(0), "Confectionery", Qt::CaseSensitive) == 0)
        {
            //qDebug() << "Attribute type is " << atts.value(0) << "\n";

            _currentType = "Confectionery";
            //qDebug() << "Current type is " << _currentType << "\n";
            //do something//
            //Confectionery *c = new Confectionery()

            return true;
        }

        else if (QString::compare(atts.value(0), "ReadingMaterial", Qt::CaseSensitive) == 0)
        {
            //qDebug() << "Attribute type is " << atts.value(0) << "\n";

            _currentType = "ReadingMaterial";
            //qDebug() << "Current type is " << _currentType << "\n";
            //do something//
            //Confectionery *c = new Confectionery()

            return true;
        }
    }

    //StockList
    else if (QString::compare(localName, "StockList",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "start element is " << localName << "\n";
        return true;
    }

    //item
    else if (QString::compare(localName, "item",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "start element is " << localName << "\n";

        _elementName = localName;
        //qDebug() << "Item is " << _elementName << "\n";
        //do something//
        //Confectionery *c = new Confectionery()

        return true;
    }

    //quantity
    else if (QString::compare(localName, "quantity",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "start element is " << localName << "\n";

        _elementName = localName;
        //qDebug() << "Item is " << _elementName << "\n";
        //do something//
        //Confectionery *c = new Confectionery()

        return true;
    }

    else if (QString::compare(localName, "weight",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "start element is " << localName << "\n";

        _elementName = localName;
        //qDebug() << "Item is " << _elementName << "\n";
        //do something//
        //Confectionery *c = new Confectionery()

        return true;
    }

    else if (QString::compare(localName, "frequency",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "start element is " << localName << "\n";

        _elementName = localName;
        //qDebug() << "Item is " << _elementName << "\n";
        //do something//
        //Confectionery *c = new Confectionery()

        return true;
    }
//    QString _currentType;
//    int _quantity;
//    int _weight;
    //    QString _frequency;
}

bool XmlHandler::characters(const QString &ch)
{
    if (QString::compare(_elementName, "item",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "item is " << ch << "\n";
        _item = ch;
        return true;
    }

    if (QString::compare(_elementName, "quantity",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "qunatity is " << ch << "\n";
        _quantity = ch.toInt();
        return true;
    }
    if (QString::compare(_currentType, "Confectionery",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "If block in XmlHandler::characters accessed successfully with current type: " << _currentType << "\n";
        //QString s = ""; //For some bizzare reason I cannot assign directly to ch
        //s.append(ch);
        //s = s.trimmed();//Does not work
        //qDebug() << "ch value is " << ch << "\n";

        if (QString::compare(_elementName, "weight",Qt::CaseSensitive) == 0)
        {
            //qDebug() << "weight is " << ch << "\n";
            _weight = ch.toInt();

            //At this point we know we are working with a Confectionery item and have read all the variables, so we can write them to an object
            Confectionery *c = new Confectionery(_item, _quantity, _weight);
            _s = c; //Pass the Confectionery object to a Stock pointer so it can be added to the stock list
            _list.push_back(_s);

            return true;
        }
    }
    else if (QString::compare(_currentType, "ReadingMaterial",Qt::CaseSensitive) == 0)
    {
        //qDebug() << "If block in XmlHandler::characters accessed successfully with current type: " << _currentType << "\n";
        //qDebug() << "ch value is " << ch << "\n";

        if (QString::compare(_elementName, "frequency",Qt::CaseSensitive) == 0)
        {
            //qDebug() << "frequency is " << ch << "\n";
            _frequency = ch;

            //At this point we know we are working with a ReadingMaterial item and have read all the variables, so we can write them to an object
            ReadingMaterial *rm = new ReadingMaterial(_item, _quantity, _frequency);
            _s = rm; //Pass the Confectionery object to a Stock pointer so it can be added to the stock list
            _list.push_back(_s);

            return true;
        }
    }
}

bool XmlHandler::endElement(const QString &, const QString &, const QString &)
{
    return true;
}

QVector<Stock *> XmlHandler::getStockList()
{
    return _list;
}
