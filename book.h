#include <iostream>
using namespace std;

class Book
{
    friend ostream & operator<<(ostream &, const Book &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Book();

        //---------------------------------------------------------------------
        // Destructor
        ~Book();

        //---------------------------------------------------------------------
        // Getters/Setters
        virtual int getYear() const;
        virtual string getTitle() const;
        virtual bool inStock() const;
        virtual string getType() const;
        virtual int getNumberVolumes() const;

        virtual void setYear(int);
        virtual void setTitle(string);
        virtual void setNumberVolumes(int);

        //---------------------------------------------------------------------
        // For use with bookfactory class
        virtual Book* create() const = 0; 

        //---------------------------------------------------------------------
        // Operator overloads (pure virtual)
        virtual bool operator==(const Book &) const = 0;
        virtual bool operator!=(const Book &) const = 0;
        virtual bool operator<(const Book &) const = 0;
        virtual bool operator>(const Book &) const = 0;

    protected:
        int year;
        string title;
        bool inStock;
        string bookType;
        int numVolumes;
};