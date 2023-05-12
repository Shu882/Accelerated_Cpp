//
// Created by Ethan Shu on 5/12/23.
// accelerated ch4 example

// compute a student's overall grade from midterm, final and homework
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <istream>
#include <algorithm>

using std::endl; //manipulator
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::setprecision; // another manipulator
using std::domain_error;
using std::istream;
using std::streamsize;

double median(vector<double> vec){
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if(size==0) throw domain_error("median of an empry vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}

double grade(double midterm, double final, double homework){
    return 0.2*midterm + 0.4*final + 0.4*homework;
}

double grade(double midterm, double final, const vector<double> &hw){
    if(hw.size()==0) throw domain_error("student has no homework");
    return grade(midterm, final, median(hw));
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

int main(){
    // ask for and read the student's name
    cout << "Please enter your name";
    string name;
    cin >> name;
    cout << "hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for homework grades
    cout << "enter all your homework grades, "
            "followed by end-of-file: ";

    vector<double> homework;
    //read homework grades
    read_hw(cin,homework);

    //compute and generate the final grade, if possible
    try{
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
        << final_grade << setprecision(prec) << endl;
    }catch (domain_error){
        cout<<endl<<"You must enter your grades. "
                    "please try again" << endl;
        return 1;
    }
    return 0;
}