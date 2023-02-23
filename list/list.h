//---------------------------------------------------------------------------
// list.h
// Parent list class for implementing linked lists
//---------------------------------------------------------------------------
// List class Implementation and assumptions:  
//   -- List is a pure virtual class, not intended to be called directly.
//   -- Implementation is left to derived classes.
//
//---------------------------------------------------------------------------
#ifndef LIST
#define LIST

#include <iostream>
#include "item.h"
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
        // Pure virtual function to print out entire list
        virtual void print() const = 0;

        //---------------------------------------------------------------------
        // Pure virtual function for deleting list
        virtual void makeEmpty() = 0;

};

#endif
