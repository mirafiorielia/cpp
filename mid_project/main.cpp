#include <iostream>
#include <string>

//#include "rational.h"

using namespace std;

int main()
{
    int a[10];
    int b[10];

    int *p = &a[9];
    *p = 11;
    a[9] = 6;

    cout << p << '\n';
    cout << *p << '\n';

    return 0;
}