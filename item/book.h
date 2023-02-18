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

        virtual void setYear(int);

        //---------------------------------------------------------------------
        // For use with bookfactory class (pure virtual)
        virtual Book* create() const = 0; 
    
        //---------------------------------------------------------------------
        // sets book data from data file (pure virtual)
        virtual bool setData(istream&) = 0;

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
        int year;
};

#endif