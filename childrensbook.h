#include "book.h"

class ChildrensBook : public Book
{
    friend ostream& operator<<(ostream &, const ChildrensBook &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        ChildrensBook();

        //---------------------------------------------------------------------
        // Destructor
        ~ChildrensBook();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getFirstName() const;
        string getLastName() const;

        bool setFirstName(string);
        bool setLastName(string);

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Childrens Book class 
        virtual Book* create() const; 
        
        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Book &) const;
        virtual bool operator!=(const Book &) const;
        virtual bool operator<(const Book &) const;
        virtual bool operator>(const Book &) const;

    protected:
        string first;
        string last;
};