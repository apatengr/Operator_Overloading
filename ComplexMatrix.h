//  Complex.h
//  Lab4
//
//  Created by Animesh Patel on 10/23/17.
//  Copyright © 2017 Animesh Patel. All rights reserved.




#ifndef ComplexMatrix_h
#define ComplexMatrix_h
#include <string>
#include "Complex.h"
#include <iostream>
#include <cmath>

class ComplexMatrix{
    
public:
    
    ComplexMatrix(int = 0);  // constructor, with single argument to 0
    
    ComplexMatrix(const ComplexMatrix &); //copy constructor
    
    ~ComplexMatrix(); // destructor
    
    ComplexMatrix& operator = (const ComplexMatrix&); // Assignment operator
    
    friend ostream &operator << (ostream &, const ComplexMatrix &);
    
    void fillMatrix(); // to take user input
    
    ComplexMatrix operator + (ComplexMatrix &); // Matrix Addition
    
    ComplexMatrix operator * (ComplexMatrix &); // Matrix Multiplication
   
    Complex& operator()(int, int); // return reference 


    
private:
    int dimension;
    size_t size;
    Complex *ptr;
};

#endif
