#include "sentenceprocessor.h"
#include <qregexp.h>
#include <QtDebug>

QStringList SentenceProcessor::makeList()
{
    return s.split(" ", QString::SkipEmptyParts, Qt::CaseInsensitive);
}

SentenceProcessor::SentenceProcessor(const QString & inputString) : s(inputString)
{
 lst = makeList();
 qDebug() << "SentenceProcessor object created successfully";
}

int SentenceProcessor::getWordNumber(const QString & sentence)
{
    return lst.length();
}


int SentenceProcessor::getVowelNumber(const QString & sentence)
{
    return sentence.count(QRegExp("(A|E|I|O|U|a|e|o|i|u)"));
    //return 5; //test code
}
bool SentenceProcessor::isReversible(const QString & sentence)
{
    int max = getWordNumber(s);
    //qDebug() << "max: " << max << '\n'; //debug code
    int mid = max / 2;
    //qDebug() << "mid: " << mid << '\n'; //debug code
    for (int i = 0; i < mid; i++)
    {
        //qDebug() << "i: " << i << '\n'; //debug code
        if (lst[i]!=lst[max-1-i])
        {
            //qDebug() << "lst[i]: " << lst[i] << "lst[max-1-i]: " << lst[max-1-i] << '\n'; //debug code
            return false;
        }
    }
    return true; //test code
}

QString SentenceProcessor::isReversibleTrueOrFalse()
{
    if(isReversible(s))
        return "True";
    else
        return "False";
}
QString SentenceProcessor::wordsReversed(const QString & sentence)
{
    QString newString = "";
    if (isReversible(s))
    {
        return s;
    }
    else
    {
        int max = getWordNumber(s);
        qDebug() << "max: " << max << '\n'; //debug code
        for (int i = 0; i < max; i++)
        {
            newString.append(lst[max-1-i]+ " ");
        }
    }
    //return QString("Sentence reversed");
    return newString;
}

QString SentenceProcessor::formatSentence(const QString & sentence)
{
    QString firstLetter;
    QString lastLetter;
    int stringLength = s.length();
    //qDebug() << "stringLength: " << stringLength << '\n'; //debug code
    QString theRest =s.right(stringLength-1);

    firstLetter = s[0];
    lastLetter = s[stringLength-1];
    if (lastLetter == " ") //check for space at the end
    {
        qDebug() << "Last letter is a space" << '\n'; //debug code
        theRest = theRest.left(theRest.length()-1);
    }
    if (lastLetter != ".") //check for full stop at the end
    {
        theRest = theRest.append(".");
    }
    return firstLetter.toUpper()+theRest;

    //return QString("Sentence formatted");
}

