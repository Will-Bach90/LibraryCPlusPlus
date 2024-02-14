// William Bach

// Derived Factory class for returning transaction objects
//---------------------------------------------------------------------------
// Transactionfactory class Implementation and assumptions:  
//   -- Item* createObject(char) function returns new Transaction object, 
//      where the type of transaction is determined by input char 
//      ('C' for checkout, 'R' for return, 'H' for displaying a patron's
//      history).
//   -- objFactory data member is array of Transaction*, where each each 
//      index maps to a particular transaction type. 
//   -- Hashing function used to map a given char value to index of array
//   -- Invalid input chars return null pointers
//---------------------------------------------------------------------------
#ifndef TRANSACTION_FACTORY
#define TRANSACTION_FACTORY

#include "factory.h"
#include "transaction.h"
#include "borrowbook.h"
#include "returnbook.h"
#include "displayhistory.h"
#include "displaylibrary.h"


class TransactionFactory : public Factory
{
    public:
        //-------------------------------------------------------------------
        // Default Constructor
        TransactionFactory();

        //-------------------------------------------------------------------
        // Destructor
        virtual ~TransactionFactory();

        //-------------------------------------------------------------------
        // Returns Transaction pointer to derived class
        Transaction* createObject(char) const;
    protected:
        //-------------------------------------------------------------------
        // Array that holds transaction pointers to different derived classes
        Transaction* objFactory[CHARACTERS]; 

};

#endif