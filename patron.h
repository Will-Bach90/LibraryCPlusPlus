#ifndef PATRON
#define PATRON

#include <iostream>
#include "accounthistory.h"
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
        ~Patron();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getFirstName() const;
        string getLastName() const;
        int getID() const;

        void setFirstName(string);
        void setLastName(string);
        void setID(int);

        //---------------------------------------------------------------------
        // Prints out user's entire history
        void printHistory() const;

        //---------------------------------------------------------------------
        // adds a transaction to user's history
        bool addToHistory(const Book*, const Transaction*);

        //---------------------------------------------------------------------
        // adds a book to user's list of borrowed books
        bool addToBorrowList(Book*);

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