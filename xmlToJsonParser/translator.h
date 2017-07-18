#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>



class Translator
{
private:
    QXmlStreamReader xmlReader;


public:
    enum fileTypes{
    JSON,
    XML
    };

    Translator(fileTypes FileType, const QString FilePath);
    void read();
    void getContent();
};

#endif // TRANSLATOR_H
