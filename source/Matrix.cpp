/*******************************************************************************
------------------------------------------------------------------------
Program  :  Matrix.cpp
Purpose  :  Definition of the class Matrix
Author   :  Marimuthu, Prasanna
Date     :  01.12.2019
*******************************************************************************/

//includes
#include <iostream>
#include <iomanip>
#include <memory>

#include "Matrix.hpp"

//namespace
using namespace std;

template <typename T>
Matrix<T>::Matrix(int rows, int cols) {
    ASSERT_VALIDNUMBER(rows * cols > 0, "Invalid rows or columns passed.")
    ASSERT_MAXSIZE(MaxSizeMatrix >= rows * cols, "Failed to create matrix.")

    row = rows;
    col = cols;
    value  = std::make_unique<T[]>(rows * cols);
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& sourceMatrix) {
    row = sourceMatrix.row;
    col = sourceMatrix.col;
    *this = sourceMatrix;
}

template <typename T>
void Matrix<T>::print() {
    cout << "*********" << endl;
    for(auto i = 0; i < row; i++) {
        for(auto j = 0; j < col; j++) {
            cout << std::left << std::setw(5) << value[i * col + j] ;
        }
        cout << std::endl;
    }
    cout << "*********" << endl;
}

template <typename T>
void Matrix<T>::resize(const int& rows, const int&  cols) {
    ASSERT_VALIDNUMBER(rows * cols > 0, "Invalid rows or columns passed.")

    int oldSize = row * col;
    int newSize = rows * cols;

    if(oldSize != newSize) {
        std::unique_ptr<T[]> newValues = std::make_unique<T[]>(rows * cols);

        if(oldSize > newSize) {
            for(auto i = 0; i < rows; i++) {
                for(auto j = 0; j < cols; j++) {
                    newValues[i * cols + j] = value[i * col + j];
                }
            }
        }
        else if(oldSize < newSize) {
            for(auto i = 0; i < row; i++) {
                for(auto j = 0; j < col; j++) {
                    newValues[i * cols + j] = value[i * col + j];
                }
            }
        }

        value = move(newValues);
    }
    row = rows;
    col = cols;
}

template<typename T>
Matrix<T> Matrix<T>::Vector2Matrix(const Vector<T>& vector) {
    Matrix<T> matrix(vector.getSize(), 1);
    for(auto i = 0; i < vector.getSize(); i++) {
        matrix.value[i] = vector.at(i);
    }
    return matrix;
}

template<typename T>
int Matrix<T>::getRow() const {
    return row;
}

template<typename T>
int Matrix<T>::getCol() const {
    return col;
}

template<typename T>
int Matrix<T>::getSize() const {
    return row * col;
}

template<typename T>
void Matrix<T>::makeIdentity() {
    ASSERT_DIMENSION(row == col, "Dimensions are not compatible for creating identity matrix. Square matrix expected.")

    std::unique_ptr<T[]> newValues = std::make_unique<T[]>(row * col);
    for(auto i = 0; i < row; i++) {
        newValues[i * (row + 1)] = T(1);
    }
    value = move(newValues);
}

template <typename T>
Matrix<T>::~Matrix() {

}

//shows linker that this type is present. Disables matrix with other dataypes.
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;

//Matrix.cpp