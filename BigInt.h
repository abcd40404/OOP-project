#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;

#ifndef YYYYE_H
#define YYYYE_H
class BigInt
{
    public:
    BigInt();
    BigInt(char *data);
    BigInt(int data);
    BigInt(const BigInt& num);
    ~BigInt();
    int getCapacity();
    int getUsed();
    char *getDigit();
    friend const BigInt operator *(const BigInt& num1, const BigInt& num2);
    friend const BigInt operator /(const BigInt& num1, const BigInt& num2);
    friend const BigInt operator %(const BigInt& num1, const BigInt& num2);
    friend const BigInt operator +(const BigInt& num1, const BigInt& num2);
    friend const BigInt operator -(const BigInt& num1, const BigInt& num2);
    friend const BigInt operator -(const BigInt& num);
    BigInt& operator =(BigInt num);
    bool operator >(const BigInt& num) const;
    bool operator >=(const BigInt& num) const;
    bool operator <(const BigInt& num) const;
    bool operator <=(const BigInt& num) const;
    bool operator ==(const BigInt& num) const;
    friend ostream& operator <<(ostream& input, const BigInt& num);
    void factorial(char *num);
    bool isNeg() const;
    void abs();
    
    private:
    int capacity;
    int used;
    char *digit;
};
#endif