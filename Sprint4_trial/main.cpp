#include <iostream>
#include "linkedlist.h"
#include "dsstring.h"
#include "stack.h"
#include "airport.h"
using namespace std;

int main(int argc, char *argv[])
{
    String hi;
    hi = "hi";
    cout << hi << endl;
    hi.clear();
    hi.~String();
    delete hi;
    return 0;
}
