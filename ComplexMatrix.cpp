//
//  ComplexMatrix.cpp
//  Lab4
//
//  Created by Animesh Patel on 10/23/17.
//  Copyright © 2017 Animesh Patel. All rights reserved.
//


#include "ComplexMatrix.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;



// default constructor 
ComplexMatrix::ComplexMatrix(int matSize)

:dimension(matSize)
{
   // Dynamically allocates size
    ptr  = new Complex[dimension*dimension];
    for (int i = 0; i < dimension*dimension; i++){
        ptr[i] = Complex(0,0);
    }
}


// Copy Constructor
ComplexMatrix::ComplexMatrix(const ComplexMatrix &copyMatrix)
: dimension(copyMatrix.dimension)
{
    // allocate memory for pointer matrix
    ptr = new Complex[dimension*dimension];
    
    for (size_t i = 0; i < dimension; ++i){
        for (size_t j = 0; j < dimension; ++j){
            ptr[(dimension * i) + j] = copyMatrix.ptr[(dimension * i) + j];
        }
    }
}


// Destructor with print statement
ComplexMatrix::~ComplexMatrix()
{
    delete [] ptr;
    cout<<"The memory allocated for the matrix has been deleted.\n";
}



// assignment operator dynamically deallocates the memory
ComplexMatrix& ComplexMatrix:: operator = (const ComplexMatrix& rhs){
    if (&rhs!= this){
        if (dimension != rhs.dimension){
            delete [] ptr;
            dimension = rhs.dimension;
            ptr = new Complex[dimension*dimension];
            
            for (size_t i = 0; i < dimension; ++i){
                for (size_t j = 0; j < dimension; ++j){
                    ptr[(i * dimension) + j] = rhs.ptr[(i * dimension) + j];
                }
            }
            
        }
    }
    return *this;
}



// size function returning size of matrix 1-D allocated
//size_t ComplexMatrix::getSize() const
//{
  //  return size;
//}


// ostream operator
ostream &operator << (ostream &output, const ComplexMatrix &RHS)
{
    for (size_t i = 0; i < RHS.dimension; ++i){
        for (size_t j = 0; j < RHS.dimension; ++j){
            
            
            output << setw(12) << RHS.ptr[(RHS.dimension * i) + j];
            
        }
        output << endl;
    }
    return output;
}



// takes in user input
void ComplexMatrix::fillMatrix()
{
    cout << "Please enter the matrix elements in the order indicated." << endl;
    for (int i = 0; i < dimension; ++i){
        for (int j = 0; j < dimension; ++j){
            cout << "Element " << "(" << i << ", " << j << "): ";
            cin >> ptr[(dimension * i) + j];
        }
    }
}



// matrix addition
ComplexMatrix ComplexMatrix::operator + (ComplexMatrix &obj1)
{
    
    ComplexMatrix ADDI(dimension);
    for (int i = 0; i < dimension; ++i){
        for (int j = 0; j < dimension; ++j){
            ADDI.ptr[(i * dimension) + j] = ptr[(i * dimension) + j] + obj1.ptr[(i * dimension) + j];
        }
    }
    
    return ADDI;   //  returns matrix after addition
}


// matrix multiplication
ComplexMatrix ComplexMatrix::operator * (ComplexMatrix &obj2)
{
    
    ComplexMatrix MULT(dimension);
    for (int i = 0; i < dimension; ++i){
        for (int j = 0; j < dimension; ++j){
            for (int k = 0; k < dimension; ++k){
                
                MULT.ptr[i * dimension + j] = MULT.ptr[i * dimension + j] +
                (ptr[i * dimension + k] * obj2.ptr[k * dimension + j]);
            }
        }
    }
    return MULT;   // returns multiplied matrix
}



// returning reference
Complex& ComplexMatrix::operator()(int row,int col){
    return ptr[(row * dimension) + col];
}

