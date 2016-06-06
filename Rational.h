//Team No: 9
//Name: 林秉辭
//Student ID: 403410070
//Dept: 資工系
//Year: 大二
#include <iostream>
#include <cstdlib>
#include "BigInt.h"

using namespace std;
using namespace BigInt_Wei;

#ifndef R_H
#define R_H
namespace Rational_LIN{

    class Rational{
        public:
            Rational();
            //Default constructor
            //Precondiction: None
            //Postcondiction: numerator and denominator will be set
            //0 and 1 respectively.
            Rational(BigInt newNumerator, BigInt newDenominator);
            //Constructor with custom numerator and denominator
            //Precondiction: newDenominator must not be 0, or the program will be terminate.
            //Postcondiction: numerator and denominator will be set by newNumerator and newDenominator.
            Rational(BigInt wholeNumber);
            //Single parameter constructor
            //Precondition: None
            //Postcondition: numerator will be set by wholeNumber and denominator will be 1.
            Rational(const Rational& object);

            const BigInt getNumerator() const;
            //Precondition: None
            //Postcondition: return object.numerator
            const BigInt getDenominator() const;
            //Precondition: None
            //Postcondition: return object.denominator
            friend ostream& operator <<(ostream& outputStream, const Rational& object);
            //operator '<<' overloading
            //Precondiction: friend function , two parameters
            //Postcondiction: output the object which format is a/b
            friend istream& operator >>(istream& inputStream, Rational& object);
            //operator '>>' overloading
            //Precondition: friend function , two parameters, and the input must be the format a/b
            //which a and b are BigInt
            //Postcondition: input the object
            friend const Rational operator *(const Rational& r1, const Rational& r2);
            //operator '*' overloading
            //Precondiction: friend function , two parameters
            //Postcondiction: return an object which is the result of (a/b) * (c/d)
            friend const Rational operator /(const Rational& r1, const Rational& r2);
            //operator '/' overloading
            //Precondiction: friend function , two parameters
            //Postcondiction: return an object which is the result of (a/b) / (c/d)
            friend const bool operator ==(const Rational& r1, const Rational& r2);
            //operator '==' overloading
            //Precondiction: friend function , two parameters
            //Postcondiction: return true if (a/b) == (c/d)
            //           else return fasle
            Rational& operator =(const Rational& object);

            const bool operator <(const Rational& r);
            //operator '<' overloading
            //Precondiction: member function , one parameter
            //Postcondiction: return true if (a/b) < (c/d)
            //           else return fasle
            const bool operator <=(const Rational& r);
            //operator '<=' overloading
            //Precondiction: member function , one parameter
            //Postcondiction: return true if (a/b) <= (c/d)
            //           else return fasle
            const bool operator >(const Rational& r);
            //operator '>' overloading
            //Precondiction: member function , one parameter
            //Postcondiction: return true if (a/b) > (c/d)
            //           else return fasle
            const bool operator >=(const Rational& r);
            //operator '>=' overloading
            //Precondiction: member function , one parameter
            //Postcondiction: return true if (a/b) >= (c/d)
            //           else return fasle
            BigInt& operator [](int index);
            //operator '[]' overloading
            //Precondiction: index must be 0 or 1, or the program will terminate
            //Postcondiction: if index == 0 return object.numerator
            //           else if index == 1 return object.denominator
        private:
            BigInt numerator;
            BigInt denominator;
    };

    void normalize(BigInt& n, BigInt& d);
    //normalize numerator and denominator
    //Precondiction: None
    //Postcondiction: numerator and denominator will be divided by GCD.
    const Rational operator +(const Rational& r1, const Rational& r2);
    //operator '+' overloading
    //Precondiction: nonmember function , two parameters
    //Postcondiction: return an object which is the result of (a/b) + (c/d)
    const Rational operator -(const Rational& r1, const Rational& r2);
    //operator '-' overloading
    //Precondiction: nonmember function , two parameters
    //Postcondiction: return an object which is the result of (a/b) - (c/d)
    const Rational operator -(const Rational& r);
    //operator '-' overloading
    //Precondiction: nonmember function , one parameter
    //Postcondiction: return an object which is the result of -(a/b), while means that
    //object.denominator * (-1)
    BigInt GCD(BigInt a, BigInt b);
    //Precondiction: None
    //Postcondiction: return the Greatest Common Divisor of a and b.
}
#endif
