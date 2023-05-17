//
// Created by Ethan Shu on 5/16/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <stdexcept>


using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::max; using std::sort;
using std::streamsize; using std::setprecision;
using std::domain_error;

class Student_info{
public:
    std::string name() const {return n;}
    bool valid() const {return !homework.empty();} // test for empty

    std::istream& read(std::istream&);
    double grade() const;

    // constructor
    Student_info();
    Student_info(std::istream&);

private:
    std::string n; // name
    double midterm, final; // midterm and final grades
    std::vector<double> homework; // a vector of homework grades
};

bool compare(const Student_info&, const Student_info&);

Student_info::Student_info():midterm(0), final(0){}
Student_info::Student_info(istream& is):{read(is);}



int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin)){
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), student.end(), compare);

    // write the names and grades
    for(vector<Student_info>::size_type i=0; i!=students.size(); ++i){
        cout << students[i].name()
        << string(maxlen+1-students.name.size(), ' ');
        try{
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecisioin(3) << final_grade
            << setprecision(prec) << endl;
        } catch (domain_error e){
            cout << e.what() << endl;
        }
    }
    return 0;
}