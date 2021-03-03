#include "xmlwriter.h"

XmlWriter::XmlWriter(QObject *parent) : QObject(parent), _stockList(nullptr)
{
    setFileName("");

}

XmlWriter::XmlWriter(QObject *parent, StockList *stockList, QString fileName) : QObject(parent), _stockList(stockList)
{
    setFileName(fileName);
    _file.setFileName(_fileName);
}

void XmlWriter::setFileName(QString fileName)
{
    if (_fileName != fileName)
    {
        _fileName = fileName;
    }
    else {
        qDebug() << "New value is the same as the old value. Item not set. Old value: " << _fileName << "New value: " << fileName << "\n";
    }
}

void XmlWriter::writeToFile()
{
    _file.open(QIODevice::WriteOnly);
    _writer.setDevice(&_file);
    //_writer.setAutoFormatting(true); //This line adds tabs and newline chars which interfere with xmlhandler::character
    _writer.writeStartDocument();   //write the xml header

    //write the xml body
    _writer.writeStartElement("StockList");

    //Write confectionery items
    Confectionery *c;
    for (int i = 0; i < _stockList->getList("Confectionery").count(); i++)
    {
        c = dynamic_cast<Confectionery*>(_stockList->getList("Confectionery")[i]);
        _writer.writeStartElement("StockItem");
        _writer.writeAttribute("type", "Confectionery");
            _writer.writeTextElement("item", _stockList->getList("Confectionery")[i]->getItem());
            _writer.writeTextElement("quantity", QString::number(_stockList->getList("Confectionery")[i]->getQuantity()));
            _writer.writeTextElement("weight", QString::number(c->getWeight()));
        _writer.writeEndElement();
    }

    //Write confectionery items
    ReadingMaterial *rm;
    for (int i = 0; i < _stockList->getList("ReadingMaterial").count(); i++)
    {
        rm = dynamic_cast<ReadingMaterial*>(_stockList->getList("ReadingMaterial")[i]);
        _writer.writeStartElement("StockItem");
        _writer.writeAttribute("type", "ReadingMaterial");
            _writer.writeTextElement("item", _stockList->getList("ReadingMaterial")[i]->getItem());
            _writer.writeTextElement("quantity", QString::number(_stockList->getList("ReadingMaterial")[i]->getQuantity()));
            _writer.writeTextElement("frequency", rm->getFrequency());
        _writer.writeEndElement();
    }

    _writer.writeEndDocument();  //close xml body




    _file.close();
}
