// William Bach

#include "book.h"

//---------------------------------------------------------------------
// Default constructor
Book::Book()
{
    year = 0;
}

//---------------------------------------------------------------------
// Destructor
Book::~Book() 
{

}

//---------------------------------------------------------------------
// Get year function
int Book::getYear() const
{
    return year;
}

//---------------------------------------------------------------------
// Get type (fiction, periodical, or children's book via char)
char Book::getType() const
{
    return bookType;
}

//---------------------------------------------------------------------
// Get title
string Book::getTitle() const
{
    return title;
}

//---------------------------------------------------------------------
// Set year
void Book::setYear(int yr)
{
    year = yr;
}

//---------------------------------------------------------------------
// Set book type
void Book::setType(char c)
{
    bookType = c;
}

//---------------------------------------------------------------------
// Set title
void Book::setTitle(string t)
{
    title = t;
}

//---------------------------------------------------------------------
// Base print function
void Book::print() const
{
    cout << "This is a base Book Class print";
}

//---------------------------------------------------------------------
// Print formatting for book inventory
void Book::printSetUp() const
{

    cout << setw(8) << left << "AVAIL" << setw(25) << left;
    cout << "AUTHOR" << setw(20) << left << "TITLE";
    cout << setw(11) << right << "YEAR";
}