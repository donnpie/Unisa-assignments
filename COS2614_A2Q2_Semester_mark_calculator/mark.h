#ifndef MARK_H
#define MARK_H
//This class defines an object to hold and process
//the marks a student obtains during a semester module
//There are three semester tests and one exam
//Weights are provided for each test and the exam

#include <QDebug>

class Mark
{
protected:
    static const int ASSIGNMENT_COUNT = 3; //Number of assignments in a semester module
    constexpr static const double UPPER = 100; //Upper limit for range test
    constexpr static const double LOWER = 0; //Lower limit for range test
public:
    Mark();//Initialises all member variables to 0
    Mark(double a1, double a2, double a3, double e, double a1w, double a2w, double a3w, double ew); //Overloaded constructor
    Mark(const Mark &); //Copy constructor
    Mark& operator=(const Mark &); //Assignment operator
    ~Mark(); //Destructor

    //Methods
    double sumOfAssignmentWeights(); //Adds up the weights of the assignments
    bool sumOfAssignmentWeightsIsOK(); //Returns true if assignment weights sums to 100
    double semesterMark(); //Returns the weighted average mark of assignments
    double finalMark(); //Returns the weighted average of assignments and exam
    double semesterWeight(); //Returns the combined weight of the assignments
        //semesterWeight = 100 - w_exam

    //Setters
    void setAssignmentMark(double m = 0, int i = 0);
        //Sets the ith assignment mark to m
    void setExamMark(double m = 0);
    void setAssignmentWeight(double w = 0, int i = 0);
    void setExamWeight(double w = 0);
    void print();
private:
    //Implementation notes:
    //Weights and marks are stored as numbers ranging from 0 to 100

    //Member variables
    double assignmentMarks[ASSIGNMENT_COUNT]; //Assignment marks must be between 0 and 100
    double exam; //Exam mark must be between 0 and 100
    double assignmentWeights[ASSIGNMENT_COUNT]; //Weights for assignment marks must add up to 100
        //Each weight must be between 0 and 100
    double examWeight; //Weight for exam must be between 0 and 100

    //Helper functions
    bool isInRange(double val, double l, double u);
        //Returns true if l <= val <= u

};

#endif // MARK_H
