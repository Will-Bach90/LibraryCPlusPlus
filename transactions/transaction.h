// William Bach

//---------------------------------------------------------------------------
// transaction.h
// Parent transaction class for main transaction types: checkout, return, 
// display history, and display library
//---------------------------------------------------------------------------
// Transaction class Implementation and assumptions:  
//   -- Transaction class not intended to be called directly other than as
//      a pointer to derived classes.
//   -- Data members include pointer to Item object upon which it is acting, 
//      pointer to patron who is taking part in transaction, a bool type for 
//      confirming whether book data member is in library, and char for 
//      transaction type ('C' for checkout, 'R' for return, 'H' for 
//      displaying history, 'D' for displaying library)
//   -- Transaction* create to be implemented in derived classes, returns 
//      pointer to transaction object.
//---------------------------------------------------------------------------
#ifndef TRANSACTION
#define TRANSACTION

#include <iostream>
#include "bookinventory.h"
#include "patron.h"
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
        virtual char getTransactionType() const; // e.g. 'C' for checkout
        virtual string getTransactionName() const;

        virtual void setTransactionType(char);

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the transaction class
        virtual Transaction* create() const = 0;

        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const; 

        //---------------------------------------------------------------------
        // Method for setting patron and item data members
        virtual void setData(Patron*, Item*);

        //---------------------------------------------------------------------
        // Pure virtual function to perform the transaction
        virtual void execute(const BookInventory []) const = 0;

        //---------------------------------------------------------------------
        // Pure virtual function to print out errors
        virtual void notFoundError(Patron*, Item*) const = 0;

    protected:
        char transactionType; // 'C' for checkout, 'R' for return
        string txnName; // e.g. Checkout or Return
        Patron* patron;
        Item* book;
};

#endif