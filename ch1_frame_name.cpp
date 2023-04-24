//
// Created by Ethan Shu on 4/23/23.
// accelerated C++, section 1.2
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

    // formulate each line
    std::string two, three;
    three = '*' + message + '*';
    std::string spaces(message.size(), ' ');
    two = '*' + spaces + '*';
    std::string one(three.size(), '*');

    // output
    std::cout << one << std::endl << two << std::endl << three << std::endl << two << std::endl << one << std::endl;

    return 0;
}