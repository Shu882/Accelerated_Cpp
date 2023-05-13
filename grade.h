#ifndef ACCELERATED_GRADE_H
#define ACCELERATED_GRADE_H

// function declaration
// type declaration

#include "Student_info.h"
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
#endif //ACCELERATED_GRADE_H
