// William Bach

//---------------------------------------------------------------------------
// patron.h
// Class representing a patron registered with the library
//---------------------------------------------------------------------------
// Patron class implementation and assumptions:
//      -- Maintains history of transactions and list of borrowed books
//      -- Performs methods to history such as adding and printing a 
//         Patron's history, transactions and also adding and removing book 
//         items from the borrowed list. 
//      -- Assumes Item class and its derived classes have been properly 
//         implemented
//      -- Assumes list class and its derived classes have been properly 
//         implemented.
//---------------------------------------------------------------------------
#ifndef PATRON
#define PATRON

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "accounthistory.h"
#include "item.h"
#include "book.h"
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

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Patron();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getFirstName() const;
        string getLastName() const;
        int getID() const;
        string getFullName() const;

        void setFirstName(string);
        void setLastName(string);
        void setID(int);

        bool setData(istream&);

        //---------------------------------------------------------------------
        // Prints out user's entire history
        void printHistory();

        //---------------------------------------------------------------------
        // adds a transaction to user's history
        void addToHistory(Item*, string);

        //---------------------------------------------------------------------
        // adds a book to user's list of borrowed books
        void addToBorrowList(Item*);

        //---------------------------------------------------------------------
        // Removes a book from user's list of borrowed books
        bool removeFromBorrowList(Item*);

        //---------------------------------------------------------------------
        // Checks to see if given book is in patron's list of currently 
        // borrow books
        bool inCurrentBooks(const Item&);

        //---------------------------------------------------------------------
        // prints out user's borrowed book list
        void printBorrowList();

    private:
        string first; // patron first names
        string last;  // last name
        int patronID;  // 4 digit ID
        AccountHistory history;  // linked list of patron history
        CurrentBooks borrowlist; // linked list of currently borrowed books
};

#endif