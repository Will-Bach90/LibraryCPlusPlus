// William Bach

#include "item.h"

//---------------------------------------------------------------------------
// Default constructor
Item::Item()
{
    itemFormat = 'H';
    itemTypeName = "Generic Item";
    copies = 0;
}

//---------------------------------------------------------------------------
// Destructor
Item::~Item() 
{

}

//---------------------------------------------------------------------------
// Get item name (e.g. 'Fiction Book')
string Item::getItemTypeName() const
{
    return itemTypeName;
}

//---------------------------------------------------------------------------
// Checks if item is in stock, returns true if copies > 0
bool Item::inStock() const
{
    return (copies > 0);
}

//---------------------------------------------------------------------------
// Gets item format ('H' for hard copy)
char Item::getFormat() const
{
    return itemFormat;
}

//---------------------------------------------------------------------------
// Returns number of item copies as int
int Item::getNumCopies() const
{
    return copies;
}

//---------------------------------------------------------------------------
// Sets item format
void Item::setFormat(char c)
{
    itemFormat = c;
}

//---------------------------------------------------------------------------
// Sets number of copies
void Item::setNumCopies(int n)
{
    copies = n;
}

//---------------------------------------------------------------------------
// Print function for use with output overload
void Item::print() const
{
    cout << "Base Item Class Print";
}

//---------------------------------------------------------------------------
// Output overload
ostream& operator<<(ostream & output, const Item & b)
{
    b.print();
    output << endl;
    return output;
}