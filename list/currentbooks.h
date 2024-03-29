// William Bach

//---------------------------------------------------------------------------
// currentbooks.h
// Derived list class for saving all of patron's checked out books in linked
// list
//---------------------------------------------------------------------------
// CurrentBooks class Implementation and assumptions:  
//   -- Used as data member in Patron class
//   -- Allows append, retrieve, and remove of given books from list
//   -- Remove does not delete Node data member, only node itself.
//---------------------------------------------------------------------------
#ifndef CURRENT_BOOKS
#define CURRENT_BOOKS

#include "list.h"

class CurrentBooks : public List
{
    public:
        CurrentBooks();
        virtual ~CurrentBooks();

        //---------------------------------------------------------------------
        // Virtual function to see if list is empty
        virtual bool isEmpty() const;

        //---------------------------------------------------------------------
        // Virtual function to add book to end of list
        virtual void append(Item*);

        //---------------------------------------------------------------------
        // Virtual function to remove book from list
        virtual bool remove(Item*);

        //---------------------------------------------------------------------
        // Function to print out entire list of books currently borrowed
        virtual void print() const;

        //---------------------------------------------------------------------
        // Function to delete the entire list
        virtual void makeEmpty();

    private:
        struct Node{
            Item* data; // Item pointer represents node data
            Node* next; // next node pointer
        };
        Node* head; // head of the linked list
};

#endif