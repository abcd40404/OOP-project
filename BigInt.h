//Team No: 9
//Name: 林秉辭
//Student ID: 403410070
//Dept: 資工系
//Year: 大二
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#ifndef YYYYE_H
#define YYYYE_H
namespace BigInt_Wei
{
    class BigInt
    {
        public:
        BigInt();//constructor
        BigInt(const char *data);//constructor
        BigInt(int data);//constructor
        BigInt(const BigInt& num);//copy constructor
        ~BigInt();//destructor
        int getCapacity() const;//access function
        int getUsed() const;//access function
        char *getDigit() const;//access function
        friend const BigInt operator *(const BigInt& num1, const BigInt& num2);
        //precondition: num1,num2 are BigInt
        //postcondition: ans = num1 * num2 , return ans
        friend const BigInt operator /(const BigInt& num1, const BigInt& num2);
        //precondition: num1,num2 are BigInt
        //postcondition: ans = num1 / num2 , return ans
        friend const BigInt operator %(const BigInt& num1, const BigInt& num2);
        //precondition: num1,num2 are BigInt
        //postcondition: ans = num1 % num2 , return ans
        friend const BigInt operator +(const BigInt& num1, const BigInt& num2);
        //precondition: num1,num2 are BigInt
        //postcondition: ans = num1 + num2 , return ans
        friend const BigInt operator -(const BigInt& num1, const BigInt& num2);
        //precondition: num1,num2 are BigInt
        //postcondition: ans = num1 - num2 , return ans
        friend const BigInt operator -(const BigInt& num);
        //precondition: num is BigInt
        //postcondition: ans = -num, return ans
        BigInt& operator =(BigInt num);
        //precondition: a = b , a and b are BigInt(class)
        //postcondition: a is assigned to b(a = b)
        bool operator >(const BigInt& num) const;
        // precondition: num1 > num2 ,num1 and num2 are BigInt
        // postcondition: if num1 > num2 return true,else return false
        bool operator >=(const BigInt& num) const;
        // precondition: num1 >= num2 ,num1 and num2 are BigInt
        // postcondition: if num1 >= num2 return true,else return false
        bool operator <(const BigInt& num) const;
        // precondition: num1 < num2 ,num1 and num2 are BigInt
        // postcondition: if num1 < num2 return true,else return false
        bool operator <=(const BigInt& num) const;
        // precondition: num1 <= num2 ,num1 and num2 are BigInt
        // postcondition: if num1 <= num2 return true,else return false
        bool operator ==(const BigInt& num) const;
        // precondition: num1 == num2 ,num1 and num2 are BigInt
        // postcondition: if num1 == num2 return true,else return false
        friend ostream& operator <<(ostream& input, const BigInt& num);
        //  output dynamic array in num.
        void factorial(char *num);
        // precondition: num is a char pointer
        //postcondition: do num!
        bool isNeg() const;
        //if num < 0 return true, else return false
        void abs();
        //if num < 0 return -num, else return num

        private:
        int capacity;
        int used;
        char *digit;
    };
}
#endif
