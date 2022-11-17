#include <iostream>
#include <string>

//#include "rational.h"

using namespace std;

int main()
{
    int x = 10;
    int *p = &x;

    cout << x << '\n';
    cout << &x << '\n';
    cout << p << '\n';
    cout << *p << '\n';

    *p = 5;

    cout << x << '\n';
    cout << &x << '\n';
    cout << p << '\n';
    cout << *p << '\n';

    return 0;
}