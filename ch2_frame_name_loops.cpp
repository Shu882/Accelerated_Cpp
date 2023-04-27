//
// Created by Ethan Shu on 4/25/23.
// accelerated C++, chapter 2
//

#include <iostream>
#include <string>

int main(){
    // ask the user to type in the name
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;

    // formulate the message
    std::string message;
    message = "Hello, " + name + "!";

    // formulate and output each line
    int blank=2;
    const int nrows = 3+blank*2;
    const int ncols = message.size() + 2;
    const std::string one(ncols, '*');
    const std::string spaces(message.size(), ' ');
    const std::string blank_frame = '*' + spaces + '*';
    for (int i = 1; i <= nrows; ++i) {
        // there's a lot of nuances (allowed data types, type conversion). At the point, better just use the logical operators
        if (i == 1 | i == nrows) // this is bitwise operator, better use logical OR operator
            std::cout << one << std::endl;
        else if (i == (nrows + 1) / 2)
            std::cout << '*' << message << '*' << std::endl;
        else
            std::cout << blank_frame << std::endl;
    }
    return 0;
}
