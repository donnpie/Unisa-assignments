#ifndef SENTENCEPROCESSOR_H
#define SENTENCEPROCESSOR_H

#include <QWidget>
#include <QString>
#include <QStringList>

class SentenceProcessor
{
public:
    explicit SentenceProcessor(const QString & inputString);
    int getWordNumber(const QString & sentence);
        //Takes sentence and returns the number of words in it.
        //Assues that words are seperated by spaces
    int getVowelNumber(const QString & sentence);
        //Returns the number of vowels in a sentence
    bool isReversible(const QString & sentence);
        //Returns true if sentence is the same with the words reversed
        //Eg "One for all and all for one"
        //Ignores case
    QString isReversibleTrueOrFalse();
        //Returns a QString "True" is sentence is reversible
        //else returns "False"
    QString wordsReversed(const QString & sentence);
        //Returns the sentence with words in reversed order
    QString formatSentence(const QString & sentence);
        //Returns the sentence with first letter of first word capitalised
        //and a full stop at the end
        //If there is already a full stop at the end, does not add another full stop

private:
    QStringList lst;
    QStringList makeList();
    QString s;

};

#endif // SENTENCEPROCESSOR_H
