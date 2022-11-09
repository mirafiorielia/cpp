#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int global_init_var = 1;
static int global_var;

void fibonacci(int, int, vector<int>, int);
void print(const string&, const vector<int>&);
void call_counter();

int main() {
    int local_var;
    static int static_init_var = 1;
    static int static_var;

    fibonacci(1, 2, {}, 10);

    return 0;
}

void fibonacci(int x, int y, vector<int> elements, int size) {
    elements.push_back(x);
    elements.push_back(y);

    for (int index = 2; index < size; ++index) {
        elements.push_back(elements[index - 1] + elements[index - 2]);
        call_counter();
    }

    print("FIBONACCI", elements);
}

void print(const string& tag, const vector<int>& elements) {
    for (int element : elements) {
        cout << tag << ' ' << element << "\n";
    }
}

void call_counter() {
    static int counter = 0;
    counter++;

    cout << "func called: " << counter << " times\n";
}
