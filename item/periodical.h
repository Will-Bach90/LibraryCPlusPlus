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
        // sets book data from data file
        virtual bool setData(istream&);

        //---------------------------------------------------------------------
        // Virtual print function for use with output overload
        virtual void print() const; 
        
        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Item &) const;
        virtual bool operator!=(const Item &) const;
        virtual bool operator<(const Item &) const;
        virtual bool operator>(const Item &) const;

    protected:
        int month
};

#endif