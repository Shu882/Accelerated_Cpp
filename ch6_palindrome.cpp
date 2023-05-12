//
// Created by Ethan Shu on 4/30/23.
//

bool is_palindrome(const string &s){
    return equal(s.cbegin(), s.cend(), s.crbegin());
}

