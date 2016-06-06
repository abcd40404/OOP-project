#include <iostream>
#include <cstdlib>
#include "Rational.h"
#include "BigInt.h"

using namespace std;
using namespace BigInt_Wei;

namespace Rational_LIN{
    Rational::Rational(){
        numerator = 0;
        denominator = 1;
    };

    Rational::Rational(BigInt newNumerator, BigInt newDenominator){
        if(newDenominator == BigInt(0)){
            cout << "Illegal denominator\n";
            exit(1);
        }
        normalize(newNumerator, newDenominator);
        numerator = newNumerator;
        denominator = newDenominator;
    };

    Rational::Rational(BigInt wholeNumber){
        numerator = wholeNumber;
        denominator = BigInt(1);
    };

    Rational::Rational(const Rational& object){
        BigInt n(object.numerator);
        BigInt d(object.denominator);
        numerator = n;
        denominator = d;
    }

    const BigInt Rational::getNumerator() const{
        return this->numerator;
    }

    const BigInt Rational::getDenominator() const{
        return this->denominator;
    }

    ostream& operator <<(ostream& outputStream, const Rational& object){
        outputStream << object.numerator << '/' << object.denominator;
        return outputStream;
    }

    // istream& operator >>(istream& inputStream, Rational& object){
    //     BigInt n, d;
    //     //numerator and denominator
    //     char c;
    //     // '/'
    //     inputStream >> n >> c >> d;
    //     object = Rational(n, d);
    //     return inputStream;
    // }

    const Rational operator *(const Rational& r1, const Rational& r2){
        BigInt n(r1.numerator * r2.numerator);
        BigInt d(r1.denominator * r2.denominator);
        return Rational(n, d);
    }

    const Rational operator /(const Rational& r1, const Rational& r2){
        BigInt n(r1.numerator * r2.denominator);
        BigInt d(r1.denominator * r2.numerator);
        return Rational(n, d);
    }

    const bool operator ==(const Rational& r1, const Rational& r2){
        //a/b == c/d if ad == cb
        BigInt ad(r1.numerator * r2.denominator);
        BigInt cb(r1.denominator * r2.numerator);
        return (ad == cb);
    }

    Rational& Rational::operator =(const Rational& object){
        if(this == &object){
            return *this;
        }
        else{
            BigInt n(object.numerator);
            BigInt d(object.denominator);
            numerator = n;
            denominator = d;
            return *this;
        }
    }

    const bool Rational::operator <(const Rational& r){
        //if b > 0 and d > 0, a/b < c/d provided ad < cb
        if(!this->numerator.isNeg() && !r.numerator.isNeg()){
            BigInt ad = this->numerator * r.denominator;
            BigInt cb = this->denominator * r.numerator;
            return (ad < cb);
        }
        else if(this->numerator.isNeg() && r.numerator.isNeg()){
            BigInt ad = this->numerator * r.denominator;
            BigInt cb = this->denominator * r.numerator;
            return (ad < cb);
        }
        //if b > 0 and d < 0
        else if(!this->numerator.isNeg()){
            return false;
        }
        //if b < 0 and d > 0
        else if(!r.numerator.isNeg()){
            return true;
        }
    }

    const bool Rational::operator <=(const Rational& r){
        //if b > 0 and d > 0, a/b <= c/d provided ad <= cb
        if(!this->numerator.isNeg() && !r.numerator.isNeg()){
            BigInt ad = this->numerator * r.denominator;
            BigInt cb = this->denominator * r.numerator;
            return (ad <= cb);
        }
        else if(this->numerator.isNeg() && r.numerator.isNeg()){
            BigInt ad = this->numerator * r.denominator;
            BigInt cb = this->denominator * r.numerator;
            return (ad <= cb);
        }
        //if b > 0 and d < 0
        else if(!this->numerator.isNeg()){
            return false;
        }
        //if b < 0 and d > 0
        else if(!r.numerator.isNeg()){
            return true;
        }
    }

    const bool Rational::operator >(const Rational& r){
        //if b > 0 and d > 0, a/b > c/d provided ad > cb
        if(!this->numerator.isNeg() && !r.numerator.isNeg()){
            BigInt ad = this->numerator * r.denominator;
            BigInt cb = this->denominator * r.numerator;
            return (ad > cb);
        }
        else if(this->numerator.isNeg() && r.numerator.isNeg()){
            BigInt ad = this->numerator * r.denominator;
            BigInt cb = this->denominator * r.numerator;
            return (ad > cb);
        }
        //if b > 0 and d < 0
        else if(!this->numerator.isNeg()){
            return true;
        }
        //if b < 0 and d > 0
        else if(!r.numerator.isNeg()){
            return false;
        }
    }

    const bool Rational::operator >=(const Rational& r){
        //if b > 0 and d > 0, a/b >= c/d provided ad >= cb
        if(!this->numerator.isNeg() && !r.numerator.isNeg()){
            BigInt ad = this->numerator * r.denominator;
            BigInt cb = this->denominator * r.numerator;
            return (ad >= cb);
        }
        else if(this->numerator.isNeg() && r.numerator.isNeg()){
            BigInt ad = this->numerator * r.denominator;
            BigInt cb = this->denominator * r.numerator;
            return (ad >= cb);
        }
        //if b > 0 and d < 0
        else if(!this->numerator.isNeg()){
            return true;
        }
        //if b < 0 and d > 0
        else if(!r.numerator.isNeg()){
            return false;
        }
    }

    BigInt& Rational::operator [](int index){
        if(index == 0){
            return numerator;
        }
        else if(index == 1){
            return denominator;
        }
        else{
            cout << "Illegal index\n";
            exit(1);
        }
    }

    void normalize(BigInt& n, BigInt& d){
        BigInt gcd = GCD(n, d);
        n = n / gcd;
        d = d / gcd;
        if(n.isNeg() && d.isNeg()){
            n = -n;
            d = -d;
        }
        else if(!n.isNeg() && d.isNeg()){
            n = -n;
            d = -d;
        }
    }

    const Rational operator +(const Rational& r1, const Rational& r2){
        //If the parameters are const, then the get() function must be suffix const
        BigInt n1(r1.getNumerator());
        BigInt n2(r2.getNumerator());
        BigInt d1(r1.getDenominator());
        BigInt d2(r2.getDenominator());
        BigInt gcd(GCD(d1, d2));
        gcd.abs();
        if(!n1.isNeg() && !n2.isNeg()){
            BigInt n(n1 * (d2 / gcd) + n2 * (d1 / gcd));
            BigInt d(d1 * d2 / gcd);
            return Rational(n, d);
        }
        else if(n1.isNeg() && n2.isNeg()){
            n1 = -n1;
            d1 = -d1;
            n2 = -n2;
            d2 = -d2;
            BigInt n(n1 * (d2 / gcd) + n2 * (d1 / gcd));
            BigInt d(d1 * d2 / gcd);
            return Rational(n, d);
        }
        else if(!n1.isNeg() && n2.isNeg()){
            n2 = -n2;
            d2 = -d2;
            BigInt n(n1 * (d2 / gcd) + n2 * (d1 / gcd));
            BigInt d(d1 * d2 / gcd);
            return Rational(n, d);
        }
        else if(n1.isNeg() && !n2.isNeg()){
            n1 = -n1;
            d1 = -d1;
            BigInt n(n2 * (d1 / gcd) + n1 * (d2 / gcd));
            BigInt d(d1 * d2 / gcd);
            return Rational(n, d);
        }
    }

    const Rational operator -(const Rational& r1, const Rational& r2){
        Rational r(r1 + (-r2));
        return r;
    }

    const Rational operator -(const Rational& r){
        BigInt n(r.getNumerator() * BigInt("-1"));
        return Rational(n, r.getDenominator());
    }

    BigInt GCD(BigInt a, BigInt b){
        while(1){
            if(b.getUsed() == 1 && b.getDigit()[0] == '0')
                break;
            BigInt c(a % b);
            a = b;
            b = c;
        }
        return a;
    }
}
