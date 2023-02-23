//---------------------------------------------------------------------------
// transaction.h
// Parent transaction class for main transaction types: checkout, return, 
// and display history
//---------------------------------------------------------------------------
// Transaction class Implementation and assumptions:  
//   -- Transaction class not intended to be called directly other than as
//      a pointer to derived classes.
//   -- Data members include pointer to Item object upon which it is acting, 
//      pointer to patron who is taking part in transaction, a bool type for 
//      confirming whether book data member is in library, and char for 
//      transaction type ('C' for checkout, 'R' for return, 'H' for 
//      displaying history)
//   -- Transaction* create to be implemented in derived classes, returns 
//      pointer to transaction object.
//---------------------------------------------------------------------------
#ifndef TRANSACTION
#define TRANSACTION

#include <iostream>
#include "item.h"
#include "patron.h"
#include "bookinventory.h"
using namespace std;

class Transaction
{
    friend ostream & operator<<(ostream &, const Transaction &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Transaction();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Transaction();

        //---------------------------------------------------------------------
        // Getters/Setters
        virtual char getTransactionType() const;

        virtual void setTransactionType(char);

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the transaction class
        virtual Transaction* create() const = 0;

        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const; 

        virtual void setData(Patron*, Item*, bool);

        //---------------------------------------------------------------------
        // Pure virtual function to perform the transaction
        virtual void execute() const = 0;

    protected:
        char transactionType;
        Patron* patron;
        Item* book;
        bool inTree;
};

#endif
