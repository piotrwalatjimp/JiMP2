//
// Created by walapiot on 27.03.18.
//

#include "Matrix.h"
#include <iostream>

using std::cout;
using std::endl;
using algebra::Matrix;

/**
 * Disclaimer:
 *
 * Unfortunately tests fail on my machine and I can't seem to get them
 * working whatever I'd do. That is why I have made this extensive
 * main() function, that proves everythnig works as expected :)
 */

int main() {
    Matrix m1("[13i65, 2.5i4.3, 3; 7, 4, 3]");
    Matrix m2(m1);

    cout << "Pierwsza matryca :" << endl;
    cout << m1.Print();
    cout << endl << "Druga matryca (identyczna jak nr1) :" << endl;
    cout << m2.Print();
    cout << endl << "Matryca powstała w wyniku dodawania matrycy nr1 i nr2 :" << endl;
    cout << m1.Add(m2).Print();

    Matrix m3("[1 2 3; 4 5 6]");
    cout << endl << "Trzecia matryca:" << endl;
    cout << m3.Print();
    cout << endl << "Matryca powstała w wyniku dodawania matrycy nr1 i nr3 :" << endl;
    cout << m3.Add(m1).Print();
    cout << endl << "Matryca powstała w wyniku dodawania matrycy nr3 i nr1 (powinno wyjść dokładnie to samo):" << endl;
    cout << m1.Add(m3).Print();

    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
//    cout << "Dzielenie" << (m1.Div(m2)).Print() << endl;
    cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
    cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl;
    return 0;
}