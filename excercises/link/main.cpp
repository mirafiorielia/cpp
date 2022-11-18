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

Link *add(Link *head, Link *link)
{
    link->succ = nullptr;

    if (head == nullptr) {
        link->prev = nullptr;
        head = link;
        return head;
    }

    while (head->succ != nullptr) {
        head = head->succ;
    }

    head->succ = link;
    link->prev = head;

    return head;
}

int main()
{
    cout << "GODS\n";

    Link *gods = new Link{"Thor"};

    cout << sizeof(gods) << '\n';

    gods = new Link{"Odin", nullptr, gods};
    gods->succ->prev = gods;

    gods = new Link{"Freia", nullptr, gods};
    gods->succ->prev = gods;

    Link *modern_gods = new Link{"Gesù"};
    modern_gods = insert(modern_gods, new Link{"Baldassarre"});
    modern_gods = insert(modern_gods, new Link{"Bjarne"});

    modern_gods = insert(modern_gods, new Link{"Ghidoni"});
    modern_gods = insert(modern_gods, new Link{"Elia"});
    modern_gods = insert(modern_gods, new Link{"Jasmin"});
    modern_gods = insert(modern_gods, new Link{"Lisa"});
    modern_gods = insert(modern_gods, new Link{"Pietro"});

    // printValues(gods);
    printValues(modern_gods);

    return 0;
}