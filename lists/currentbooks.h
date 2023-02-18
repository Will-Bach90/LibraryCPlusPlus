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
        virtual bool append(Book*);

        //---------------------------------------------------------------------
        // Virtual function to remove book from list
        virtual bool remove(Book*);

        //---------------------------------------------------------------------
        // Function to get book object from node
        Book* getData();

        //---------------------------------------------------------------------
        // Function to set book object in node
        virtual void setData(Book*);

        //---------------------------------------------------------------------
        // Function to print out entire list of books currently borrowed
        virtual void print();

    private:
        struct Node{
            Book* data;
            Node* next;
        };
        Node* head;
};

#endif