// William Bach

//---------------------------------------------------------------------------
// accounthistory.h
// Derived list class for saving all of patron's history in linked list
//---------------------------------------------------------------------------
// AccountHistory class Implementation and assumptions:  
//   -- Used as data member in Patron class
//   -- Allows append only
//   -- Transaction type stored as string, book as Item*
//
//---------------------------------------------------------------------------
#ifndef ACCOUNT_HISTORY
#define ACCOUNT_HISTORY

#include "list.h"

class AccountHistory : public List
{
    public:
        //---------------------------------------------------------------------
        // Default constructor
        AccountHistory();

        //---------------------------------------------------------------------
        // Default constructor
        virtual ~AccountHistory();

        //---------------------------------------------------------------------
        // Virtual function to see if list is empty
        virtual bool isEmpty() const;

        //---------------------------------------------------------------------
        // Virtual function to add transaction to end of list
        virtual void append(Item*, string);

        //---------------------------------------------------------------------
        // Function to print out entire account history
        virtual void print() const;

        //---------------------------------------------------------------------
        // Function to empty out the list for use in destructor
        void makeEmpty();

    private:
        struct Node{
            string txnType; // Transaction type
            Item* book;     // Pointer to item being stored in history
            Node* next;     // Next node pointer
        };
        Node* head;         // Head of linked list
};

#endif