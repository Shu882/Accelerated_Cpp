//
// Created by Ethan Shu on 5/1/23.
// accelerated ch7, example 1, word count
//

#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::string;
using std::map;
using std::endl;

int main(){
    string word; //store each input word
    map<string, int> word_counter; // store word-count pairs

    while(cin>>word)
        ++word_counter[word];

    for (map<string, int>::const_iterator it=word_counter.begin(); it!=word_counter.end(); ++it)
        cout<<"Word: " << it->first << "; Times: " << it->second << endl;
    return 0;
};