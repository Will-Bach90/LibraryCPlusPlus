// William Bach

#include "childrensbook.h"

//-------------------------------------------------------------------------
// Default constructor
ChildrensBook::ChildrensBook()
{

    bookType = 'C';
    itemTypeName = "CHILDREN'S BOOKS";
    copies = 5;
    first = "";
    last = "";
}

//-------------------------------------------------------------------------
// Destructor
ChildrensBook::~ChildrensBook() 
{

}

//-------------------------------------------------------------------------
// Gets author's first name
string ChildrensBook::getFirstName() const
{
    return first;
}

//-------------------------------------------------------------------------
// Gets author's last name
string ChildrensBook::getLastName() const
{
    return last;
}

//-------------------------------------------------------------------------
// Sets author's first name
void ChildrensBook::setFirstName(string s)
{
    first = s;
}

//-------------------------------------------------------------------------
// Sets author's last name
void ChildrensBook::setLastName(string s)
{
    last = s;
}

//-------------------------------------------------------------------------
// Gets author's full name
string ChildrensBook::getAuthorName() const
{
    return first + " " + last;
}

//-------------------------------------------------------------------------
// creates and returns item pointer to children's book
Item* ChildrensBook::create() const
{
    return new ChildrensBook();
}

//-------------------------------------------------------------------------
// Sets childrens book data from book data file
bool ChildrensBook::setData(istream& infile)
{
    infile >> last >> ws;
    getline(infile, first, ',');
    infile >> ws;
    getline(infile, title, ',');
    infile >> year;
    // if nothing is defined, return false
    if(year==0 || first=="" || last=="" || title=="") {return false;}
    return true;
}

//-------------------------------------------------------------------------
// Sets childrens book data from transaction data file
bool ChildrensBook::setTransactionData(istream& infile)
{
    if(infile.eof()) {return false; } // if end of file, return false
    infile >> itemFormat >> ws;
    getline(infile, title, ',');
    infile >> last >> ws;
    getline(infile, first, ',');
    if(first=="" || last=="" || title=="" || itemFormat!='H') {return false;}
    return true;
}

//-------------------------------------------------------------------------
// print function for use with output overload
void ChildrensBook::print() const
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
void ChildrensBook::printHistoryFormat() const
{
    cout << setw(22) << left;
    cout << getAuthorName() << setw(27) << left;
    if(title.length()>27)
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
bool ChildrensBook::operator==(const Item& i) const
{
    // casting item class down to children's book class.
    const ChildrensBook* c = static_cast<const ChildrensBook*>(&i);
    return (this->title == c->getTitle()) && 
            (this->first == c->getFirstName()) && 
            (this->last == c->getLastName());
}

//-------------------------------------------------------------------------
// inequality operator overload
bool ChildrensBook::operator!=(const Item& i) const
{
    // casting item class down to children's book class.
    const ChildrensBook* c = static_cast<const ChildrensBook*>(&i);
    return !(this->title == c->getTitle()) || 
            !(this->first == c->getFirstName()) || 
            !(this->last == c->getLastName());
}

//-------------------------------------------------------------------------
// less than operator overload
bool ChildrensBook::operator<(const Item& i) const
{
    // casting item class down to children's book class.
    const ChildrensBook* c = static_cast<const ChildrensBook*>(&i);
    if(this->title != c->getTitle()) // first compare title
    {
        return this->title < c->getTitle();
    }
    return this->last < c->getLastName(); // then last name
}

//-------------------------------------------------------------------------
// greater than operator overload
bool ChildrensBook::operator>(const Item& i) const
{
    const ChildrensBook* c = static_cast<const ChildrensBook*>(&i);
    if(this->title != c->getTitle())
    {
        return this->title > c->getTitle();
    }
    return this->last > c->getLastName();
}