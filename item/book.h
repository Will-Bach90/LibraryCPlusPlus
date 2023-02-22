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
        virtual char getFormat() const;

        virtual void setYear(int);
        virtual void setFormat(char);

        virtual string getLastName() const = 0;
        virtual string getFirstName() const = 0;
        virtual int getMonth() const = 0;

        //---------------------------------------------------------------------
        // For use with bookfactory class (pure virtual)
        virtual Item* create() const = 0; 
    
        //---------------------------------------------------------------------
        // sets book data from data file (pure virtual)
        virtual void setData(string) = 0;

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
        int year;
        char bookFormat;
};

#endif
