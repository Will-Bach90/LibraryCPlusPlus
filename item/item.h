//---------------------------------------------------------------------------
// item.h
// Parent class for all items for use/checkout available in 
// the library
//---------------------------------------------------------------------------
// Item class:  
//   includes additional features:
//   -- (Virtual) Getters/Setters for all data members
//   -- Overloaded output operator for use with virtual 
//   -- allows for assignment of 2 arrays
//   -- size is part of the class (so no longer needs to be passed)
//   -- includes range checking, program terminates for out-of-bound subscripts
//
// Implementation and assumptions:
//   -- Pure virtual functions to be defined in derived classes
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
        virtual string getType() const;
        virtual int getNumCopies() const;
        virtual int getYear() const;
        virtual string getLastName() const;
        virtual string getFirstName() const;
        virtual int getMonth() const;

        virtual void setTitle(string);
        virtual void setNumCopies(int);
        virtual void setType(string);

        //---------------------------------------------------------------------
        // Creates instance of item for use with factory class (pure virtual)
        virtual Item* create() const = 0; 
    
        //---------------------------------------------------------------------
        // sets item data from book data file (pure virtual)
        virtual void setData(string) = 0;
    
        //---------------------------------------------------------------------
        // sets item data from transaction data file (pure virtual)
        virtual void setTransactionData(string) = 0;

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
        string firstName; 
        string lastName;  
        int year;
        int month;
        string title;
        char itemType;
        int copies;
};

#endif
