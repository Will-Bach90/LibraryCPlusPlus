//---------------------------------------------------------------------------
// borrowbook.h
// Derived transaction class for checking out a book
//---------------------------------------------------------------------------
// BorrowBook class Implementation and assumptions:  
//   -- Assumed Patron and Book both exist and are in system.
//   -- Transaction* create returns BorrowBook object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
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
