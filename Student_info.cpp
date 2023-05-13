//
// Created by Ethan Shu on 5/12/23.
//
// read homework grades from an input stream into a vector<double>
#include "Student_info.h"
using std::vector;
using std::istream;

istream& read_hw(istream& in, vector<double>& hw){
    if(in) {
        hw.clear(); // get rid of previous contents
        // read homework grades
        double x;
        while (in >> x) hw.push_back(x);
        //clear the stream so the input will work for the next student
        in.clear();
    }
    return in;
}

istream& read(istream &in, Student_info &s){
    in >> s.name >> s.midterm >> s.final;
    read_hw(in, s.homework);
    return in;
}

bool compare(const Student_info &s1, const Student_info &s2) {return s1.name < s2.name;}

