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
        // Virtual print function for use with output overload
        virtual void print() const;        
        
        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Item &) const;
        virtual bool operator!=(const Item &) const;
        virtual bool operator<(const Item &) const;
        virtual bool operator>(const Item &) const;

    protected:
        string first;
        string last;
};

#endif