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
        ~Transaction();

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

        //---------------------------------------------------------------------
        // Pure virtual function to perform the transaction
        virtual bool execute() const = 0;

    protected:
        char transactionType;
};

#endif