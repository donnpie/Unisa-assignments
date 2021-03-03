#ifndef MARKVIEW_H
#define MARKVIEW_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include "mark.h"
#include <QMessageBox>

namespace Ui {
class MarkView;
}

class MarkView : public QDialog
{
    Q_OBJECT

public:
    explicit MarkView(QWidget *parent = nullptr);
    ~MarkView();

public slots:
    void doCalcs();
    void showFinalMark();

private:
    static const int MAX_VAL = 100; //Max value allowed in spinboxes
    const int WINDOW_WIDTH = 1200;
    const int WINDOW_HEIGHT = 800;
    const int BUTTON_WIDTH = 200;
    const int BUTTON_HEIGHT = 50;
    const int FONT_SIZE = 9;
    const int FONT_WEIGHT = 1;
    const QString FONT_FAMILY = "MS Shell Dlg 2";
    QFont font;
    QGridLayout *layout;

    Ui::MarkView *ui;

    QLabel *labelA1;
    QLabel *labelA2;
    QLabel *labelA3;
    QLabel *labelSumOfSemWeights;
    QLabel *labelSemMark;
    QLabel *labelExam;
    QLabel *labelMarksCol;
    QLabel *labelWeightsCol;
    QLabel *labelWarning;
    QLabel *labelFinalMark;
    QPushButton *btnCalcFinalMark;
    QPushButton *btnClose;
    QSpinBox *spinA1Mark;
    QSpinBox *spinA1Weight;
    QSpinBox *spinA2Mark;
    QSpinBox *spinA2Weight;
    QSpinBox *spinA3Mark;
    QSpinBox *spinA3Weight;
    QSpinBox *spinExamMark;
    QSpinBox *spinExamWeight;
    QLineEdit *txtSumOfSemWeights;
    QLineEdit *txtSemMark;
    QLineEdit *txtSemWeight;
    QLineEdit *txtFinalMark;

    Mark mark;


};

#endif // MARKVIEW_H
