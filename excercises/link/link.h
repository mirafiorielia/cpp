#include <string>

using namespace std;

struct Link
{
    string value;
    Link *prev, *succ;
    Link(const string &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}

    Link* insert(Link *persistentLink, Link *newLink);
};
