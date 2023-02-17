#include "book.h"

class Fiction : public Book
{
    friend ostream& operator<<(ostream &, const Fiction &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Fiction();

        //---------------------------------------------------------------------
        // Destructor
        ~Fiction();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getFirstName() const;
        string getLastName() const;

        bool setFirstName(string);
        bool setLastName(string);

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Fiction book class 
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