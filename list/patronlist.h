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
        // Virtual function to add patron to end of list
        virtual void append(Patron*);

        virtual bool retrieve(int, Patron*&);

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