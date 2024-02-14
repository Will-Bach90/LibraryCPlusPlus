// William Bach

//---------------------------------------------------------------------------
// returnbook.h
// Derived transaction class for returning a checked out book
//---------------------------------------------------------------------------
// ReturnBook class Implementation and assumptions:  
//   -- Assumes Patron and Book both exist and are in system. 
//   -- Checks to make sure book is in Patron's list of currently
//      checked out books
//   -- Transaction* create returns ReturnBook object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
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
        virtual ~ReturnBook();


        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the ReturnBook class
        virtual Transaction* create() const;

        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const; 

        //---------------------------------------------------------------------
        // Virtual function to perform the transaction
        virtual void execute(const BookInventory []) const;

        //---------------------------------------------------------------------
        // Error printer
        virtual void notFoundError(Patron*, Item*) const;
};

#endif