//
// Created by Ethan Shu on 5/20/23.
//

template <class T>
class Handle{
public:
    Handle:p(0){} // default constructor
    Handle(const Handles& s):p(0) {if (s.p) p = s.p -> clone();} // copy constructor
    Handle& operator=(const Handle&); // assignment constructor
    ~Handle() {delete p;} // destructor


private:
    T* p;
};

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs){
    if (&rhs!=this){
        delete p;
        p = rhs.p ? rhs.p -> clone() :0;
    }
    return *this;
}

template<class T>
T* Handle<T>::operator->() const {
    if (p) return p;
    throw domain_error("unbounded Handle");
}

template<class T>
T& Handle<T>::operator*() const {
    if (p) return *p;
    throw domain_error("unbounded Handle");
}