//
// Created by Ethan Shu on 5/13/23.
//

class Str{
public:
    // define size_type of Str is the same as size_type defined in Vec, which is size_t
    typedef Vec<char>::size_type size_type;

    //default constructor; create an empty Str
    Str();

    // create a Str containing n copies of c
    Str(size_type n, char c):data(n,c){}

    //create a Str from a null-terminated array of char
    Str(const char* cp){
        std::copy(cp,cp+std::strlen(cp),std::back_inserter(data));
    }

    // create a Str from the range denoted by b and e
    template <class In>
            Str(In b, In e){
        std::copy(b, e, std::back_inserter(data));
    }

    char& operator[](size_type i) {return data[i];}
    const char& operator[](size_type i) const {return data[i];}

    size_type size(){ return data.size();}

    // operator +=
    Str &operator+=(const Str &s){
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }


private:
    Vec<char> data;

};

// output operator
ostream& operator<<(ostream& os, const Str& s){
    for(Str::size_type i=0; i != s.size(); ++i)
        os << s[i];
    return os;
}

// input operator
// use input operator to extract single string from input stream
friend istream &operator>> (istream &is, Str &s){
    // obliterate existing values
    s.data.clear();

    // read and discard any white space
    char c;
    // there is no order problem although c used in the 2nd expression is from the first expression
    // since &&, it's guaranteed the first expression will be executed first
    while (is.get(c) && isspace(c)); // do nothing if it's a space

    if(is){
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));

        //if we read a white space, put it back on the stream
        if (is)
            is.unget();
    }
    return is;
}

// operator +
Str operator+(const Str &s1, const Str &s2){
    Str s = s1;
    s+=s2;
    return s;
}

