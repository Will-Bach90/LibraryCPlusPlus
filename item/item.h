// William Bach

//---------------------------------------------------------------------------
// item.h
// Parent class for all items available for use/checkout in 
// the library
//---------------------------------------------------------------------------
// Item class:  
//   includes additional features:
//   -- (Virtual) Getters/Setters for all data members
//   -- Overloaded output operator for use with virtual print method
//
// Implementation and assumptions:
//   -- Pure virtual functions to be defined in derived classes
//   -- Item class not intended to be called directly other than as a pointer
//      to a derived class.
//   -- data members include itemFormat (e.g. 'H' for hardcopy), title,
//      and number of copies in stock
//---------------------------------------------------------------------------
#ifndef ITEM
#define ITEM

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Item
{
    friend ostream & operator<<(ostream &, const Item &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Item();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Item();

        //---------------------------------------------------------------------
        // Getters/Setters
        virtual bool inStock() const; // if copies > 0
        virtual char getFormat() const;
        virtual int getNumCopies() const;
        virtual string getItemTypeName() const;

        virtual void setNumCopies(int);
        virtual void setFormat(char);

        //---------------------------------------------------------------------
        // Creates instance of item for use with factory class (pure virtual)
        virtual Item* create() const = 0; 
    
        //---------------------------------------------------------------------
        // sets item data from book data file (pure virtual)
        virtual bool setData(istream&) = 0;

        //---------------------------------------------------------------------
        // sets item data from transaction data file (pure virtual)
        virtual bool setTransactionData(istream&) = 0;

        //---------------------------------------------------------------------
        // Virtual print function for use with output overload
        virtual void print() const;

        //---------------------------------------------------------------------
        // Pure virtual print function formats item info
        // for printing patron's account history
        virtual void printHistoryFormat() const = 0;

        //---------------------------------------------------------------------
        // Pure virtual print function formats item info
        // for printing out library
        virtual void printSetUp() const = 0;

        //---------------------------------------------------------------------
        // Operator overloads (pure virtual)
        virtual bool operator==(const Item &) const = 0;
        virtual bool operator!=(const Item &) const = 0;
        virtual bool operator<(const Item &) const = 0;
        virtual bool operator>(const Item &) const = 0;

    protected:
        char itemFormat;     // format set to 'H' for hard copy
        string itemTypeName; // item name (e.g. 'Fiction Book')
        int copies;          // copies of item in stock
};

#endif