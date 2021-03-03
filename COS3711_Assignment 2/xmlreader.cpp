#include "xmlreader.h"

XmlReader::XmlReader()
{

}

XmlReader::XmlReader(QString filename, XmlHandler &handler) : _filename(filename), _handler(&handler)
{
    _file.setFileName(filename);
//    if (!_file.open(QIODevice::ReadOnly))
//    {
//        qDebug() << "Error: File could not be opened\n";
//        std::exit(-1);
//    }
    this->setContentHandler(_handler);
    QXmlInputSource source(&_file);
    this->parse(&source);
}
