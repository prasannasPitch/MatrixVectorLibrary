/*******************************************************************************
------------------------------------------------------------------------
Program  :  testVectorMatrix.cpp
Purpose  :  main for the application
Author   :  Marimuthu, Prasanna
Date     :  01.12.2019
*******************************************************************************/

//includes
#include <iostream>

#include "Vector.hpp"
#include "Matrix.hpp"

//namespace
using namespace std;


int main() {

    cout << "********************Sample Usage******************** \n";
    cout << "\n********************Vector******************** \n";

    cout << " Create vector A (initialized with zero) \n";
    integerVector vectorA(10);
    vectorA.print();

    cout << "Create vector B (initialized with zero) \n";
    integerVector vectorB(10);
    cout << "Access vector B elements \n";
    for(int i = 0; i < vectorB.getSize(); i++) {
        vectorB(i) = i * 10;
    }
    vectorB.print();

    cout << "Copy vector B elements to new vector C (through auto keyword and assignment operator) \n";
    auto vectorC = vectorB;
    cout << "Vector C elements \n";
    vectorC.print();

    cout << "Check vector B and vector C are equal. \n";
    cout << "Result : " << boolalpha << (vectorB == vectorC) << endl;

    cout << "Get the first element in vector C \n";
    cout << "First position : " << vectorC.at(0) << endl;

    cout << "Delete first element in vector C \n";
    vectorC.deleteAt(0);
    cout << "Vector C after deleting has " << vectorC.getSize() << " elements." <<  endl;
    vectorC.print();

    //vectorA = vectorC - Exception raised for dimension mismatch
    cout << "Exception raised when vector A is copied to vector C. \n" ;
    vectorC.resize(vectorA.getSize());

    cout << "Vector C after resize to " << vectorC.getSize() << " elements." << endl;
    vectorC.print();

    cout << "Copy vector C to Vector A \n";
    vectorA = vectorC;
    cout << "Vector A \n";
    vectorA.print();

    cout << "Dot product of two vectors and asigned to new vector D \n";
    auto vectorD = vectorA * vectorB;
    vectorD.print();

    cout << "Resize vector to 5 \n";
    vectorD.resize(5);
    cout << "Vector D after resize to " << vectorD.getSize() << " elements." << endl;
    vectorD.print();

    cout << "Copy vector D to Vector E \n";
    auto vectorE = vectorD;

    cout << "Scalar multiplication by 0.5 \n";
    vectorD = vectorD * 0.5;
    vectorD.print();

    cout << "Check if 2 * vector D is equal to vector E \n";
    cout << "Result : " << boolalpha << (2 * vectorD == vectorE) << endl;
    vectorD.print();

    cout << "Check if 2 * vector A is equal to vector A + vector A \n";
    cout << "Result : " << boolalpha << (2 * vectorA == vectorA + vectorA) << endl;
    vectorA.print();

    cout << "\n********************Matrix******************** \n";

    cout << " Create Matrix A (initialized with zero) \n";
    integerMatrix matrixA(4, 4);
    matrixA.print();

    cout << "Create Matrix B (initialized with zero) \n";
    integerMatrix matrixB(4, 4);
    cout << "Access Matrix B elements \n";
    for(int i = 0; i < matrixB.getRow(); i++) {
        for(int j = 0; j < matrixB.getCol(); j++) {
            matrixB(i, j) = i * 10 + 2;
        }
    }
    matrixB.print();

    cout << "Copy matrix B elements to new matrix C (through auto keyword and assignment operator) \n";
    auto matrixC = matrixB;
    cout << "Matrix C elements \n";
    matrixC.print();

    cout << "Multiply two matrix and asigned to new matrix D \n";
    auto matrixD = matrixB * matrixC;
    matrixD.print();

    cout << "Create Matrix I as an identity matrix \n";
    integerMatrix matrixI(4, 4);
    matrixI.makeIdentity();
    matrixI.print();

    cout << "Proving A * I = I * A \n";
    cout << "Result : " << boolalpha << (matrixA * matrixI == matrixI * matrixA) << endl;

    cout << "Copy matrix D elements to new matrix E \n";
    auto matrixE = matrixD;
    matrixE.print();

    cout << "Scalar multiplication by 0.5 \n";
    matrixD = matrixD * 0.5;
    matrixD.print();

    cout << "Check if 2 * matrix D is equal to matrix E \n";
    cout << "Result : " << boolalpha << (2 * matrixD == matrixE) << endl;

    cout << "Resize matrix by retaining possible order and elements (4,4) => (3,3) \n";
    matrixD.resize(3, 3);
    matrixD.print();

    cout << "Resize matrix by retaining possible order and elements (3,3) => (4,3) \n";
    matrixD.resize(4, 3);
    matrixD.print();

    cout << "Resize matrix by retaining possible order and elements (4,3) => (1,3) \n";
    matrixD.resize(1, 3);
    matrixD.print();

    cout << "Resize matrix by retaining possible order and elements (1,3) => (1,10) \n";
    matrixD.resize(1, 10);
    matrixD.print();

    cout << "Multiplying vector (10 = 10*1) and matrix (1*10) to result a 10x10 matrix \n";
    auto resultMatrix = vectorB * matrixD ;
    resultMatrix.print();

    cout << "\n********************End******************** \n";

    getchar();
}


//testVectorMatrix.cpp