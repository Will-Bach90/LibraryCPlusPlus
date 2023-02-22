#ifndef DISPLAY_LIBRARY
#define DISPLAY_LIBRARY
#include "transaction.h"

class DisplayHistory : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        DisplayHistory();

        //---------------------------------------------------------------------
        // Destructor
        ~DisplayHistory();

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