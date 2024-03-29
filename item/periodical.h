// William Bach

//---------------------------------------------------------------------------
// periodical.h
// Derived Book class for Periodicals
//---------------------------------------------------------------------------
// Periodical class Implementation and assumptions:  
//   -- Item* create() function returns new Periodical object for use
//      in factory class
//   -- setData function sets all data members for periodical from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of month data member
//   -- Comparison overloads reflect sorting criteria of periodical 
//      class: sorted by year, then month, then title. No other data used 
//      for sorting, and criteria uniquely identifies each periodical.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//---------------------------------------------------------------------------
#ifndef PERIODICAL
#define PERIODICAL

#include "book.h"

class Periodical : public Book
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Periodical();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Periodical();

        //---------------------------------------------------------------------
        // Getters/Setters
        int getMonth() const;

        void setMonth(int);

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Periodical book class 
        virtual Item* create() const; 
        
        //---------------------------------------------------------------------
        // sets book data from book data file
        virtual bool setData(istream&);

        //---------------------------------------------------------------------
        // sets book data from transaction data file
        virtual bool setTransactionData(istream&);

        //---------------------------------------------------------------------
        // Virtual print function for use with output overload
        virtual void print() const; 

        //---------------------------------------------------------------------
        // Print function for formatting title headers
        virtual void printSetUp() const;

        //---------------------------------------------------------------------
        // Print function for use when printing patron's history
        virtual void printHistoryFormat() const;
        
        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Item &) const;
        virtual bool operator!=(const Item &) const;
        virtual bool operator<(const Item &) const;
        virtual bool operator>(const Item &) const;

    protected:
        int month;
};

#endif