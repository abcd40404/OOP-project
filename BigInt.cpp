#include <iostream>
#include <algorithm>
#include <cstring>
#include "BigInt.h"
using namespace std;
BigInt::BigInt()
{
    capacity = 1;
    used = 0;
    digit = new char;
}
BigInt::BigInt(int data)
{
    int neg = 0;
    used = 0;
    if(data < 0)
    {
        neg = 1;
        data *= -1;
    }
    int *temp = new int [1000],i=0;
    if(data == 0)
        temp[used++] = 0;
    while(data != 0)
    {
        temp[i++] = data % 10;
        data/=10;
        used++;
    }
    capacity = used + 2;
    digit = new char[capacity];
    for(int i=0 ;i < used; i++)
       digit[i] = temp[i] + '0';
    if(neg == 1)
        digit[used++] = '-';
    delete [] temp;
}
BigInt::BigInt(char *num)
{
    int len = strlen(num);
    if(num[len-1] == '!')
    {
        char *temp;
        temp = new char[len];
        strcpy(temp , num);
        used = 1;
        capacity = 1;
        digit = new char;
        digit[0] = '1';
        temp[len - 1] = 0;
        factorial(temp);
    }
    else
    {
        used = 0;
        capacity = 1;
        int start = 0;
        int neg = 0;
        for(int i=0; i < len; i++)
        {
            if(num[i] == '0')
                start++;
            else if(num[i] == '-')
               {
                   start++;
                   neg = 1;
               }
            else
                break;
        }
        while(len > capacity)
            capacity*=2;
        digit = new char[capacity];
        for(int i = 0; i < capacity; i++)
            digit[i] = '0';
        int index = len-1;
        for(int i=0; i<(len-start) ;i++)
        {
            digit[i] = num[index--];
            used++;
        }
        if(used == 0)
            used++;
        if(neg == 1)
            digit[used++] = '-';
    }

}
BigInt::BigInt(const BigInt& num)
{
    capacity = num.capacity;
    used = num.used;
    digit = new char [capacity];
    for(int i=0;i< capacity;i++)
       digit[i]='0';
    for(int i=0; i < capacity; i++)
        digit[i]=num.digit[i];
}
BigInt::~BigInt()
{
    delete [] digit;
    digit = NULL;
}
int BigInt::getCapacity () const
{
    return capacity;
}
int BigInt::getUsed () const
{
    return used;
}
char* BigInt::getDigit () const
{
    char* data = new char[capacity];
    for(int i = 0; i < capacity; i++)
        data[i] = digit[i];
    return data;
}
ostream& operator <<(ostream& input, const BigInt& num)
{
    for(int i=num.used-1;i>=0;i--)
      input << num.digit[i];
     return input;
}
const BigInt operator *(const BigInt& num1, const BigInt& num2)
{
    BigInt ans;
    ans.capacity = num1.used + num2.used + 2;
    delete [] ans.digit;
    ans.digit = new char[ans.capacity];
    for(int i=0; i < ans.capacity ;i++)
        ans.digit[i] = '0';
    int temp = 0,limit1 = num1.used,limit2 = num2.used,i = 0,j = 0,carry = 0;
    if(num1.digit[num1.used-1] == '-')
        limit1--;
    if(num2.digit[num2.used-1] == '-')
        limit2--;
    for(i=0; i < limit2; i++)
    {
        for(j=0; j < limit1; j++)
        {
            temp = (num1.digit[j] - '0') * (num2.digit[i] - '0');
            temp += carry;
            temp +=(ans.digit[i + j] - '0');
            carry = 0;
            if(0 <= temp && temp <= 9)
            {
            }
            else
            {
                carry = temp / 10;
                temp %= 10;
            }
            ans.digit[i + j] = temp + '0';
            if(j == limit1-1)
            {
                ans.digit[i+j+1] += carry;
                carry = 0;
            }
        }
    }
    for(int i=ans.capacity - 1; i >= 0; i--)
    {
        if(ans.digit[i] != '0')
        {
            ans.used = i + 1;
            break;
        }
        if(i == 0 && ans.digit[i] == '0')
        {
            ans.used = i + 1;
            return ans;
            break;
        }
    }
    if((num1.digit[num1.used-1] == '-' && num2.digit[num2.used-1] != '-')
        ||(num1.digit[num1.used-1] != '-' && num2.digit[num2.used-1] == '-'))
        ans.digit[ans.used++] = '-';
    return ans;
}
const BigInt operator /(const BigInt& num1, const BigInt& num2){
    if(num2 == BigInt(0)){
        cout << "Illegal number\n";
        exit(1);
    }
    if(num1 == BigInt(0)){
        return BigInt(0);
    }
    BigInt divisor(num2);
    int len1 = num1.used;
    bool neg1 = false, neg2 = false;
    if(num1.digit[num1.used - 1] == '-'){
        neg1 = true;
        len1--;
    }
    if(num2.digit[num2.used - 1] == '-'){
        neg2 = true;
        divisor.abs();
    }
    if(len1 < divisor.used){
        return BigInt(0);
    }
    char *block = new char[num1.capacity];
    char *ans = new char[num1.capacity];
    int len(divisor.used);
    int block_idx(0);
    int ans_idx(0);
    memset(ans, 0, sizeof(ans));

    if((neg1 == true && neg2 == false) || (neg1 == false && neg2 == true)){
        ans[ans_idx++] = '-';
    }
    //get block
    for(int i = len1 - 1; block_idx < len; i--){
        if(i < 0)
            break;
        block[block_idx++] = num1.digit[i];
    }
    block[block_idx] = '\0';
    for(int i = len1 - len; i >= 0; i--){
        if(i != len1 - len){
            block[block_idx++] = num1.digit[i];

            block[block_idx] = '\0';
        }
        BigInt temp(block);

        if(divisor > temp){
            if(i != len1 - len)
                ans[ans_idx++] = '0';
            if(i == 0)
                break;

            block[block_idx++] = num1.digit[i - 1];
            block[block_idx] = '\0';
            temp = BigInt(block);
            i--;
        }

        int lb = 1, ub = 9;
        while(ub - lb > 1){
            // 1,0
            if(divisor * ub <= temp){
                lb = ub;
                break;
            }

            if(divisor * lb > temp){
                lb = 0;
                break;
            }

            int mid = (lb + ub) / 2;
            if(divisor * mid > temp)
                ub = mid;
            else
                lb = mid;
        }
        ans[ans_idx++] = lb + '0';
        ans[ans_idx] = '\0';
        BigInt product;
        product = divisor * lb;
        temp = temp - product;

        block_idx = 0;
        for(int j = temp.used - 1; j >= 0; j--){
            block[block_idx++] = temp.digit[j];
        }
        block[block_idx] = '\0';
    }

    return BigInt(ans);
}
const BigInt operator %(const BigInt& num1, const BigInt& num2){
    if(num2 == BigInt(0)){
        cout << "Illegal number\n";
        exit(1);
    }
    if(num1 == BigInt(0)){
        return BigInt(0);
    }
    BigInt divisor(num2);
    int len1 = num1.used;
    bool neg1 = false, neg2 = false;
    if(num1.digit[num1.used - 1] == '-'){
        neg1 = true;
        len1--;
    }
    if(num2.digit[num2.used - 1] == '-'){
        neg2 = true;
        divisor.abs();
    }

    char *block = new char[num1.capacity];
    int len(divisor.used);
    int block_idx(0);

    //get block
    for(int i = len1 - 1; block_idx < len; i--){
        if(i < 0)
            break;
        block[block_idx++] = num1.digit[i];
    }
    block[block_idx] = '\0';

    for(int i = len1 - len; i >= 0; i--){
        if(i != len1 - len){
            block[block_idx++] = num1.digit[i];
            block[block_idx] = '\0';
        }
        BigInt temp(block);

        if(divisor > temp){
            if(i == 0)
                break;

            block[block_idx++] = num1.digit[i - 1];
            block[block_idx] = '\0';
            temp = BigInt(block);
            i--;
        }

        int lb = 1, ub = 9;
        while(ub - lb > 1){
            // 1,0
            if(divisor * ub <= temp){
                lb = ub;
                break;
            }

            if(divisor * lb > temp){
                lb = 0;
                break;
            }

            int mid = (lb + ub) / 2;
            if(divisor * mid > temp)
                ub = mid;
            else
                lb = mid;
        }

        BigInt product;
        product = divisor * lb;
        temp = temp - product;

        block_idx = 0;
        for(int j = temp.used - 1; j >= 0; j--){
            block[block_idx++] = temp.digit[j];
        }
        block[block_idx] = '\0';
    }
    return BigInt(block);
}
const BigInt operator +(const BigInt& num1, const BigInt& num2)
{
    BigInt ans;
    if(num1.digit[num1.used - 1] == '-' && num2.digit[num2.used - 1] != '-')
    {
         ans = num2 - (-num1);
         return ans;
    }
    if(num1.digit[num1.used - 1] != '-' && num2.digit[num2.used - 1] == '-')
    {
        ans = num1 - (-num2);
        return ans;
    }
    int neg = 0, limit1 = num1.used, limit2 = num2.used;
    if(num1.digit[num1.used - 1] == '-' && num2.digit[num2.used - 1] == '-')
    {
        limit1--;
        limit2--;
        neg = 1;
    }
    if(num1.used > num2.used)
    {
        ans.digit = new char[num1.used + 2];
        ans.capacity = num1.used + 2;
    }
    else
    {
        ans.digit = new char[num2.used + 2];
        ans.capacity = num2.used + 2;
    }
    for(int i = 0; i < ans.capacity; i++)
        ans.digit[i] = '0';
    int max_len,carry = 0,temp = 0;
    max_len = limit1 > limit2 ? limit1 : limit2;
    for(int i = 0; i < max_len; i++)
    {

        if(limit1 > limit2)
        {
            temp += carry;
            carry = 0;
            if(i < limit2)
                temp += (num1.digit[i] - '0') + (num2.digit[i] - '0');
            else
                temp += (num1.digit[i] - '0');
            if(0 <= temp && temp <= 9)
            {
                ans.digit[i] = temp + '0';
            }
            else
            {
                carry = 1;
                ans.digit[i] = temp % 10 + '0';
            }
            temp = 0;
        }
        else
        {
            temp += carry;
            carry = 0;
            if(i < limit1)
                temp += (num1.digit[i] - '0') + (num2.digit[i] - '0');
            else
                temp += num2.digit[i] - '0';
            if(0 <= temp && temp <= 9)
            {
                ans.digit[i] = temp + '0';
            }
            else
            {
                carry = 1;
                ans.digit[i] = temp % 10 + '0';
            }
            temp = 0;
        }
        if(i == max_len - 1)
        {
            if(carry == 1)
            {
                ans.digit[max_len] = '1';
                carry = 0;
                ans.used = max_len + 1;
            }
            else
                ans.used = max_len;
        }
    }
    if(neg == 1)
        ans.digit[ans.used++] = '-';
     return ans;
}
const BigInt operator -(const BigInt& num1, const BigInt& num2)
{
    BigInt ans;
    if(num1.digit[num1.used - 1] == '-' && num2.digit[num2.used - 1] != '-')
    {
         ans = num1 + (-num2);
         return ans;
    }
    if(num1.digit[num1.used - 1] != '-' && num2.digit[num2.used - 1] == '-')
    {
        ans = num1 + (-num2);
        return ans;
    }
    int limit1 = num1.used, limit2 = num2.used, neg = 0;
    if(num1.digit[num1.used - 1] == '-' && num2.digit[num2.used - 1] == '-')
    {
        limit1--;
        limit2--;
        neg = 1;
    }
    int max_len = limit1 > limit2 ? limit1 : limit2;
    ans.digit = new char[max_len + 2];
    ans.capacity = max_len + 2;
    for(int i = 0; i < ans.capacity; i++)
        ans.digit[i] = '0';
    int borrow = 0,temp;
    if(num1 > num2)
    {
        for(int i=0; i < max_len; i++)
        {
            if(i < limit2)
                temp = num1.digit[i] - num2.digit[i];
            else
                temp = num1.digit[i] - '0';
            temp -= borrow;
            borrow = 0;
            if(temp < 0)
                {
                    borrow = 1;
                    temp+=10;
                }
            ans.digit[i] = temp +'0';
        }
    }
    else
    {
        for(int i=0; i < max_len; i++)
        {

            if(i < limit1)
                temp = num2.digit[i] - num1.digit[i];
            else
                temp = num2.digit[i] - '0';
            temp -= borrow;
            borrow = 0;
            if(temp < 0)
                {
                    borrow = 1;
                    temp+=10;
                }
            ans.digit[i] = temp +'0';
        }
    }
    for(int i = max_len - 1; i >= 0; i--)
    {
        if(ans.digit[i] != '0')
        {
            ans.used = i + 1;
            break;
        }
        if(i == 0 && ans.digit[i] == '0')
        {
            ans.used = 1;
            return ans;
        }
    }
    if((num1 > num2 && neg == 1) || (num1 <= num2 && neg == 0))
    {
        if(ans.used != 0)
            ans.digit[ans.used] = '-';
        ans.used++;
    }
    return ans;
}
const BigInt operator -(const BigInt& num)
{
    BigInt ans;
    ans.capacity = num.capacity;
    ans.used = num.used;
    ans.digit = new char[num.capacity];
    strcpy(ans.digit,num.digit);
    if(ans.digit[ans.used - 1] == '-')
    {
        ans.digit[ans.used - 1] = '\0';
        ans.used = ans.used - 1;
    }
    else
    {
        ans.digit[ans.used] = '-';
        ans.used = ans.used + 1;
    }
    return ans;
}
bool BigInt::operator >(const BigInt&num) const
{
    int limit1 = used, limit2 = num.used;
    if(digit[used - 1] == '-')
        limit1--;
    if(num.digit[num.used - 1] == '-')
        limit2--;
    if(limit1 > limit2)
        return 1;
    if(limit1 < limit2)
        return 0;
    for(int i=limit1 - 1; i >= 0; i--)
    {
        if(digit[i] > num.digit[i])
            return true;
        else if(digit[i] < num.digit[i])
            return false;
    }
    return 0;
}
bool BigInt::operator >=(const BigInt&num) const
{
    int limit1 = used, limit2 = num.used;
    if(digit[used - 1] == '-')
        limit1--;
    if(num.digit[num.used - 1] == '-')
        limit2--;
    if(limit1 > limit2)
        return true;
    if(limit1 < limit2)
        return false;
    for(int i=limit1 - 1; i >= 0; i--)
    {
        if(digit[i] > num.digit[i])
            return true;
        else if(digit[i] < num.digit[i])
            return false;
    }
    return true;
}
bool BigInt::operator <(const BigInt&num) const
{
    int limit1 = used, limit2 = num.used;
    if(digit[used - 1] == '-')
        limit1--;
    if(num.digit[num.used - 1] == '-')
        limit2--;
    if(limit1 < limit2)
        return true;
    if(limit1 > limit2)
        return false;
    for(int i=limit1 - 1; i >= 0; i--)
    {
        if(digit[i] < num.digit[i])
            return true;
        else if(digit[i] > num.digit[i])
            return false;
    }
    return false;
}
bool BigInt::operator <=(const BigInt&num) const
{
    int limit1 = used, limit2 = num.used;
    if(digit[used - 1] == '-')
        limit1--;
    if(num.digit[num.used - 1] == '-')
        limit2--;
    if(limit1 < limit2)
        return true;
    if(limit1 > limit2)
        return false;
    for(int i=limit1 - 1; i >= 0; i--)
    {
        if(digit[i] < num.digit[i])
            return true;
        else if(digit[i] > num.digit[i])
            return false;
    }
    return 1;
}
bool BigInt::operator ==(const BigInt& num) const{
    if(this->used != num.used){
        return false;
    }
    else{
        for(int i = this->used - 1; i >= 0; i--){
            if(this->digit[i] != num.digit[i]){
                return false;
            }
        }
        return true;
    }
}
BigInt& BigInt::operator =(BigInt num)
{
    if(this == &num)
    return *this;
    else
    {
        capacity = num.capacity;
        used = num.used;
        delete [] digit;
        digit = new char [capacity];
        for(int i=0;i < capacity ;i++)
        digit[i] = num.digit[i];
        return *this;
    }
}
void BigInt::factorial(char *num)
{
    int neg = 0;
    if(num[0] == '-')
        neg = 1;
    char temp[2] = "1";
    BigInt one(temp), i(temp),limit(num);
    digit[0] = '1';
    for(i; i <= limit; i = i + 1)
        *this = *this * i;
    if(neg == 1)
        digit[used++] = '-';
}

bool BigInt::isNeg() const{
    if(this->digit[this->used - 1] == '-')
        return true;
    else
        return false;
}

void BigInt::abs() {
    if(this->digit[this->used - 1] == '-'){
        this->digit[this->used - 1] == '\0';
        this->used--;
    }
}
