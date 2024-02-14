// William Bach

#include "patronhashmap.h"

//---------------------------------------------------------------------
// Default Constructor
PatronHashMap::PatronHashMap()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = new PatronList();
    }
}

//---------------------------------------------------------------------
// Destructor
PatronHashMap::~PatronHashMap()
{
    this->makeEmpty();
}

//---------------------------------------------------------------------
// Deletes entire hash table
void PatronHashMap::makeEmpty()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        delete table[i];
    }
}

//---------------------------------------------------------------------
// Private hash function
int PatronHashMap::hash(int k) const
{
    return k%TABLE_SIZE;
}

//---------------------------------------------------------------------
// Inserts patron into hash table
void PatronHashMap::insert(Patron* p)
{
    int index = hash(p->getID()); // find index from hash function
    table[index]->append(p); // insert into table
}

//---------------------------------------------------------------------
// finds patron in hash table from their id, returns true if found
bool PatronHashMap::retrieve(int id, Patron*& rp)
{
    int index = hash(id);
    return table[index]->retrieve(id, rp);
}

//---------------------------------------------------------------------
// Prints out entire hash table
void PatronHashMap::print()
{
    string linebreak(75, '=');
    string spaces(24, ' ');
    cout << linebreak << endl;
    cout << spaces << "+---------------+" << endl;
    cout << spaces << "|LIBRARY PATRONS|" << endl;
    cout << spaces << "+---------------+" << endl;
    cout << setw(12) << left << "ID" << setw(25) << left << "NAME" << endl;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(!table[i]->isEmpty()) // if slot is not empty
        {
            table[i]->print();  // print out linked list 
        }
    }
    cout << linebreak << endl;
    cout << endl;
}