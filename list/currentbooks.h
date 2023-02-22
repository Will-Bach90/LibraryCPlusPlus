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

        virtual void makeEmpty();

    private:
        struct Node{
            Item* data;
            Node* next;
        };
        Node* head;
};

#endif