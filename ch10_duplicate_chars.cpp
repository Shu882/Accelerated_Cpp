//
// Created by Ethan Shu on 5/18/23.
//

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::copy;

char* duplicate_chars(const char* p){
    size_t length = strlen(p)+1;
    char* result = new char[length];
    copy(p, p+length, result);
    return result;
}

int main(){
    const char* s = "Can you duplicate this message?";
    char* result = duplicate_chars(s);
    cout << result << endl;
    return 0;
}


