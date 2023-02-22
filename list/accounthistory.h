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
        virtual void append(Item*, char);

        //---------------------------------------------------------------------
        // Function to print out entire account history
        virtual void print() const;

        void makeEmpty();

    private:
        struct Node{
            char txnType;
            Item* book;
            Node* next;
        };
        Node* head;
};

#endif