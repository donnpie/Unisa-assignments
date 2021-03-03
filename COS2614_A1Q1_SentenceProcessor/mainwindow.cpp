#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include "sentenceprocessor.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString string = QInputDialog::getMultiLineText(this, "Input", "Input sentence", "one for all and all for one"); //"Add text here"
    SentenceProcessor sentence(string);
    if (sentence.getWordNumber(string)>=2)
    {
        QMessageBox::information(this, "Output", "Word count: " + QString::number(sentence.getWordNumber(string)) + "\n"
                                 + "Vowel count: " + QString::number(sentence.getVowelNumber(string)) + "\n"
                                 + "Sentence is reversible: " + sentence.isReversibleTrueOrFalse() + "\n"
                                 + "Reversed sentence: " + sentence.wordsReversed(string) + "\n"
                                 + "Formatted sentence: " + sentence.formatSentence(string));
    }
    else
    {
        QMessageBox::warning(this, "Error", "Please enter a sentence with at least two words.");
    }
}
