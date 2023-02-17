#ifndef PERIODICAL
#define PERIODICAL

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
        virtual ~Periodical();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getMonth() const;

        bool setMonth() const;

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Periodical book class 
        virtual Book* create() const; 
        
        //---------------------------------------------------------------------
        // sets book data from data file
        virtual bool setData(istream&);
        
        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Book &) const;
        virtual bool operator!=(const Book &) const;
        virtual bool operator<(const Book &) const;
        virtual bool operator>(const Book &) const;

    protected:
        int month
};

#endif
