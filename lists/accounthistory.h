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
        virtual bool append(Transaction*, Book*);

        //---------------------------------------------------------------------
        // Function to get transaction object from node
        Transaction* getTransaction();

        //---------------------------------------------------------------------
        // Function to get book object from node
        Book* getBook();

        //---------------------------------------------------------------------
        // Function to set transaction object in node
        virtual void setData(Transaction*, Book*);

        //---------------------------------------------------------------------
        // Function to print out entire account history
        virtual void print();

    private:
        struct Node{
            Transaction* txn;
            Book* book
            Node* next;
        };
        Node* head;
};

#endif