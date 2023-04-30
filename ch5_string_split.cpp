//
// Created by Ethan Shu on 4/29/23.
// accelerated C++, chapter 5
//
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector <string> split(const string &s) {
    vector <string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    // why not def s_size =s.size() so it doesn't repeat the computation over and over?
    while (i != s.size()){

        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;
        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j)is a space
        while (j != s.size() && !isspace(s[j]))
            j++;
        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and taking j - i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

int main() {
    string s; // read and split each line of input
    while (getline(cin, s)) {
    vector<string> v = split(s);
    // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); ++i)
            cout << v[i] << endl;
    }
    return 0;
}

