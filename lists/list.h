#ifndef LIST
#define LIST

#include <iostream>
#include "transaction.h"
using namespace std;

class List
{
    public:
        //---------------------------------------------------------------------
        // Default constructor
        List();

        //---------------------------------------------------------------------
        // Virtual Destructor
        virtual ~List();

        //---------------------------------------------------------------------
        // Pure virtual function to see if list is empty
        virtual bool isEmpty() const = 0;

        //---------------------------------------------------------------------
        // Pure virtual function to add node to end of list
        virtual bool append() = 0;

        //---------------------------------------------------------------------
        // Pure virtual function to print out entire list
        virtual void print() = 0;

};

#endif