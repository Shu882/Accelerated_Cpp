//
// Created by Ethan Shu on 5/16/23.
//

struct Sales_data{
    // new members: operations on Sales_data objects
    std::string isbn() const {return bookNO;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    // data members are unchanged from 2.6.1 (p72)
    std::string bookNO;
    unsigned units_sold  = 0;
    double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print (std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);