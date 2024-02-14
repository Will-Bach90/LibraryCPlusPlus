// William Bach

#include "returnbook.h"

//---------------------------------------------------------------------
// Default constructor
ReturnBook::ReturnBook()
{
    transactionType = 'R';
    txnName = "Return";
}

//---------------------------------------------------------------------
// Destructor
ReturnBook::~ReturnBook() {

}

//---------------------------------------------------------------------
// For use with transactionfactory class - creates and returns an 
// instance of the ReturnBook class
Transaction* ReturnBook::create() const
{
    return new ReturnBook;
}

//---------------------------------------------------------------------
// Virtual print method for use with output overload
void ReturnBook::print() const
{
    cout << " " << transactionType << " " << endl;
} 

//---------------------------------------------------------------------
// Virtual function to perform the transaction
void ReturnBook::execute(const BookInventory lib[]) const
{
    if(book && patron)
    {
        if(patron->removeFromBorrowList(book))
        {
            book->setNumCopies(book->getNumCopies()+1);
        }
    }
}

//---------------------------------------------------------------------
// Function for printing errors when book is not found in library
void ReturnBook::notFoundError(Patron* p, Item* b) const
{
    if(b && p) // if book and patron are defined
    {
        // cast item object to book class
        const Book* bcast = static_cast<const Book*>(*&b);
        cout << "ERROR: " << p->getFirstName() << " ";
        cout << p->getLastName() << " tried to ";
        cout << "return '" << bcast->getTitle();
        cout << "' - not found in catalog." << endl;
    }
}