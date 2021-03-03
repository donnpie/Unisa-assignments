#ifndef XMLREADER_H
#define XMLREADER_H
#include <QXmlSimpleReader> //NB: remember to include QT += xml in the pro file and run qmake!
#include <QXmlInputSource>
#include "xmlhandler.h"
#include <QFile>
#include <QDebug>
#include <cstdlib>

class XmlReader : public QXmlSimpleReader
{
public:
    XmlReader();
    XmlReader(QString filename, XmlHandler &handler);


private:
    QString _filename;
    XmlHandler *_handler;
    QFile _file;

};

#endif // XMLREADER_H
