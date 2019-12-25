/*******************************************************************************
------------------------------------------------------------------------
Program  :  Matrix.hpp
Purpose  :  Declaration of the class Matrix
Author   :  Marimuthu, Prasanna
Date     :  01.12.2019
*******************************************************************************/
#pragma once

//includes
#include <memory>

#include "declMatrixVector.hpp"
#include "Vector.hpp"
#include "Arithmetic.hpp"

template <typename T>
class Matrix : Arithmetic<T> {
    private:

        //data members of Class Matrix.
        int row, col;

    public:

        /// <summary> Default constructor disabled as matrices should be initialized with rows and cols. </summary>
        Matrix<T>() = delete;

        /// <summary> Constructor of class Matrix. </summary>
        /// <param name="rows"> Initializes the row of matrix.  </param>
        /// <param name="cols"> Initializes the column of matrix.  </param>
        Matrix<T>(const int rows, const int cols);

        /// <summary> Copy Constructor of class Matrix. </summary>
        /// <param name="sourceMatrix"> Content of source matrix copied to new matrix  </param>
        Matrix<T>(const Matrix<T>& sourceMatrix);

        /// <summary>Assignment operator overloaded.</summary>
        /// <param name="sourceMatrix"> Source matrix copied through assignment operator.  </param>
        /// <returns> Returns Matrix  </returns>
        Matrix<T>& operator=(const Matrix& sourceMatrix) {
            ASSERT_DIMENSION((row == sourceMatrix.row) && (col == sourceMatrix.col), "Copy not possible. Hint : Try resizing matrix before copying.")

            std::unique_ptr<T[]> newValues = std::make_unique<T[]>(row * col);
            for(auto i = 0; i < row * col; i++) {
                newValues[i] = sourceMatrix.value[i];
            }
            value = move(newValues);

            return *this;
        }

        /// <summary> Operator overloading of is equal operator. </summary>
        /// <param name="vectorA"> Vector LHS operand.  </param>
        /// <param name="vectorB"> Vector RHS operand.  </param>
        /// <returns> Returns true if both the vectors are equal </returns>
        friend bool operator==(const Matrix<T>& matrixA, const Matrix<T>& matrixB) {
            ASSERT_DIMENSION((matrixA.row == matrixB.row) && (matrixA.col == matrixB.col), " Cannot check equality.")

            bool isEqual = true;
            for(auto i = 0; i < matrixA.row * matrixB.col; i++) {
                if(matrixA.value[i] != matrixB.value[i]) {
                    isEqual = false;
                    break;
                }
            }
            return isEqual;
        }

        /// <summary> Operator overloading of accessing elements. </summary>
        /// <param name="rows"> element present in row. </param>
        /// <param name="cols"> element present in column. </param>
        /// <returns> Returns matrix element </returns>
        T& operator()(const int& rows, const int& cols) {
            ASSERT_INDEX(row > rows && col >= cols, "Indexed value exceeds the matrix size.");

            return value[rows * col + cols];
        }

        /// <summary> Operator overloading of scalar multiplication </summary>
        /// <param name="matrix"> Matrix to be multiplied.  </param>
        /// <param name="scalarValue"> Scalar value to be multiplied with.  </param>
        /// <returns> Returns Matrix </returns>
        friend Matrix<T> operator*(const Matrix<T>& matrix, const double& scalarValue) {
            Matrix<T> resultMatrix(matrix.row, matrix.col);
            for(auto i = 0; i < matrix.row * matrix.col; i++) {
                resultMatrix.value[i] = T(scalarValue * matrix.value[i]);
            }
            return resultMatrix;
        }

        /// <summary> Operator overloading of scalar multiplication </summary>
        /// <param name="matrix"> Matrix to be multiplied.  </param>
        /// <param name="scalarValue"> Scalar value to be multiplied with.  </param>
        /// <returns> Returns Matrix </returns>
        friend Matrix<T> operator*(const double& scalarValue, const Matrix<T>& matrix) {
            return matrix * scalarValue;
        }

        /// <summary> Operator overloading of matrix addition. </summary>
        /// <param name="matrixA"> Matrix LHS operand.  </param>
        /// <param name="matrixB"> Matrix RHS operand.  </param>
        /// <returns> Returns Matrix </returns>
        friend Matrix<T> operator+(const Matrix<T>& matrixA, const Matrix<T>& matrixB) {
            ASSERT_DIMENSION((matrixA.row == matrixB.row) && (matrixA.col == matrixB.col), "Addition not possible. Hint : Check if rows of two matrices and columns of two matrices are equal.")

            Matrix<T> resultMatrix(matrixA.row, matrixB.col);
            for(auto i = 0; i < matrixA.row * matrixB.col; i++) {
                resultMatrix.value[i] = matrixA.value[i] + matrixB.value[i];
            }
            return resultMatrix;
        }

        /// <summary> Operator overloading of matrix multiplication. </summary>
        /// <param name="matrixA"> Matrix LHS operand.  </param>
        /// <param name="matrixB"> Matrix RHS operand.  </param>
        /// <returns> Returns Matrix </returns>
        friend Matrix<T> operator*(const Matrix<T>& matrixA, const Matrix<T>& matrixB) {
            ASSERT_DIMENSION(matrixA.col == matrixB.row, "Multiplication not possible. Hint : Check if column of first matrix is equal to row of second matrix.")

            Matrix<T> resultMatrix(matrixA.row, matrixB.col);
            for(auto i = 0; i < matrixA.row; i++) {
                for(auto j = 0; j < matrixB.col; j++) {
                    T sum = 0;
                    for(auto k = 0; k < matrixA.col; k++) {
                        sum = sum + matrixA.value[i * matrixA.col + k] * matrixB.value[k * matrixB.col + j];
                    }
                    resultMatrix.value[i * matrixB.col + j] = sum;
                }
            }
            return resultMatrix;
        }

        /// <summary> Prints in matrix format </summary>
        void print();

        /// <summary> Resize the given matrix. </summary>
        /// <param name="rows"> number of rows that the matrix should be set.  </param>
        /// <param name="cols"> number of columns that the matrix should be set.  </param>
        /// <returns> Returns Matrix </returns>
        void resize(const int& rows, const int& cols);

        /// <summary>Function for vector multiplication. </summary>
        /// <param name="matrix"> Matrix in LHS operand.  </param>
        /// <param name="vector"> Vector in RHS operand.  </param>
        /// <returns> Returns Matrix </returns>
        friend Matrix<T> operator*(const Matrix<T>& matrixA, const Vector<T>& vector) {
            ASSERT_DIMENSION(matrixA.getCol() == vector.getSize(), "Dimensions are not compatible for multiplication.")

            return matrixA * Vector2Matrix(vector);
        }

        /// <summary>Function for vector multiplication. </summary>
        /// <param name="vector"> Vector in LHS operand.  </param>
        /// <param name="matrix"> Matrix in RHS operand.  </param>
        /// <returns> Returns Matrix </returns>
        friend Matrix<T> operator*(const Vector<T>& vector, const Matrix<T>& matrixA) {
            ASSERT_DIMENSION(matrixA.getRow() == 1, "Dimensions are not compatible for multiplication.")

            return  Vector2Matrix(vector) * matrixA ;
        }

        /// <summary>Function for convert vector to matrix. </summary>
        /// <param name="vector"> Vector that is converted.  </param>
        /// <returns> Returns Matrix </returns>
        static Matrix<T> Vector2Matrix(const Vector<T>& vector);

        /// <summary>Function to get matrix rows. </summary>
        /// <returns> Returns number of rows in matrix. </summary>
        int getRow() const;

        /// <summary>Function to get matrix columns. </summary>
        /// <returns> Returns number of columns in matrix. </summary>
        int getCol() const;

        /// <summary>Function for get number of matrix elements. </summary>
        /// <returns> Returns size of matrix i.e number of elements </summary>
        int getSize() const;

        /// <summary> Make current matrix as Identity Matrix. </summary>
        void makeIdentity() ;

        /// <summary> Default destructor </summary>
        ~Matrix();
};

//Matrix.hpp