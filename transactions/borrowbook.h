#ifndef BORROWBOOK
#define BORROWBOOK
#include "transaction.h"

class BorrowBook : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        BorrowBook();

        //---------------------------------------------------------------------
        // Destructor
        ~BorrowBook();

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the ReturnBook class
        virtual Transaction* create() const;

        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const; 

        //---------------------------------------------------------------------
        // Virtual function to perform the transaction
        virtual void execute() const;
};

#endif