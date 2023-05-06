//
// Created by Ethan Shu on 5/6/23.
// accelerated C++ ch10 example
//

#include <iostream>
using std::cout;
using std::endl;

int main(){
    int x = 5;
    int *p = &x;
    cout << "x = " << *p << endl;

    //change x value and output again
    *p = 6;
    cout << "x = " << *p << " now!" << endl;

    return 0;
}

