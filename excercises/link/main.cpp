#include <iostream>
#include <string>

#include "link.h"

using namespace std;

/*
newLink is inserted between persitentLink and its previous link
x -> newLink -> persistentLink
*/
Link *insert(Link *p, Link *n)
{
    cout << !n << '\n';
    if (!n)
        return p;

    cout << !p << '\n';
    if (!p)
        return n;

    n->succ = p;

    cout << p->prev << '\n';
    if (p->prev)
        p->prev->succ = n;

    n->prev = p->prev;
    p->prev = n;
    return n;
}

void printValues(Link *gods)
{
    while (gods != nullptr)
    {
        cout << gods->value << '\n';
        gods = gods->succ;
    }
}

int main()
{
    cout << "GODS\n";

    /*
    Link *gods = new Link{"Thor"};

    gods = new Link{"Odin", nullptr, gods};
    gods->succ->prev = gods;

    gods = new Link{"Freia", nullptr, gods};
    gods->succ->prev = gods;
    */

    Link *modernGods = new Link{"Gesù"};
    modernGods = insert(modernGods, new Link("Baldassarre"));
    modernGods = insert(modernGods, new Link("Bjarne"));

    // printValues(gods);
    printValues(modernGods);

    return 0;
}