// William Bach

//---------------------------------------------------------------------------
// fiction.h
// Derived Book class for Fiction books
//---------------------------------------------------------------------------
// Fiction class Implementation and assumptions:  
//   -- Item* create() function returns new Fiction object for use
//      in factory class
//   -- setData function sets all data members for fiction book from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of author first and last name data members
//   -- Comparison overloads reflect sorting criteria of Fiction 
//      class: sorted by author, then title. No other data used for sorting, 
//      and criteria uniquely identifies each fiction book.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//---------------------------------------------------------------------------
#ifndef FICTION
#define FICTION

#include "book.h"

class Fiction : public Book
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Fiction();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Fiction();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getFirstName() const;
        string getLastName() const;
        string getAuthorName() const; // gets full author name

        void setFirstName(string);
        void setLastName(string);

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Fiction book class 
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
        // Virtual print function for formatting book info
        // for use in printing patron's history
        virtual void printHistoryFormat() const;
        
        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Item &) const;
        virtual bool operator!=(const Item &) const;
        virtual bool operator<(const Item &) const;
        virtual bool operator>(const Item &) const;

    protected:
        string first; // author first name
        string last;  // author last name
};

#endif