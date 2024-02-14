// William Bach

#include "periodical.h"

//---------------------------------------------------------------------
// Default constructor
Periodical::Periodical()
{
    month = 0;
    bookType = 'P';
    copies = 1;
    itemTypeName = "PERIODICALS";
}

//---------------------------------------------------------------------
// Destructor
Periodical::~Periodical() 
{

}

//---------------------------------------------------------------------
// get month as int
int Periodical::getMonth() const
{
    return month;
}

//-------------------------------------------------------------------------
// creates and returns item pointer to periodical book
Item* Periodical::create() const
{
    return new Periodical();
}

//-------------------------------------------------------------------------
// sets periodical data from book data file
bool Periodical::setData(istream& infile)
{
    infile >> ws;
    getline(infile, title, ',');
    infile >> month;
    infile >> year;
    if(year==0 || month==0 || title=="") {return false;}
    return true;
}

//-------------------------------------------------------------------------
// sets periodical data from transaction data file
bool Periodical::setTransactionData(istream& infile)
{
    infile >> itemFormat >> year >> month >> ws;
    getline(infile, title, ',');
    if(year==0 || month==0 || title=="" || itemFormat!='H') 
    {
        return false;
    }
    return true;
}

//-------------------------------------------------------------------------
// print function for use with output overload
void Periodical::print() const
{
    cout << setw(8) << left << copies << setw(39) << left;
    cout << title << setw(6) << left << month;
    cout << setw(11) << right << year;

}

//-------------------------------------------------------------------------
// prints out headers for displaying all books in library
void Periodical::printSetUp() const
{
    cout << setw(8) << left << "AVAIL" << setw(39) << left;
    cout << "TITLE" << setw(6) << left << "MONTH";
    cout << setw(11) << right << "YEAR";
}

//-------------------------------------------------------------------------
// prints out periodicals for use in printing patron's history
void Periodical::printHistoryFormat() const
{
    cout << setw(22) << left;
    cout << " " << setw(27) << left;
    if(title.length()>27)
    {
        cout << title.substr(0, 27) + "...";
        cout << setw(4) << right << month << "/" << year;
    }
    else
    {
        cout << title;
        cout << setw(6) << right << month << "/" << year;
    }
}

//-------------------------------------------------------------------------
// equality overload
bool Periodical::operator==(const Item &i) const
{
    // casting item class down to periodical book class.
    const Periodical* p = static_cast<const Periodical*>(&i);
    return (this->title == p->getTitle()) && 
            (this->year == p->getYear()) && 
            (this->month == p->getMonth());
}

//-------------------------------------------------------------------------
// inequality overload
bool Periodical::operator!=(const Item &i) const
{
    // casting item class down to periodical book class.
    const Periodical* p = static_cast<const Periodical*>(&i);
    return !(this->title == p->getTitle()) || 
        !(this->year == p->getYear()) || 
        !(this->month == p->getMonth());
}

//-------------------------------------------------------------------------
// less than overload
bool Periodical::operator<(const Item &i) const
{
    const Periodical* p = static_cast<const Periodical*>(&i);
    if(this->year != p->getYear()) // if year is not the same
    {
        return this->year < p->getYear(); // compare years
    }
    else 
    {
        if(this->month != p->getMonth()) // else if month is not the same
        {
            return this->month < p->getMonth(); // compare months
        }
        else
        {
            return this->title < p->getTitle(); // else compre titles
        }
    }
}

//-------------------------------------------------------------------------
// greater than overload
bool Periodical::operator>(const Item &i) const
{
    // casting item class down to periodical book class.
    const Periodical* p = static_cast<const Periodical*>(&i);
    if(this->year != p->getYear())
    {
        return this->year > p->getYear();
    }
    else 
    {
        if(this->month != p->getMonth())
        {
            return this->month > p->getMonth();
        }
        else
        {
            return this->title > p->getTitle();
        }
    }
}