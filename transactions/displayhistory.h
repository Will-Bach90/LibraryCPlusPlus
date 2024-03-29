// William Bach

//---------------------------------------------------------------------------
// displayhistory.h
// Derived transaction class for displaying a patron's account history
//---------------------------------------------------------------------------
// DisplayHistory class Implementation and assumptions:  
//   -- Assumed Patron exists and is in the system.
//   -- Item* data member set to nullptr.
//   -- Transaction* create returns DisplayHistory object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
#ifndef DISPLAY_HISTORY
#define DISPLAY_HISTORY
#include "transaction.h"

class DisplayHistory : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        DisplayHistory();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~DisplayHistory();

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the DisplayHistory class
        virtual Transaction* create() const;

        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const; 

        //---------------------------------------------------------------------
        // Virtual function to perform the transaction
        virtual void execute(const BookInventory []) const;

        //---------------------------------------------------------------------
        // Placeholder error printing function
        virtual void notFoundError(Patron*, Item*) const;
};

#endif