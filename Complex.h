//Team No: 9
//Name: 林秉辭
//Student ID: 403410070
//Dept: 資工系
//Year: 大二
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>
#include "Rational.h"
#include "BigInt.h"
using namespace std;
using namespace Rational_LIN;
using namespace BigInt_Wei;

#ifndef COMPLEX_H
#define COMPLEX_H

namespace Complex_JAY{
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
}
#endif
