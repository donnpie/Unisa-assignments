#include "reference.h"

const int DEFAULT_YEAR = 2020;
const int DEFAULT_VOLUME = 1;
const int DEFAULT_ISSUE = 1;

Reference::Reference(QObject *parent)
{
    this->setParent(parent);
    setAuthor("");
    setYear(DEFAULT_YEAR);
    setTitle("");
    setJournal("");
    setVolume(DEFAULT_VOLUME);
    setIssue(DEFAULT_ISSUE);
    setPages("");

}

Reference::Reference(QObject *parent, QString author, int year, QString title, QString journal, int volume, int issue, QString pages)
{
    this->setParent(parent);
    setAuthor(author);
    setYear(year);
    setTitle(title);
    setJournal(journal);
    setVolume(volume);
    setIssue(issue);
    setPages(pages);
}

QString Reference::getAuthor()
{
    return _author;
}

int Reference::getYear()
{
    return _year;
}

QString Reference::getTitle()
{
    return _title;
}

QString Reference::getJournal()
{
    return _journal;
}

int Reference::getVolume()
{
    return _volume;
}

int Reference::getIssue()
{
    return _issue;
}

QString Reference::getPages()
{
    return _pages;
}

void Reference::setAuthor(QString author)
{
    if (_author != author)
    {
        _author = author;
    }
}

void Reference::setYear(int year)
{
    if (_year != year)
    {
        if (year > 0)
        {
            if (year <= this->getCurrentYear())
            {
                _year = year;
            }
            else {
                QMessageBox::warning(nullptr, "Error", "The Year must be less than or equal to the current year");
            }
        }
        else {
            QMessageBox::warning(nullptr, "Error", "The Year must be a positive integer");
        }
    }

}

void Reference::setTitle(QString title)
{
    if (_title != title)
    {
        _title = title;
    }

}

void Reference::setJournal(QString journal)
{
    if (_journal != journal)
    {
        _journal = journal;
    }
}

void Reference::setVolume(int volume)
{
    if (_volume != volume)
    {
        if (volume > 0)
        {
            _volume = volume;
        }
        else {
            QMessageBox::warning(nullptr, "Error", "The Volume must be a positive integer");
        }
    }
}

void Reference::setIssue(int issue)
{
    if (_issue != issue)
    {
        if (issue > 0)
        {
            _issue = issue;
        }
        else {
            QMessageBox::warning(nullptr, "Error", "The Issue must be a positive integer");
        }
    }
}

void Reference::setPages(QString pages)
{
    if (_pages != pages)
    {
        _pages = pages;
    }
}

int Reference::getCurrentYear()
{
    return QDate::currentDate().year();
}


QList<QStandardItem *> Reference::getStdList()
{
    QList<QStandardItem *> list;
    list << new QStandardItem(this->getAuthor());
    list << new QStandardItem(QString::number(this->getYear()));
    list << new QStandardItem(this->getTitle());
    list << new QStandardItem(this->getJournal());
    list << new QStandardItem(QString::number(this->getVolume()));
    list << new QStandardItem(QString::number(this->getIssue()));
    list << new QStandardItem(this->getPages());
    return list;
}
