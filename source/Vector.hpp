/*******************************************************************************
------------------------------------------------------------------------
Program  :  Vector.hpp
Purpose  :  Declaration of the class Vector
Author   :  Marimuthu, Prasanna
Date     :  01.12.2019
*******************************************************************************/
#pragma once

//includes
#include <memory>

#include "Arithmetic.hpp"
#include "declMatrixVector.hpp"

template <typename T>
class Vector : Arithmetic<T> {
    private:

        //data members of Class Vector.
        int size;

    public:

        /// <summary> Default constructor disabled as vector should be initialized with size. </summary>
        Vector<T>() = delete;

        /// <summary> Constructor of class Vector. </summary>
        /// <param name="elements"> Initializes the size of vector.  </param>
        Vector(const int& elements);

        /// <summary> Copy Constructor (Deep Copy) of class Vector. </summary>
        /// <param name="sourceVector"> Content of source vector copied to new vector  </param>
        Vector<T>(const Vector<T>& sourceVector);

        /// <summary>Assignment operator overloaded.</summary>
        /// <param name="sourceMatrix"> Source vector copied through assignment operator.  </param>
        /// <returns> Returns vector  </returns>
        Vector<T>& operator=(const Vector& sourceVector) {
            ASSERT_DIMENSION((size == sourceVector.size), "Copy not possible. Hint : Try resizing vector before copying.")

            std::unique_ptr<T[]> newValues = std::make_unique<T[]>(size);
            for(auto i = 0; i < size; i++) {
                newValues[i] = sourceVector.value[i];
            }
            value = move(newValues);

            return *this;
        }

        /// <summary> Operator overloading of scalar multiplication </summary>
        /// <param name="vector"> Vector to be multiplied.  </param>
        /// <param name="scalarValue"> Scalar value to be multiplied with.  </param>
        /// <returns> Returns Vector </returns>
        friend Vector<T> operator*(const Vector<T>& vector, const double& scalarValue) {
            Vector<T> resultVector(vector.size);
            for(auto i = 0; i < vector.size; i++) {
                resultVector.value[i] = T(scalarValue * vector.value[i]);
            }
            return resultVector;
        }

        /// <summary> Operator overloading of scalar multiplication </summary>
        /// <param name="vector"> Vector to be multiplied.  </param>
        /// <param name="scalarValue"> Scalar value to be multiplied with.  </param>
        /// <returns> Returns Vector </returns>
        friend Vector<T> operator*(const double& scalarValue, const Vector<T>& vector) {
            return vector * scalarValue;
        }

        /// <summary> Operator overloading of vector addition. </summary>
        /// <param name="vectorA"> Vector LHS operand.  </param>
        /// <param name="vectorB"> Vector RHS operand.  </param>
        /// <returns> Returns Vector </returns>
        friend Vector<T> operator+(const Vector<T>& vectorA, const Vector<T>& vectorB) {
            ASSERT_DIMENSION((vectorA.size == vectorB.size), "Dimensions are not equal.")

            Vector<T> resultVector(vectorA.size);
            for(auto i = 0; i < vectorA.size; i++) {
                resultVector.value[i] = vectorA.value[i] + vectorB.value[i];
            }
            return resultVector;
        }

        /// <summary> Operator overloading of vector multiplication. </summary>
        /// <param name="vectorA"> Vector LHS operand.  </param>
        /// <param name="vectorB"> Vector RHS operand.  </param>
        /// <returns> Returns Vector </returns>
        friend Vector<T> operator*(const Vector<T>& vectorA, const Vector<T>& vectorB) {
            ASSERT_DIMENSION((vectorA.size == vectorB.size), "Dimensions are not equal.")

            Vector<T> resultVector(vectorA.size);
            for(auto i = 0; i < vectorA.size; i++) {
                resultVector.value[i] = vectorA.value[i] * vectorB.value[i];
            }
            return resultVector;
        }


        /// <summary> Operator overloading of is equal operator. </summary>
        /// <param name="vectorA"> Vector LHS operand.  </param>
        /// <param name="vectorB"> Vector RHS operand.  </param>
        /// <returns> Returns true if both the vectors are equal </returns>
        friend bool operator==(const Vector<T>& vectorA, const Vector<T>& vectorB) {
            ASSERT_DIMENSION((vectorA.size == vectorB.size), "Dimensions are not equal.")

            bool isEqual = true;
            for(auto i = 0; i < vectorA.size; i++) {
                if(vectorA.at(i) != vectorB.at(i)) {
                    isEqual = false;
                    break;
                }
            }
            return isEqual;
        }

        /// <summary> Operator overloading of accessing elements. </summary>
        /// <param name="index"> value of index passed. </param
        /// <returns> Returns vector element </returns>
        T& operator()(const int& index) {
            ASSERT_INDEX(size > index, "Indexed value exceeds the vector size.");

            return value[index];
        }

        /// <summary> Accessing elements present in the index of vector. </summary>
        /// <param name="index"> value of index passed. </param
        /// <returns> Returns vector element </returns>
        T at(const int& index) const;

        /// <summary> Delete element present in the index of vector. </summary>
        /// <param name="index"> value of index passed. </param
        void deleteAt(const int& index);

        /// <summary> Resize vector to the new size. </summary>
        /// <param name="targetSize"> target size. </param
        void resize(const int& targetSize);

        /// <summary> Prints in vector format </summary>
        void print();

        /// <summary> Return size of the vector. </summary>
        int getSize() const;

        /// <summary> Default destructor </summary>
        ~Vector();

};

//Vector.hpp