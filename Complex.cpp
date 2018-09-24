//  Complex.h
//  Lab4
//  Created by Animesh Patel on 10/23/17.
//  Copyright © 2017 Animesh Patel. All rights reserved.
//#include "Complex.h"
//#include <cmath>
#include <iostream>
//#include <iomanip>
using namespace std;


// constructor
Complex::Complex(double a, double b)
:real(a), imag(b)
{
    
}


// istream
istream &operator >> (istream &input, Complex &number)
{
    input >> number.real;
    input.ignore(1);
    input >> number.str;
    input.ignore(2);
    input >> number.imag;
    if (number.str =="-"){
        number.imag = (-1)*number.imag;
    }
    return input;
}


// ostream
ostream &operator << (ostream &output, const Complex &number)
{
    
    if (number.imag < 0)
        output << number.real << " - i" << (-1)*(number.imag);
    
    else
        output << number.real << " + i" << number.imag;

    return output;
}

// predecrement
Complex &Complex::operator-- ()
{
    --real;
    return *this;
}

// postdecrement
Complex Complex::operator-- (int)
{
    Complex temp = *this;
    --real;
    return temp;
}



// double real part gets added to complex real part and returns the complex value
// double precision before the plus sign
Complex operator + (double &obj1, const Complex &obj2)
{
    return Complex(obj2.real + obj1 , obj2.imag);
}


// double real part gets added to complex real part and returns the complex value
// double precision after the plus sign
Complex Complex::operator + (double &obj2){
    return Complex(real + obj2 , this->imag);
}


// Complex value 1 + Complex value 2
// returns the final complex number

Complex Complex::operator + (const Complex &obj1)
{
    double ansReal = real + obj1.real;
    double ansImag = imag + obj1.imag;
    return Complex(ansReal, ansImag);
}



// Multiplication of two complex number and returns a complex value
Complex Complex::operator * (const Complex &obj1)
{
    double ansReal = (real * obj1.real) - (imag * obj1.imag);
    double ansImag = (real * obj1.imag) + (imag * obj1.real);
    return Complex(ansReal, ansImag);
}

// absolute value, perform the magnitude operation
double abs(Complex &obj1)
{
    return pow(((obj1.real * obj1.real) + (obj1.imag * obj1.imag)),.5);
}


/*
class A{
public:
    A();// default constructor
    A(int); // int constructor
    A(const  A&); // copy constructor
    ~A(); // destructor
    A operator+ (const A& rhs) const; // Addition operator
    int x;
};

A::A(): x(0){
    cout << "A Int Con  " << endl;
};

A:: A(int x): x(x){
    cout << "A Int con " << endl;
};

A:: ~A() {
    cout << "-A Destructor " << endl;
    
};

A::A(const A &a){
    x = a.x;
    cout << "A copy con " << endl;
}
 */
/*
int main(){
    int a[8] = {1,2,3,4,5,6,7,8};
    int *aptr;
    aptr = &a[0];
    cout << "aptr is " << aptr << endl;
}
*/
/*
template <typename T>
T maximum (T value1, T value2, T value3){
    
    T maximumValue = value1;
    
    if (value2 > maximumValue)
        maximumValue = value2;
    if (value3 > maximumValue)
        maximumValue = value3;
    return maximumValue;
}
*/




/*

class Base {
public:
    virtual void Func1() =0;
    void Func2(); };
class Sub1 : public Base {
public:
    virtual void Func2();
    void Func3(); };
class Sub2 : public Sub1 {
public:
    virtual void Func1(); void Func2();
    void Func3();
};



class Sub3 : public Sub1 {
public:
virtual void Func1();
};
//----------- Implementation
// Base
void Base::Func2()
{ cout << "Hello from Base::Func2()" << endl; }



// Sub1
void Sub1::Func2()
{cout << "Hello from Sub1::Func2()" << endl; } void Sub1::Func3()
{ cout << "Hello from Sub1::Func3()" << endl; }
// Sub2
void Sub2::Func1()
{ cout << "Hello from Sub2::Func1()" << endl; } void Sub2::Func2()
{ cout << "Hello from Sub2::Func2()" << endl; } void Sub2::Func3()
{ cout << "Hello from Sub2::Func3()" << endl; }
// Sub3
void Sub3::Func1()
{ cout << "Hello from Sub3::Func1()" << endl; }
//----------- Global Functions





void globalFunction(Sub1 & b) {
    b.Func1(); b.Func2(); b.Func3();
}



int main() {
    Sub2 s2; Sub3 s3;
    globalFunction(s3); globalFunction(s2);
}





*/

































































