/*******************************************************************************
------------------------------------------------------------------------
Program  :  Arithmetic.hpp
Purpose  :  Abstract class for matrix and vector
Author   :  Marimuthu, Prasanna
Date     :  01.12.2019
*******************************************************************************/
#pragma once

template <typename T>
class Arithmetic {

    protected:

        //Pointer to array elements.
        std::unique_ptr<T[]> value;

        //abstraction for functions.
        virtual void print() = 0;
        virtual int getSize() const = 0;
};

//Arithmetic.hpp