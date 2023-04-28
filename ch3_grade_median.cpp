//
// Created by Ethan Shu on 4/26/23.
// Accelerated C++, book example from section 3.1
//

#include <iostream>
#include <string>
#include <iomanip>
#include <ios> //input output base
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::setprecision;
using std::streamsize;
using std::sort;

int main(){
    string name;
    cout << "Please enter your name" << endl;
    cin >> name;

    double final;
    cout << "Please enter your final" << endl;
    cin >> final;

    double midterm;
    cout << "Please enter your midterm" << endl;
    cin >> midterm;

    vector<double> hw;
    double grade;
    while(cin>>grade) hw.push_back(grade);
    if (hw.empty()) return 1;
    sort(hw.begin(), hw.end());
    vector<double>::size_type n=hw.size();
    double median = (n%2==0) ? (hw[n/2]+hw[n/2-1])/2 : hw[(n-1)/2];

    double overall = 0.4*final + 0.2*midterm + 0.4*median;

    streamsize prec = cout.precision();
    cout << name << ", your overall grade is: " << setprecision(4) << overall << setprecision(prec) << endl;

    return 0;
}

