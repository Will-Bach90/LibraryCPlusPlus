// William Bach

#include "fiction.h"

//-------------------------------------------------------------------------
// Default constructor
Fiction::Fiction()
{

    bookType = 'F';
    itemTypeName = "FICTION BOOKS";
    copies = 5;
}

//-------------------------------------------------------------------------
// Destructor
Fiction::~Fiction() 
{

}

//-------------------------------------------------------------------------
// Returns author's first name as string
string Fiction::getFirstName() const
{
    return first;
}

//-------------------------------------------------------------------------
// Returns author's last name as string
string Fiction::getLastName() const
{
    return last;
}

//-------------------------------------------------------------------------
// Sets author's first name
void Fiction::setFirstName(string s)
{
    first = s;
}

//-------------------------------------------------------------------------
// Sets author's last name
void Fiction::setLastName(string s)
{
    last = s;
}

//-------------------------------------------------------------------------
// Returns author's full name
string Fiction::getAuthorName() const
{
    return first + " " + last;
}

//-------------------------------------------------------------------------
// creates and returns item pointer to fiction book
Item* Fiction::create() const
{
    return new Fiction();
}

//-------------------------------------------------------------------------
// Sets fiction book data from book data file
bool Fiction::setData(istream& infile)
{
    infile >> last >> ws;
    getline(infile, first, ',');
    infile >> ws;
    getline(infile, title, ',');
    infile >> year;
    if(year==0 || first=="" || last=="" || title =="") {return false;}
    return true;
}

//-------------------------------------------------------------------------
// Sets fiction book data from transaction data file
bool Fiction::setTransactionData(istream& infile)
{
    if(infile.eof()) {return false; } // if end of file, return false
    infile >> itemFormat >> last >> ws;
    getline(infile, first, ',');
    infile >> ws;
    getline(infile, title, ',');
    if(first=="" || last=="" || title=="" || itemFormat!='H') 
    {
        return false; // if no data members had been set, return false
    }
    return true;
}

//-------------------------------------------------------------------------
// print function for use with output overload
void Fiction::print() const
{
    cout << setw(8) << left << copies << setw(25) << left;
    cout << getAuthorName() << setw(20) << left;
    if(title.length()>19) // truncates title if too long
    {
        cout << title.substr(0, 19) + "...";
        cout << setw(9) << right << year;
    }
    else
    {
        cout << title;
        cout << setw(11) << right << year;
    }

}

//-------------------------------------------------------------------------
// print function for formatting book info
// in printing patron's account history
void Fiction::printHistoryFormat() const
{
    cout << setw(22) << left;
    cout << getAuthorName() << setw(27) << left;
    if(title.length()>27) // truncates title if too long
    {
        cout << title.substr(0, 27) + "...";
        cout << setw(8) << right << year;
    }
    else
    {
        cout << title;
        cout << setw(11) << right << year;
    }
}

//-------------------------------------------------------------------------
// equality operator overload
bool Fiction::operator==(const Item &i) const
{
    // casting item class down to fiction book class.
    const Fiction* f = static_cast<const Fiction*>(&i);
    return (this->title == f->getTitle()) && 
            (this->first == f->getFirstName()) && 
            (this->last == f->getLastName());
}

//-------------------------------------------------------------------------
// inequality operator overload
bool Fiction::operator!=(const Item &i) const
{
    // casting item class down to fiction book class.
    const Fiction* f = static_cast<const Fiction*>(&i);
    return !(this->title == f->getTitle()) || 
            !(this->first == f->getFirstName()) || 
            !(this->last == f->getLastName());
}

//-------------------------------------------------------------------------
// less than operator overload
bool Fiction::operator<(const Item &i) const
{
    // casting item class down to fiction book class.
    const Fiction* f = static_cast<const Fiction*>(&i);
    if(this->last != f->getLastName()) // first compare last names
    {
        return this->last < f->getLastName();
    }
    else
    {
        if(this->first != f->getFirstName()) // then first names
        {
            return this->first < f->getFirstName();
        }
        return this->title < f->getTitle(); // then titles
    }
}

//-------------------------------------------------------------------------
// greater than operator overload
bool Fiction::operator>(const Item &i) const
{
    const Fiction* f = static_cast<const Fiction*>(&i);
    if(this->last != f->getLastName())
    {
        return this->last > f->getLastName();
    }
    else
    {
        if(this->first != f->getFirstName())
        {
            return this->first > f->getFirstName();
        }
        return this->title > f->getTitle();
    }
}