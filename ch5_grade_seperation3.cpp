//
// Created by Ethan Shu on 4/29/23.
// // accelerated C++, chapter 5
//

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}

// version 3: iterators but no indexing; still potentially slow
vector<Student_info> extract_fails(vector<Student_info>& students) {
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}

for (vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
    cout << iter->name << endl;
}
