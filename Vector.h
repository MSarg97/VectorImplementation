#ifndef VECTOR_H
#include <iostream>
#include <stdexcept>

// Vector class
template <class T>
class Vector
{
public:
    Vector() : vSize(0), vCapacity(1), vec(new T[vCapacity]) {} // Default constructor

    // Initializer constructor. If the initialization value is passed to constructor,
    //the vector is initialized with that value, otherwise the default constructor is called for it
    Vector(size_t, T = T());

    Vector(const Vector&); // Copy constructor
    Vector<T>& operator=(const Vector&); // Overloading assignment operator

    // Defining const and non-const iterators for vector
    typedef T* iterator;
    typedef const T* const const_iterator;

    // Overloading subscript operator and accessing the elements of the vector
    // without checking index bounds
    T& operator[](int index) { return vec[index]; } 
    T& at(int index); // Accessing elements of the vector with checking index bounds 

    // Overloading subscript operator and accessing the elements of the constant vector
    // without checking index bounds
    const T& operator[](int index) const { return vec[index]; }

    // Accessing elements of the constant vector with checking index bounds 
    const T& at(int index) const; 

    // Functions for getting the size and the capacity of the vector
    size_t size() const { return vSize; }
    size_t capacity() const { return vCapacity; }

    // Resizing vector with specified size. If the initialization value is passed to the function, 
    // new elements are initialized with that value, 
    // otherwise a default constructor is called for them
    void resize(size_t, T = T());

    void clear() const; //Removes all elements of the vector
    bool empty() const { return vSize == 0; } // Returns true, if the vector is empty, otherwise false
    void shrink_to_fit() { vCapacity = vSize; } // Reduces capacity to fit the size

    // Functions for pushing and popping elements at the end of the Vector
    void push_back(const T&);
    void pop_back();

    // Functions that return references to the first and last elements of the Vector
    T& front() const { if (!empty()) return vec[0];}
    T& back() const { if (!empty()) return vec[vSize - 1]; }

    // Functions that return non-const and const iterators 
    // to the first and last elements of the vector
    iterator begin() { return vec; }
    iterator end() { return vec + vSize; }

    const_iterator cbegin() const { return vec; }
    const_iterator cend() const { return vec + vSize; }

    ~Vector(); //Destructor

private:
    size_t vSize;
    size_t vCapacity;
    T* vec;
};

template <class T>
Vector<T>::Vector(size_t sz, T item)
{
    vSize = sz;

    vCapacity = std::pow(2, std::ceil(log2(sz)));
    vec = new T[vCapacity];

    std::fill(vec, vec + sz, item);
}

template <class T>
Vector<T>::Vector(const Vector& v)
{
    vSize = v.vSize;
    vCapacity = v.vCapacity;

    vec = new T[vCapacity];
    std::copy(v.cbegin(), v.cend(), vec);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if (this == &v)
        std::cout << "Self assignment error!\n";
    else
    {
        vSize = v.vSize;
        vCapacity = v.vCapacity;

        vec = new T[vCapacity];
        std::copy(v.cbegin(), v.cend(), vec);
    }

    return *this;
}

template <class T>
T& Vector<T>::at(int index)
{
    if (index < 0 || index >= vSize)
        throw std::out_of_range("Index is out of bound!\n");

    return vec[index];
}

template <class T>
const T& Vector<T>::at(int index) const
{
    if (index < 0 || index >= vSize)
        throw std::out_of_range("Index is out of bound!\n");    

    return vec[index];
}

template <class T>
void Vector<T>::push_back(const T& value)
{
    if (vSize == vCapacity)
    {
        vCapacity *= 2;

        T* temp = new T[vCapacity];
        std::copy(begin(), begin() + vSize, temp);
        delete[] vec;
        vec = temp;
    }

    vec[vSize++] = value;
}

template <class T>
void Vector<T>::pop_back()
{
    if (empty())
        std::cout << "Vector is empty!\n";
    else
    {
        vSize--;

        if (vSize == vCapacity)
            vCapacity /= 2;
    }
}

template <class T>
void Vector<T>::resize(size_t sz, T item)
{
    vCapacity = std::pow(2, std::ceil(log2(sz)));
    
    T* temp = new T[vCapacity];
    
    if (sz >= vSize)
        std::copy(begin(), begin() + vSize, temp);
    else
        std::copy(begin(), begin() + sz, temp);

    delete[] vec;
    vec = temp;

    if (sz >= vSize)
        std::fill(vec + vSize, vec + sz, item);

    vSize = sz;
}

template <class T>
void Vector<T>::clear() const 
{
    vSize = 0;
    vCapacity = 1;
}

template <class T>
Vector<T>::~Vector()
{
    delete[] vec;
}

#endif // !VECTOR_H