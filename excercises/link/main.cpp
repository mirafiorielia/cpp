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
link is inserted between head and its previous node
x -> link -> head
*/
Link *insert(Link *head, Link *link)
{
    if (!link)
        return head;

    if (!head) // (head != nullptr) ??
        return link;

    link->succ = head;

    if (head->prev)
        head->prev->succ = link;

    link->prev = head->prev;
    head->prev = link;
    return link;
}

Link *add(Link *head, Link *link)
{
    Link *last = head;
    link->succ = nullptr;

    if (last == nullptr) {
        link->prev = nullptr;
        last = link;
        return last;
    }

    while (last->succ != nullptr) {
        last = last->succ;
    }

    last->succ = link;
    link->prev = last;

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

    modern_gods = add(modern_gods, new Link{"Ghidoni"});
    modern_gods = add(modern_gods, new Link{"Elia"});
    modern_gods = add(modern_gods, new Link{"Jasmin"});
    modern_gods = add(modern_gods, new Link{"Lisa"});
    modern_gods = add(modern_gods, new Link{"Pietro"});

    // printValues(gods);
    printValues(modern_gods);

    return 0;
}