// William Bach

//---------------------------------------------------------------------------
// patronlist.h
// Derived list class for saving patrons in a linked list. 
//---------------------------------------------------------------------------
// PatronList class Implementation and assumptions:  
//   -- PatronClass used for collision handling in PatronHashMap class
//   -- Currently only allows append and retrieve functions. Patron's not
//      assumed to be removed from library database.
//---------------------------------------------------------------------------
#ifndef PATRON_LIST
#define PATRON_LIST

#include "list.h"
#include "patron.h"

class PatronList : public List
{
    public:

        PatronList();
        virtual ~PatronList();

        //---------------------------------------------------------------------
        // Virtual function to see if list is empty
        virtual bool isEmpty() const;

        //---------------------------------------------------------------------
        // Function to add patron to end of list
        virtual void append(Patron*);

        //---------------------------------------------------------------------
        // Function to find patron in list via id, returns true if found with 
        // pointer to patron
        virtual bool retrieve(int, Patron*&);

        //---------------------------------------------------------------------
        // Deletes entire list.
        void makeEmpty();

        //---------------------------------------------------------------------
        // Function to print out entire list of patrons
        virtual void print() const;

    private:
        struct Node{
            Patron* data;
            Node* next;
        };
        Node* head;
};

#endif