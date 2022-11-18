#include <iostream>

#include "link.h"

using namespace std;

/*
newLink is inserted between persitentLink and its previous link
x -> newLink -> persistentLink
*/
Link *Link::insert(Link *persistentLink, Link *newLink)
{
    if (!newLink)
        return persistentLink;
    if (!persistentLink)
        return newLink;

    newLink->succ = persistentLink;

    if (persistentLink->prev)
        persistentLink->prev->succ = newLink;

    persistentLink->prev->succ = newLink;
    newLink->prev = persistentLink->prev;
    persistentLink->prev = newLink;
    return newLink;
}