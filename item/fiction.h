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

        void setFirstName(string);
        void setLastName(string);

        int getMonth() const;

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Fiction book class 
        virtual Item* create() const; 
        
        //---------------------------------------------------------------------
        // sets book data from data file
        virtual void setData(string);

        virtual void setDataFromTransaction(string);

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