// William Bach

#include "patron.h"
//---------------------------------------------------------------------
// Default Constructor
Patron::Patron()
{
    patronID = -1;
}

//---------------------------------------------------------------------
// Destructor
Patron::~Patron() {}

//---------------------------------------------------------------------
// Get patron first name
string Patron::getFirstName() const
{
    return this->first;
}

//---------------------------------------------------------------------
// Get patron last name
string Patron::getLastName() const
{
    return this->last;
}

//---------------------------------------------------------------------
// Get patron ID
int Patron::getID() const
{
    return this->patronID;
}

//---------------------------------------------------------------------
// Get patron full name
string Patron::getFullName() const
{
    string temp = this->first + " " + this->last;
    return temp;
}

//---------------------------------------------------------------------
// Set patron first name
void Patron::setFirstName(string f)
{
    first = f;
}

//---------------------------------------------------------------------
// Set patron last name
void Patron::setLastName(string l)
{
    last = l;
}

//---------------------------------------------------------------------
// Set patron ID
void Patron::setID(int id)
{
    patronID = id;
}

//---------------------------------------------------------------------
// Prints out user's entire history
void Patron::printHistory()
{
    string linebreak(75, '*');
    cout << endl;
    cout << linebreak << endl;
    cout << getFirstName() << " " << getLastName();
    cout << "'s (ID: " << getID() << ") account history: " << endl;
    history.print();
    cout << linebreak << endl;
    cout << endl;
}

//---------------------------------------------------------------------
// Sets Patron's info from the patron data file
bool Patron::setData(istream& infile)
{
    string temp;
    if(infile.eof()) {return false; } // if end of file, return
    getline(infile, temp);
    istringstream ss(temp);
    ss >> patronID >> last >> first;

    // if no data set or invalid data, return
    if(patronID<=0 || patronID>9999 || last=="" || first=="")
    {
        return false;
    }
    return true;
}

//---------------------------------------------------------------------
// adds a transaction to user's history
void Patron::addToHistory(Item* b, string txn)
{
    history.append(b, txn);
}

//---------------------------------------------------------------------
// adds a book to user's list of borrowed books
void Patron::addToBorrowList(Item* b)
{
    borrowlist.append(b);
    addToHistory(b, "CheckOut");
}

//---------------------------------------------------------------------
// removes a book to user's list of borrowed books, returns true if
// successful
bool Patron::removeFromBorrowList(Item* b)
{
    if(borrowlist.remove(b))
    {
        addToHistory(b, "Return"); // if successfully removed, add to history
        return true;
    }
    const Book* book = static_cast<const Book*>(*&b);
    cout << "ERROR: " << getFirstName() << " ";
    cout << getLastName() << " tried to return ";
    cout << book->getTitle() << " which was not checked out.";
    cout << endl;
    return false;
}

//---------------------------------------------------------------------
// prints out user's borrowed book list
void Patron::printBorrowList()
{
    borrowlist.print();
}

//---------------------------------------------------------------------
// output overload
ostream & operator<<(ostream & output, const Patron &p)
{
    output << setw(12) << left << p.getID() << setw(25);
    output << left << p.getFullName() << endl;
    return output;
}