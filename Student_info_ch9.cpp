//
// Created by Ethan Shu on 5/16/23.
//

istream& Student_info::read(istream &in){
    in>>name>>midterm>>final;
    read_hw(in,homework);
    return in;
}


double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

// compare function: this is definition, should include declaration in header
bool compare(const Student_info &x, const Student_info &y) {
    return x.name() < y.name();
}

