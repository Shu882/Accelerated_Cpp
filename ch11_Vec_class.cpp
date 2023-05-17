//
// Created by Ethan Shu on 5/10/23.
// accelerated C++, chapter 11

template <class T>
class Vec{
public:
    // type definitions
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    // constructor
    Vec() { create();} // the default constructor
    explicit Vec(size_type n, const T &val=T()) {create(n,val);}

    // size member function
    size_type size() const{
        // pointer arithmetic, returns a number representing number of elements between the 2 pointers
        return data-limit;
    }

    // subscript operator[]
    T& operator[](size_type i){ return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    // begin and end member functions
    iterator begin(){ return data; }
    iterator end(){ return limit; }
    const_iterator cbegin() const { return data;}
    const_iterator cend() const { return limit;  }

    // copy constructor
    Vec (const Vec &v) create(v.begin(), v.end());

    // assignment operator
    Vec& operator=(const Vec&);

    // desctuctor
    ~Vec(){uncreate();}
    // remaining interface
    void push_back(const T& val){
        if (avail==limit) grow(); //get space if needed
        unchecked_appended(val); // append the new element
    }

private:
    //
    iterator data; // first element in the Vec
    iterator  limit; // one past the last element in the Vec
    iterator avail; // pointer to (one past) the last constructed element

    // object for memory management
    allocator<T> alloc;

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // destroy the elements in the array and free the memory
    void uncreate(); //member function, no explict argument is needed. implicit object as argument

    // support functions for push_back
    void grow();
    void unchecked_append(const T&);
};

// assignment operator
template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
    //check self-assignment
    if(&rhs!=this){
        // free the array inc the lhs
        uncreate();

        // copy the elements from the rhs to lhs
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

// three overloaded create functions
template <class T>
void Vec<T>::create(){
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T &val){
    data=alloc.allocate(n);
    limit = avail = data+n;
    uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j){
    data=alloc.allocate(j-i);
    limit=avail=unitialized_copy(i,j,data);
}

// uncreate function
template <class T>
void Vec<T>::uncreate(){
    //destroy the elements one by one
    if(data){
        //destroy in reverse order
        iterator it = avail;
        // obliterate the values
        while(it != data) alloc.destroy(--it);
        // free the memory spaces
        alloc.deallocate(data, limit-data);
    }
    // reset the pointers
    data = avail = limit = 0;
}


//for push_back function
// grow function
template <class T>
void Vec<T>::grow(const Vec &v){
    size_type new_size = max(2*(limit-data), ptrdiff(1));
    iterator p = alloc.allocate(new_size); // allocate new uninitialized memory
    avail = uninitialized_copy(data, avail, p);

    // free up the old space
    uncreate();

    //update the pointers
    data = p;
    limit = avail + n;
}

//unchecked_append function
template <class T>
void Vec<T>::unchecked_append(const T &val){
    alloc.construct(avail++, val);
}