//
// Created by Ethan Shu on 5/12/23.
// accelerated ch4 example
//
#include <iostream>
#include <istream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::streamsize;
using std::setprecision;
using std::istream;
using std::domain_error;
using std::max;
using std::sort;


struct Student_info{
    string name;
    double midterm, final;
    vector<double> homework;
}; // note the semicolon is needed

// median function: compute the median of a numerical vector
double median(vector<double> vec){
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if(size==0) throw domain_error("median of an empry vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}

// read homework grades from an input stream into a vector<double>
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

double grade(double midterm, double final, double homework){
    return 0.2*midterm + 0.4*final + 0.4*homework;
}

double grade(double midterm, double final, const vector<double> &hw){
    if(hw.size()==0) throw domain_error("student has no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info &s) {return grade(s.midterm, s.final, s.homework);}

bool compare(const Student_info &s1, const Student_info &s2) {return s1.name < s2.name;}

int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen=0;

    // read and store all the records, and find the length of the longest name
    while (read(cin,record)){
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the records
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i=0; i!=students.size(); ++i){
        //write the names, paddled on the right to maxlen+1 characters
        cout << students[i].name
        << string(maxlen+1-students[i].name.size(), ' ');

        // compute and write the grade
        try{
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e){
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}