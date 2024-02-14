// William Bach

//---------------------------------------------------------------------------
// book.h
// Derived class of Item, Parent class for all books contained in the library
//---------------------------------------------------------------------------
// Book class:  
//   -- (Virtual) Getters/Setters for all data members and pure virtual
//      getters/setters for use in derived classes
//
// Implementation and assumptions:
//   -- Pure virtual functions to be defined in derived classes
//   -- Book class not intended to be called directly other than as a pointer
//      to a derived class.
//   -- Addition of publication year (int) and booktype (char) as data members
//---------------------------------------------------------------------------
#ifndef BOOK
#define BOOK

#include "item.h"

class Book : public Item
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Book();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Book();

        //---------------------------------------------------------------------
        // Getters/Setters
        virtual int getYear() const;
        virtual char getType() const;
        virtual string getTitle() const;

        virtual void setYear(int);
        virtual void setType(char);
        virtual void setTitle(string);

        //---------------------------------------------------------------------
        // For use with bookfactory class (pure virtual)
        virtual Item* create() const = 0; 
    
        //---------------------------------------------------------------------
        // sets book data from data file (pure virtual)
        virtual bool setData(istream&) = 0;

        //---------------------------------------------------------------------
        // sets book data from transaction data file (pure virtual)
        virtual bool setTransactionData(istream&) = 0;

        //---------------------------------------------------------------------
        // Virtual print function for use with output overload when printing
        // book inventory
        virtual void print() const;

        //---------------------------------------------------------------------
        // Pure virtual print function for use when printing patron's history
        virtual void printHistoryFormat() const = 0;

        //---------------------------------------------------------------------
        // virtual print function for formatting title headers
        virtual void printSetUp() const;

    protected:
        string title; // book title
        char bookType; // book type (fiction, periodical, children's book)
        int year;       // year published
};

#endif