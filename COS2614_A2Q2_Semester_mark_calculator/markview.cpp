#include "markview.h"
#include "ui_markview.h"

MarkView::MarkView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarkView)
{
    ui->setupUi(this);
    font = QFont(FONT_FAMILY, FONT_SIZE, FONT_WEIGHT, false);
    this->setFont(font);
    this->setWindowTitle("Module results");
    layout = new QGridLayout(this);

    //Create widgets
    labelMarksCol = new QLabel("Marks");
    labelWeightsCol = new QLabel("Weights");
    labelA1 = new QLabel("Assignment 1:");
    labelA2 = new QLabel("Assignment 2:");
    labelA3 = new QLabel("Assignment 3:");
    labelSumOfSemWeights = new QLabel("Sum of assignment weigths");
    labelSemMark = new QLabel("Semester weight and mark::");
    labelExam = new QLabel("Exam:");
    labelWarning = new QLabel("Warning: Assignment weights must sum to 100");
    labelFinalMark = new QLabel("Final mark:");
    btnCalcFinalMark = new QPushButton("Calculate final mark");
    btnClose = new QPushButton("Close");
    spinA1Mark = new QSpinBox();
    spinA1Weight = new QSpinBox();
    spinA2Mark = new QSpinBox();
    spinA2Weight = new QSpinBox();
    spinA3Mark = new QSpinBox();
    spinA3Weight = new QSpinBox();
    spinExamMark = new QSpinBox();
    spinExamWeight = new QSpinBox();
    txtSumOfSemWeights = new QLineEdit();
    txtSemMark = new QLineEdit();
    txtSemWeight = new QLineEdit();
    txtFinalMark = new QLineEdit();

    spinA1Mark->setMaximum(MAX_VAL);
    spinA2Mark->setMaximum(MAX_VAL);
    spinA3Mark->setMaximum(MAX_VAL);
    spinA1Weight->setMaximum(MAX_VAL);
    spinA2Weight->setMaximum(MAX_VAL);
    spinA3Weight->setMaximum(MAX_VAL);
    spinExamMark->setMaximum(MAX_VAL);
    spinExamWeight->setMaximum(MAX_VAL);

    layout->addWidget(labelWeightsCol, 0, 1);
    layout->addWidget(labelMarksCol, 0, 2);
    layout->addWidget(labelA1, 1, 0);
    layout->addWidget(labelA2, 2, 0);
    layout->addWidget(labelA3, 3, 0);
    layout->addWidget(labelSumOfSemWeights, 4, 0);
    layout->addWidget(labelSemMark, 5, 0);
    layout->addWidget(labelExam, 6, 0);
    layout->addWidget(labelWarning, 4, 3);
    layout->addWidget(labelFinalMark, 7, 0);
    layout->addWidget(spinA1Weight, 1, 1);
    layout->addWidget(spinA1Mark, 1, 2);
    layout->addWidget(spinA2Weight, 2, 1);
    layout->addWidget(spinA2Mark, 2, 2);
    layout->addWidget(spinA3Weight, 3, 1);
    layout->addWidget(spinA3Mark, 3, 2);
    layout->addWidget(txtSumOfSemWeights, 4, 1);
    layout->addWidget(txtSemWeight, 5, 1);
    layout->addWidget(txtSemMark, 5, 2);
    layout->addWidget(spinExamWeight, 6, 1);
    layout->addWidget(spinExamMark, 6, 2);
    layout->addWidget(txtFinalMark, 7, 2);
    layout->addWidget(btnCalcFinalMark, 7, 3);

    labelWarning->setVisible(false);

    //Connect signals and slots
    connect(spinA1Mark, SIGNAL(valueChanged(int)), this, SLOT(doCalcs()));
    connect(spinA2Mark, SIGNAL(valueChanged(int)), this, SLOT(doCalcs()));
    connect(spinA3Mark, SIGNAL(valueChanged(int)), this, SLOT(doCalcs()));
    connect(spinA1Weight, SIGNAL(valueChanged(int)), this, SLOT(doCalcs()));
    connect(spinA2Weight, SIGNAL(valueChanged(int)), this, SLOT(doCalcs()));
    connect(spinA3Weight, SIGNAL(valueChanged(int)), this, SLOT(doCalcs()));
    connect(spinExamMark, SIGNAL(valueChanged(int)), this, SLOT(doCalcs()));
    connect(spinExamWeight, SIGNAL(valueChanged(int)), this, SLOT(doCalc()));
    connect(btnCalcFinalMark, SIGNAL(clicked()), this, SLOT(showFinalMark()));
}

MarkView::~MarkView()
{
    qDebug() << "Calling MarkView destructor...";
    delete ui;
    delete labelMarksCol;
    delete labelWeightsCol;
    delete labelA1;
    delete labelA2;
    delete labelA3;
    delete labelSumOfSemWeights;
    delete labelSemMark;
    delete labelExam;
    delete labelWarning;
    delete labelFinalMark;
    delete btnCalcFinalMark;
    delete btnClose;
    delete spinA1Mark;
    delete spinA1Weight;
    delete spinA2Mark;
    delete spinA2Weight;
    delete spinA3Mark;
    delete spinA3Weight;
    delete spinExamMark;
    delete spinExamWeight;
    delete txtSumOfSemWeights;
    delete txtSemMark;
    delete txtSemWeight;
    delete txtFinalMark;
}

void MarkView::doCalcs()
{
    qDebug() << "Doing calcs...";
    mark.setAssignmentMark(static_cast<double>(spinA1Mark->value()), 0);
    mark.setAssignmentMark(static_cast<double>(spinA2Mark->value()), 1);
    mark.setAssignmentMark(static_cast<double>(spinA3Mark->value()), 2);
    mark.setAssignmentWeight(static_cast<double>(spinA1Weight->value()), 0);
    mark.setAssignmentWeight(static_cast<double>(spinA2Weight->value()), 1);
    mark.setAssignmentWeight(static_cast<double>(spinA3Weight->value()), 2);
    txtSumOfSemWeights->setText(QString::number(mark.sumOfAssignmentWeights()));
    if (!mark.sumOfAssignmentWeightsIsOK())
    {
        labelWarning->setStyleSheet("QLabel { color : red; }");
        labelWarning->setVisible(true);
    }
    else {
        labelWarning->setStyleSheet("QLabel { color : black; }");
        labelWarning->setVisible(false);
    }
    txtSemWeight->setText(QString::number(mark.semesterWeight()));
    txtSemMark->setText(QString::number(mark.semesterMark()));
    mark.setExamMark(static_cast<double>(spinExamMark->value()));
    mark.setExamWeight(static_cast<double>(spinExamWeight->value()));
    txtFinalMark->setText(QString::number(mark.finalMark()));
}

void MarkView::showFinalMark()
{
    QMessageBox::information(this, "Message", "Final mark: " + QString::number(mark.finalMark()));
}

