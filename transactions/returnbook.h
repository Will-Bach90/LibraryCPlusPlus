#ifndef RETURNBOOK
#define RETURNBOOK
#include "transaction.h"

class ReturnBook : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        ReturnBook();

        //---------------------------------------------------------------------
        // Destructor
        ~ReturnBook();

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the ReturnBook class
        virtual Transaction* create() const;

        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const; 

        //---------------------------------------------------------------------
        // Virtual function to perform the transaction
        virtual bool execute(BookInventory*, Book*, Patron*) const;
};

#endif