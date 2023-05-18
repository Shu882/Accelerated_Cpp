//
// Created by Ethan Shu on 5/17/23.
//
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

string letter_grade(double);

int main(){
    double grade;
    while (cin >> grade) {
        string letter = letter_grade(grade);
        cout << letter << endl;
    }
    return 0;
}


string letter_grade(double grade){
    // range posts for numeric grades
    static const double numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};

    // names for the letter grades

    static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-",
                                          "C+", "C", "C-", "D", "F"};
    // compute the number of grades given the size of the array
    // and the size of the single element
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    cout << "Value of ngrades: " << ngrades << endl;

    // given a number grade, find and return the associated letter grade
    for(size_t i=0; i<ngrades; ++i){
        cout << "this is loop "<< i << endl;
        if(grade>=numbers[i]){
            cout << "If condition satisfied at loop " << i << endl;
            return letters[i];
        }
    }
    return "?\?\?";
}