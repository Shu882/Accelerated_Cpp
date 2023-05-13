#ifndef ACCELERATED_STUDENT_INFO_H
#define ACCELERATED_STUDENT_INFO_H

#include <string>
#include <vector>
#include <iostream>

struct Student_info{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
}; // note the semicolon is needed

// read homework grades from an input stream into a vector<double>
std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read(std::istream&, Student_info&);
bool compare(const Student_info&, const Student_info&);

#endif //ACCELERATED_STUDENT_INFO_H
