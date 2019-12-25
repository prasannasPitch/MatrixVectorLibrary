/*******************************************************************************
------------------------------------------------------------------------
Program  :  Vector.cpp
Purpose  :  Definition of the class Vector
Author   :  Marimuthu, Prasanna
Date     :  01.12.2019
*******************************************************************************/

//includes
#include <iostream>

#include "Vector.hpp"

//namespace
using namespace std;

template<typename T>
Vector<T>::Vector(const int& elements) {
    ASSERT_VALIDNUMBER(elements > 0, "Invalid size of vector.")
    ASSERT_MAXSIZE(MaxSizeVector >= elements, "Vector size reached maximum.")

    size = elements;
    value = std::make_unique<T[]>(size);
}

template<typename T>
Vector<T>::Vector(const Vector<T>& sourceVector) {
    size = sourceVector.size;
    *this = sourceVector;
}

template<typename T>
T Vector<T>::at(const int& index) const {
    ASSERT_INDEX(size > index, "Indexed value exceeds the vector size.");

    return value[index];
}

template<typename T>
void Vector<T>::deleteAt(const int& index) {
    ASSERT_INDEX(size > index, "Indexed value exceeds the vector size.");
    bool indexFound = false;

    std::unique_ptr<T[]> newValues = std::make_unique<T[]>(size - 1);
    for(auto i = 0; i < size; i++) {
        if(indexFound) {
            newValues[i - 1] = value[i];
        }
        else if(i != index) {
            newValues[i] = value[i];
        }
        else if(i == index) {
            indexFound = true;
        }
    }
    size = size - 1;
    value = move(newValues);
}

template<typename T>
void Vector<T>::resize(const int& targetSize) {
    std::unique_ptr<T[]> newValues = std::make_unique<T[]>(targetSize);

    for(auto i = 0; i < size && i < targetSize; i++) {
        newValues[i] = value[i];
    }
    size = targetSize;
    value = move(newValues);
}


template <typename T>
void Vector<T>::print() {
    cout << "*********" << endl;
    for(auto i = 0; i < size; i++) {
        cout << value[i] << endl;
    }
    cout << "*********" << endl;
}

template<typename T>
int Vector<T>::getSize() const {
    return size;
}

template<typename T>
Vector<T>::~Vector() {
}

//shows linker that this type is present. Disables vector with other dataypes.
template class Vector<int>;
template class Vector<float>;
template class Vector<double>;

//Vector.cpp