#include "book.h"

class Periodical : public Book
{
    friend ostream& operator<<(ostream &, const Periodical &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Periodical();

        //---------------------------------------------------------------------
        // Destructor
        ~Periodical();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getMonth() const;

        bool setMonth() const;

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Periodical book class 
        virtual Book* create() const; 
        
        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Book &) const;
        virtual bool operator!=(const Book &) const;
        virtual bool operator<(const Book &) const;
        virtual bool operator>(const Book &) const;

    protected:
        int month
};