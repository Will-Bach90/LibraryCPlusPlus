// William Bach

#include "displaylibrary.h"

//---------------------------------------------------------------------
// Default constructor
DisplayLibrary::DisplayLibrary()
{
    transactionType = 'D';
    txnName = "Total Inventory";
}

//---------------------------------------------------------------------
// Destructor
DisplayLibrary::~DisplayLibrary()
{

}

//---------------------------------------------------------------------
// For use with transactionfactory class - creates and returns an 
// instance of the DisplayLibrary class
Transaction* DisplayLibrary::create() const
{
    return new DisplayLibrary();
}

//---------------------------------------------------------------------
// Virtual print method for use with output overload
void DisplayLibrary::print() const
{
    cout << " " << transactionType << " " << endl;
}

//---------------------------------------------------------------------
// Virtual function to perform the transaction
void DisplayLibrary::execute(const BookInventory lib[]) const
{
    if(lib!=nullptr)
    {
        string linebreak(75, '=');
        string linebreak2(64, '-');
        string spaces(24, ' ');
        cout << linebreak << endl;
        cout << spaces << "+--------------+" << endl;
        cout << spaces << "|BOOK INVENTORY|" << endl;
        cout << spaces << "+--------------+" << endl;
        cout << linebreak2 << endl;
        for(int i = 0; i < 36; i++)
        {
            if(!lib[i].isEmpty())
            {   
                lib[i].inOrderPrint();
            }
        }
        cout << linebreak << endl;
        cout << endl;
    }
}

//---------------------------------------------------------------------
// Placeholder generic error printing function
void DisplayLibrary::notFoundError(Patron* p, Item* b) const
{
    return;
}