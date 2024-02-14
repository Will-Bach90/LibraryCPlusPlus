// William Bach

#include "displayhistory.h"

//---------------------------------------------------------------------
// Default constructor
DisplayHistory::DisplayHistory()
{
    transactionType = 'H';
    txnName = "History Request";
}

//---------------------------------------------------------------------
// Destructor
DisplayHistory::~DisplayHistory()
{

}

//---------------------------------------------------------------------
// For use with transactionfactory class - creates and returns an 
// instance of the ReturnBook class
Transaction* DisplayHistory::create() const
{
    return new DisplayHistory();
}

//---------------------------------------------------------------------
// Virtual print method for use with output overload
void DisplayHistory::print() const
{
    cout << " " << transactionType << " " << endl;
}

//---------------------------------------------------------------------
// Virtual function to perform the transaction
void DisplayHistory::execute(const BookInventory lib[]) const
{
    if(patron) // if patron exists
    {
        patron->printHistory(); // print out account history
    }
}

//---------------------------------------------------------------------
// Placeholder generic error printing function
void DisplayHistory::notFoundError(Patron* p, Item* b) const
{
    return;
}