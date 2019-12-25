/*******************************************************************************
------------------------------------------------------------------------
Program  :  declMatrixVector.hpp
Purpose  :  Typdefs and Macros for Class Matrix and Class Vector
Author   :  Marimuthu, Prasanna
Date     :  01.12.2019
*******************************************************************************/

#pragma once

//Global
#define MaxSizeMatrix  100
#define MaxSizeVector  15

//Assertions for checking dimensions.
#define ASSERT_DIMENSION(__expression__ , __message__) { \
        if((__expression__) == false) { \
            std::cerr << "Dimensions are mismatching. " << \
                      __message__ << std::endl; \
            ::abort(); \
        } \
    }

//Assertion for checking maximum size limits.
#define ASSERT_MAXSIZE(__expression__ , __message__) { \
        if((__expression__) == false) { \
            std::cerr << "Matrix size exceeded maximum. "  << \
                      __message__ << std::endl; \
            ::abort(); \
        } \
    }

//Assertion for checking maximum size limits.
#define ASSERT_INDEX(__expression__ , __message__) { \
        if((__expression__) == false) { \
            std::cerr << "Index out of range. " << \
                      __message__ << std::endl; \
            ::abort(); \
        } \
    }

//Assertion for checking valid number or not.
#define ASSERT_VALIDNUMBER(__expression__ , __message__) { \
        if((__expression__) == false) { \
            std::cerr << "Integer numbers are expected. "  << \
                      __message__ << std::endl; \
            ::abort(); \
        } \
    }

//typedefs of Class Matrix
template<typename T>
class Matrix;
typedef Matrix<int> integerMatrix;
typedef Matrix<float> floatMatrix;
typedef Matrix<double> doubleMatrix;

//typedefs of Class Vector
template<typename T>
class Vector;
typedef Vector<int> integerVector;
typedef Vector<float> floatVector;
typedef Vector<double> doubleVector;