#ifndef PATRON_LIST
#define PATRON_LIST

#include "list.h"

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
        virtual bool append(Patron*);

        //---------------------------------------------------------------------
        // Function to get patron object from node
        Patron* getData();

        //---------------------------------------------------------------------
        // Function to set patron object in node
        virtual void setData(Patron*);

        //---------------------------------------------------------------------
        // Function to print out entire list of patrons
        virtual void print();

    private:
        struct Node{
            Patron* data;
            Node* next;
        };
        Node* head;
};

#endif