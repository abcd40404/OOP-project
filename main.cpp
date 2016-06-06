//Team No: 9
//Name: 林秉辭
//Student ID: 403410070
//Dept: 資工系
//Year: 大二
#include <iostream>
#include <cstdlib>
#include "Rational.h"
#include "BigInt.h"
#include "Complex.h"
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
using namespace BigInt_Wei;
using namespace Rational_LIN;
using namespace Complex_JAY;


int main(){
    // ((1/7 * 100!/520!) + (-8/15 * 128!/320!)) / ((100!/520!)^2 + (128!/320!)^2)
    Rational r1(BigInt("1"), BigInt("7"));
    Rational r2(BigInt("-8"), BigInt("15"));
    Rational r3(BigInt("100!"), BigInt("520!"));
    Rational r4(BigInt("128!"), BigInt("320!"));
    Rational r5(r2 * r3);
    Rational r6(r1 * r4);
    Rational r7(r3 * r3);
    Rational r8(r4 * r4);
    Rational r9(r5 - r6);
    Rational r10(r7 + r8);
    Complex c1(r1, r2);
    Complex c2(r3, r4);
    cout << c1 / c2 << endl;
    // -1931276102771238509
    // 61644223157798120177
    // BigInt a("48!"), b("1"), c("4650454253"), d("1");
    // BigInt e("4288493554"), f("1"), g("1353940654"), h("1");
    // Rational r1(a, b), r2(c, d), r3(e, f), r4(g, h);
    // Complex c1(r1, r2), c2(r3, r4);
    // cout << c1 << endl;
    // cout << c2 << endl;
    // cout << c1 / c2 << endl;
    system("pause");
    return 0;
}
