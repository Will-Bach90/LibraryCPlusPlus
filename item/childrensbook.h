// William Bach

//---------------------------------------------------------------------------
// childrensbook.h
// Derived Book class for Children's Books
//---------------------------------------------------------------------------
// ChildrensBook class Implementation and assumptions:  
//   -- Item* create() function returns new ChildrensBook object for use
//      in factory class
//   -- setData function sets all data members for Children's book from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of author first and last name data members
//   -- Comparison overloads reflect sorting criteria of ChildrensBook 
//      class: sorted by title, then author. No other data used for sorting, 
//      and criteria uniquely identifies each childrens book.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//---------------------------------------------------------------------------
#ifndef CHILDRENSBOOK
#define CHILDRENSBOOK

#include "book.h"

class ChildrensBook : public Book
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        ChildrensBook();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~ChildrensBook();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getFirstName() const;
        string getLastName() const;
        string getAuthorName() const;

        void setFirstName(string);
        void setLastName(string);

        //---------------------------------------------------------------------
        // For use with bookfactory class - creates and returns
        // an instance of the ChildrensBook class 
        virtual Item* create() const; 
        
        //---------------------------------------------------------------------
        // sets book data from data file
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
        virtual bool operator==(const Item&) const;
        virtual bool operator!=(const Item&) const;
        virtual bool operator<(const Item&) const;
        virtual bool operator>(const Item&) const;

    protected:
        string first; // author first name
        string last;  // author last name
};

#endif