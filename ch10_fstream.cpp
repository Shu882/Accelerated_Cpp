//
// Created by Ethan Shu on 5/17/23.
//
#include <fstream>

using std::ifstream;
using std::ofstream;



int main(){
    ifstream infile("in");
    ofstream outfile("out");

    string s;

    while (getline(infile, s)) outfile << s << endl;

    return 0;
}