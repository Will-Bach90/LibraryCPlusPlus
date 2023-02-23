//---------------------------------------------------------------------------
// patron.h
// A class that implements a linked list for holding Patrons
//---------------------------------------------------------------------------
// PatronList class:
//
// Implementation and assumptions:
// -- Implements a linked list for Patron objects
// -- Performs linked list operations such as add, retrieve, and 
// remove Patrons from the list data structure
// -- Assumes that Patron objects have a unique identifier (ID) to use as
// a key for retrieval and removal from the list
// -- Assumes that Patron objects are not duplicated in the list
//---------------------------------------------------------------------------

#ifndef PATRON
#define PATRON

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "accounthistory.h"
#include "item.h"
#include "childrensbook.h"
#include "fiction.h"
#include "periodical.h"
#include "currentbooks.h"

using namespace std;

class Patron
{
    friend ostream & operator<<(ostream &, const Patron &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Patron();

        Patron(string, string, int);
        //---------------------------------------------------------------------
        // Destructor
        ~Patron();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getFirstName() const;
        string getLastName() const;
        int getID() const;

        void setFirstName(string);
        void setLastName(string);
        void setID(int);

        void setData(string);

        //---------------------------------------------------------------------
        // Prints out user's entire history
        void printHistory();

        //---------------------------------------------------------------------
        // adds a transaction to user's history
        void addToHistory(Item*, char);

        //---------------------------------------------------------------------
        // adds a book to user's list of borrowed books
        void addToBorrowList(Item*);

        //---------------------------------------------------------------------
        // Removes a book from user's list of borrowed books
        void removeFromBorrowList(Item*);

        //---------------------------------------------------------------------
        // Checks to see if given book is in patron's list of currently 
        // borrow books
        bool inCurrentBooks(const Item&);

        //---------------------------------------------------------------------
        // prints out user's borrowed book list
        void printBorrowList();

    private:
        string first;
        string last;
        int patronID;
        AccountHistory history;
        CurrentBooks borrowlist;
};

#endif
