#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>
#include "Rational.h"
#include "BigInt.h"
#include "Complex.h"

using namespace std;
using namespace BigInt_Wei;
using namespace Rational_LIN;

namespace Complex_JAY{
    Complex::Complex (Rational realValue, Rational iValue)
    :real(realValue), i(iValue)
    {

    }

    Complex::Complex (Rational realValue)
    :real(realValue)
    {
        BigInt zero("0"), one("1");
        Rational init(zero, one);
        i = init;
    }

    Complex::Complex ()
    {
        BigInt zero("0"), one("1");
        Rational init(zero, one);
        real = init;
        i = init;
    }

    // istream& operator >> (istream& inputStream, Complex& num){
    //     string s1,s2;

    //     inputStream >> s1 >> s2;

    //     Rational a(s1), b(s2);

    //     num = Complex(a, b);

    //     return inputStream;
    // }

    ostream& operator << (ostream& outputStream, const Complex& num){ // problem

        BigInt zero("0"), one("1");
        Rational init(zero, one);

        if (num.real == init && num.i == init)
            outputStream << "0";
        else if (num.real == init)
            outputStream << "(0)+("<< num.i << ")" << "i";
        else if (num.i == init)
            outputStream << "("<< num.real << ")+(0)i";
        else
            outputStream << "(" << num.real << ")" << '+' << "(" << num.i << ")" << "i";

        return outputStream;
    }

    const Complex operator + (const Complex& c1, const Complex& c2){
        return Complex(c1.real + c2.real, c1.i + c2.i);
    }

    const Complex operator - (const Complex& r1, const Complex& r2){
        return Complex(r1.real - r2.real, r1.i - r2.i);
    }

    const Complex operator - (const Complex& r){
        return Complex(-r.real, -r.i);
    }

    const Complex operator * (const Complex& r1, const Complex& r2){
        return Complex(r1.real * r2.real - r1.i * r2.i, r1.real * r2.i + r1.i * r2.real);
    }

    const Complex operator / (const Complex& r1, const Complex& r2){
        BigInt bZero("0");
        BigInt bOne("1");
        Rational rZero(bZero, bOne);
        if (r2.real == rZero && r2.i == rZero){
            cout << "Error!! Divided by 0. 0 is used as answer";
            return Complex(rZero, rZero);
        }
        return Complex((r1.real * r2.real + r1.i * r2.i) / (r2.i * r2.i + r2.real * r2. real), (r1.i * r2.real - r1.real * r2.i) / (r2.i * r2.i + r2.real * r2. real));
    }
}
