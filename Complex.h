//
//  Complex.h
//  Lab4
//
//  Created by Animesh Patel on 10/23/17.
//  Copyright © 2017 Animesh Patel. All rights reserved.
//

#ifndef _COMPLEX_H
#define _COMPLEX_H
#include <iostream>
#include <string>
using namespace std;

class Complex
{
private:
    
    double real;
    double imag;
    string str;
    
public:
    
    Complex(double = 0, double = 0);  // constructor takes two doubles
    friend istream &operator >> (istream &, Complex &);   // istream overloaded operator
    friend ostream &operator << (ostream &, const Complex &);  // ostream overloaded operator
   
    Complex &operator-- ();    // predecrement
    Complex  operator-- (int); // postdecrement
    
    friend Complex operator + (double &, const Complex &); // Double + Complex, real part gets added
    Complex operator + (double &); // Complex + Double
    Complex operator + (const Complex &); // Complex + Complex
    
    Complex operator * (const Complex &); // multiplication
    
    friend double abs(Complex &);   // absolute value
    
    };

#endif












