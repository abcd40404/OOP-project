#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>
#include "Rational.h"
#include "BigInt.h"
using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H


class Complex{
    public:
        Complex(Rational realValue, Rational iValue);
        Complex(Rational realValue);
        Complex();


        friend ostream& operator << (ostream& outputStream, const Complex& num);
        friend istream& operator >> (istream& inputStream, Complex& num);

        friend const Complex operator * (const Complex& c1, const Complex& c2);
        friend const Complex operator / (const Complex& c1, const Complex& c2);
        // friend bool operator == (const Complex& c1, const Complex& c2);

        friend const Complex operator + (const Complex& c1, const Complex& c2);
        friend const Complex operator - (const Complex& c1, const Complex& c2);
        friend const Complex operator - (const Complex& r);


    private:
        Rational real;
        Rational i;
};

#endif
