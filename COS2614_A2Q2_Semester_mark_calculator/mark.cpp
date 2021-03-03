#include "mark.h"

Mark::Mark() :  exam(0), examWeight(0)
{
    for (int i = 0; i < ASSIGNMENT_COUNT; i++)
    {
        assignmentMarks[i] = 0;
        assignmentWeights[i] = 0;
    }
}

Mark::Mark(double a1, double a2, double a3, double e, double a1w, double a2w, double a3w, double ew)
{
    if (isInRange(a1, LOWER, UPPER)) assignmentMarks[0] = a1; else assignmentMarks[0] = 0;
    if (isInRange(a2, LOWER, UPPER)) assignmentMarks[1] = a2; else assignmentMarks[1] = 0;
    if (isInRange(a3, LOWER, UPPER)) assignmentMarks[2] = a3; else assignmentMarks[2] = 0;
    if (isInRange(a1w, LOWER, UPPER)) assignmentWeights[0] = a1w; else assignmentWeights[0] = 0;
    if (isInRange(a2w, LOWER, UPPER)) assignmentWeights[1] = a2w; else assignmentWeights[1] = 0;
    if (isInRange(a3w, LOWER, UPPER)) assignmentWeights[2] = a3w; else assignmentWeights[2] = 0;
    if (isInRange(e, LOWER, UPPER)) exam = e; else exam = 0;
    if (isInRange(ew, LOWER, UPPER)) examWeight = ew; else examWeight = 0;
}

Mark::~Mark()
{

}

double Mark::sumOfAssignmentWeights()
{
    double sum = 0;
    for (int i = 0; i < ASSIGNMENT_COUNT; i++)
    {
        sum += assignmentWeights[i];
    }
    return sum;
}

bool Mark::sumOfAssignmentWeightsIsOK()
{
    return (sumOfAssignmentWeights() == UPPER); //Need better code here!
}

double Mark::semesterMark()
{
    if (sumOfAssignmentWeightsIsOK())
    {
        double sum = 0;
        for (int i = 0; i < ASSIGNMENT_COUNT; i++)
        {
            sum += assignmentMarks[i]*assignmentWeights[i]/100;
        }
        return sum;
    }
    else {
        qDebug() << "Sum of assignment weights is not equal to 100. Returning 0.";
        return 0;
    }

}

double Mark::finalMark()
{
    double sum = 0;
    sum += exam*examWeight/100;
    sum += semesterMark()*semesterWeight()/100;

    return sum;
}

double Mark::semesterWeight()
{
    qDebug() << "semesterWeight: " << 100 - examWeight;
    return 100 - examWeight;
}

void Mark::setAssignmentMark(double m, int i)
{
    if (isInRange(m, LOWER, UPPER)) assignmentMarks[i] = m; else assignmentMarks[i] = 0;
    qDebug() << "setAssignmentMark[i]: " << assignmentMarks[i] << " m: " << m << " i: " << i;
}

void Mark::setExamMark(double m)
{
    if (isInRange(m, LOWER, UPPER)) exam = m; else exam = 0;
    qDebug() << "setExamMark: " << exam << " m: " << m;
}

void Mark::setAssignmentWeight(double w, int i)
{
    if (isInRange(w, LOWER, UPPER)) assignmentWeights[i] = w; else assignmentWeights[i] = 0;
    qDebug() << "setAssignmentWeights[i]: " << assignmentWeights[i] << " w: " << w << " i: " << i;
}

void Mark::setExamWeight(double w)
{
    if (isInRange(w, LOWER, UPPER)) examWeight = w; else examWeight = 0;
    qDebug() << "setExamWeight: " << examWeight << " w: " << w;
}

void Mark::print()
{
    for (int i = 0; i < ASSIGNMENT_COUNT; i++)
    {
        qDebug() << "Assignment " << i+1 << " mark: " << assignmentMarks[i];
        qDebug() << "Assignment " << i+1 << " weight: " << assignmentWeights[i];
    }
    qDebug() << "Exam mark: " << exam;
    qDebug() << "Exam weight: " << examWeight;
    qDebug() << "Semester mark: " << semesterMark();
    qDebug() << "Semester weight: " << semesterWeight();
    qDebug() << "Final mark: " << finalMark();
}

bool Mark::isInRange(double val, double l, double u)
{
    bool isOK = ((val >= l) && (val <= u));
    if (isOK)
        qDebug() << "Value is in range";
    else {
        qDebug() << "Value is not in range";
    }
    return isOK;
}
