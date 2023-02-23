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
using namespace std;

class Item
{
    friend ostream & operator<<(ostream &, const Item &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Item();

        //---------------------------------------------------------------------
        // Virtual destructor: items contained in the library are assigned as
        // Item* pointing to the derived class, so Item's destructor must
        // be virtual.
        virtual ~Item();
    
        //---------------------------------------------------------------------
        // Getters/Setters
        virtual string getTitle() const;
        virtual bool inStock() const;
        virtual char getFormat() const;
        virtual int getNumCopies() const;
    
        virtual int getYear() const = 0;            // Pure virtual
        virtual string getLastName() const = 0;
        virtual string getFirstName() const = 0;
        virtual int getMonth() const = 0;

        virtual void setTitle(string) = 0;
        virtual void setNumCopies(int) = 0;
        virtual void setFormat(char) = 0;

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
        // Operator overloads (pure virtual)
        virtual bool operator==(const Item &) const = 0;
        virtual bool operator!=(const Item &) const = 0;
        virtual bool operator<(const Item &) const = 0;
        virtual bool operator>(const Item &) const = 0;

    protected:
        // Data members for use in derived classes
        char itemFormat;
        string title;
        int copies;
};

#endif
