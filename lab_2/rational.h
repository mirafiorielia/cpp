//
// Created by eliamirafiori on 26/10/2022.
//

#ifndef LAB_2_RATIONAL_H
#define LAB_2_RATIONAL_H

#include <iostream>
#include <string>

#include "rational.h"

using namespace std;

class Rational {
    private:
        double number;

    public:
        Rational();
        Rational(double param);
        Rational(int param);
        Rational(int numerator, int divider);

        static void print(const string& param);

        double to_double() const;

        void operator= (const Rational &param);
        friend Rational operator+ (Rational param_A, Rational param_b);
        Rational operator- (Rational param) const;
        Rational operator* (Rational param) const;
        Rational operator/ (Rational param) const;
        bool operator== (Rational param) const;
        bool operator> (Rational param) const;
        bool operator< (Rational param) const;
        friend ostream& operator<< (ostream& os, const Rational& param);
};


#endif //LAB_2_RATIONAL_H
