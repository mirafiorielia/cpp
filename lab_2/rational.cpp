//
// Created by eliamirafiori on 26/10/2022.
//

#include <iostream>
#include <string>

#include "rational.h"

using namespace std;

Rational::Rational()
    : number{0} {
}

Rational::Rational(double param)
        : number{param} {
}

Rational::Rational(int param)
    : number{double(param)} {
}

Rational::Rational(int numerator, int divider)
    : number{double(numerator) / double(divider)} {
}

void Rational::print(const string& param) {
    cout << param << endl;
}

double Rational::to_double() const {
    return number;
}

void Rational::operator= (const Rational &param) {
    number = param.number;
}

Rational operator+ (Rational param_a, Rational param_b) {
    return {param_a.number + param_b.number};
}

Rational Rational::operator- (Rational param) const {
    return {number - param.to_double()};
}

Rational Rational::operator* (Rational param) const {
    return {number * param.to_double()};
}

Rational Rational::operator/ (Rational param) const {
    return {number / param.to_double()};
}

bool Rational::operator== (Rational param) const {
    return number == param.number;
}

bool Rational::operator> (Rational param) const {
    return number > param.number;
}

bool Rational::operator< (Rational param) const {
    return number < param.number;
}

ostream& operator<< (ostream& os, const Rational& param) {
    os << param.number;
    return os;
}