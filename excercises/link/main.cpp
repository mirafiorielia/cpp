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
    while (p != nullptr)
    {
        if (p->succ == nullptr)
        {
            n->prev = p;
            p->succ = n;
            cout << "N prev " << n->prev->value << '\n';
            cout << "N prev prev" << n->prev->prev->value << '\n';
            // cout << "N succ" << n->succ << '\n';
            cout << "P succ " << p->succ->value << '\n';
            cout << "P prev " << p->prev->value << "\n\n";
            return p;
        }
        cout << "BEFORE P value " << p->value << '\n';
        cout << "BEFORE P succ " << p->succ->value << '\n';
        if (p->prev) cout << "BEFORE P prev " << p->prev->value << '\n';
        p = p->succ;
        cout << "AFTER P value " << p->value << '\n';
        if (p->succ) cout << "AFTER P succ " << p->succ->value << '\n';
        cout << "AFTER P prev " << p->prev->value << "\n\n";
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

    Link *modern_gods = new Link{"Gesù"};
    modern_gods = insert(modern_gods, new Link{"Baldassarre"});
    modern_gods = insert(modern_gods, new Link{"Bjarne"});

    modern_gods = add(modern_gods, new Link{"Ghidoni"});
    modern_gods = add(modern_gods, new Link{"Elia"});

    // printValues(gods);
    printValues(modern_gods);

    return 0;
}