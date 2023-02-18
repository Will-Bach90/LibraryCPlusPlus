#ifndef ITEM
#define ITEM

#include <iostream>
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
        virtual string getTitle() const;
        virtual bool inStock() const;
        virtual string getType() const;
        virtual int getNumCopies() const;

        virtual void setTitle(string);
        virtual void setNumCopies(int);
        virtual void setType(string);

        //---------------------------------------------------------------------
        // Creates instance of item for use with factory class (pure virtual)
        virtual Item* create() const = 0; 
    
        //---------------------------------------------------------------------
        // sets item data from data file (pure virtual)
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
        string title;
        string itemType;
        int copies;
};

#endif