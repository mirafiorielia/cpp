#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "please insert your first and second names\n";

    string first;
    string second;
    int age;

    cin >> first >> second >> age;
    cout << "hello, " + first + ' ' + second + ' ' << age++ << '\n';

    return 0;
}