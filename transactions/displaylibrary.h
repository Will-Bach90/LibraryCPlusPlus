// William Bach

//---------------------------------------------------------------------------
// displaylibrary.h
// Derived transaction class for displaying all books in the library
//---------------------------------------------------------------------------
// DisplayLibrary class Implementation and assumptions:  
//   -- Assumed hash table of binary trees containing different book types is 
//      implemented and exists.
//   -- Pointer to hash table of binary trees passed as parameter in 
//      setLibrary method.
//   -- Transaction* create returns DisplayLibrary object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
#ifndef DISPLAY_LIBRARY
#define DISPLAY_LIBRARY
#include "transaction.h"

class DisplayLibrary : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        DisplayLibrary();

        //---------------------------------------------------------------------
        // Destructor
        ~DisplayLibrary();

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the DisplayLibrary class
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