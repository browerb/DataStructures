#ifndef AIRPORT_H
#define AIRPORT_H

#include "linkedlist.h"
#include "dsstring.h"

class Airport
{
public:
    Airport();
    Airport(String);
    void addDestination(Airport);
    void display();

private:
    String name;
    LinkedList <String> flights;
};

#endif // AIRPORT_H
