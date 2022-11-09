#include <iostream>
#include <string>

#include "rational.h"

using namespace std;

int main() {
    Rational rational1 = Rational();
    Rational rational2 = Rational(26);
    Rational rational3 = Rational(26, 10);

    Rational::print("RATIONAL 1: " + to_string(rational1.to_double()));
    Rational::print("RATIONAL 2: " + to_string(rational2.to_double()));
    Rational::print("RATIONAL 3: " + to_string(rational3.to_double()));

    rational1 = rational1 + rational2 + 5;
    rational2 = rational1 - rational2 + rational3;
    rational3 = rational3 * rational2;
    Rational::print("RATIONAL 1: " + to_string(rational1.to_double()));
    Rational::print("RATIONAL 2: " + to_string(rational2.to_double()));
    Rational::print("RATIONAL 3: " + to_string(rational3.to_double()));

    rational1 = rational1 / rational2;

    rational2 = rational1;
    Rational::print("RATIONAL 1: " + to_string(rational1.to_double()));
    Rational::print("RATIONAL 2: " + to_string(rational2.to_double()));

    Rational::print("rational2 == rational1? " + to_string(rational2 == rational1));
    Rational::print("rational2 == rational3? " + to_string(rational2 == rational3));

    Rational::print("rational2 > rational1? " + to_string(rational2 > rational1));
    Rational::print("rational2 < rational3? " + to_string(rational2 < rational3));

    cout << rational1.to_double() << endl;

    Rational::print("RATIONAL 1: " + to_string(rational1.to_double()));
    rational1 = 5 + rational1;
    Rational::print("RATIONAL 1: " + to_string(rational1.to_double()));

    return 0;
}
