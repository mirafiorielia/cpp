#include <iostream>
#include <string>

#include "link.h"

using namespace std;

void printValues(Link *gods)
{
    while (gods != nullptr)
    {
        cout << gods->value << '\n';
        gods = gods->succ;
    }
}

/*
newLink is inserted between persitentLink and its previous link
x -> newLink -> persistentLink
*/
Link *insert(Link *p, Link *n)
{
    if (!n)
        return p;

    if (!p)
        return n;

    n->succ = p;

    if (p->prev)
        p->prev->succ = n;

    n->prev = p->prev;
    p->prev = n;
    return n;
}

Link *add(Link *p, Link *n)
{
    if (!n)
        return p;

    if (!p)
        return n;

    while (p != nullptr)
    {

        cout << "P\n";
        cout << p->value << '\n';

        if (p->succ == nullptr)
        {
            n->prev = p;
            p->succ = n;
            return;
        }
        else
        {
            p = p->succ;
        }
    }

    return n;
}

int main()
{
    cout << "GODS\n";

    Link *gods = new Link{"Thor"};

    gods = new Link{"Odin", nullptr, gods};
    gods->succ->prev = gods;

    gods = new Link{"Freia", nullptr, gods};
    gods->succ->prev = gods;

    Link *modernGods = new Link{"Gesù"};
    modernGods = insert(modernGods, new Link("Baldassarre"));
    modernGods = insert(modernGods, new Link("Bjarne"));

    modernGods = add(modernGods, new Link("elia"));
    modernGods = add(modernGods, new Link("jasmin"));

    printValues(gods);
    printValues(modernGods);

    return 0;
}