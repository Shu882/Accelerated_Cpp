//
// Created by Ethan Shu on 5/13/23.
//

#include <iostream>

using std::cin; using std::cout; using std::endl;

int main(){
    int x, count = 0;
    while (cin >> x){
        ++count;
        cout << count << ' ' << x << endl;
    }
    return 0;
}