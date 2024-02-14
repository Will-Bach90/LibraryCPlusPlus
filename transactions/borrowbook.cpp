// William Bach

#include "borrowbook.h"

//---------------------------------------------------------------------
// Default constructor
BorrowBook::BorrowBook()
{
    transactionType = 'C';
    txnName = "CheckOut";
}

//---------------------------------------------------------------------
// Destructor
BorrowBook::~BorrowBook() {
}

//---------------------------------------------------------------------
// For use with transactionfactory class - creates and returns an 
// instance of the ReturnBook class
Transaction* BorrowBook::create() const
{
    return new BorrowBook;
}

//---------------------------------------------------------------------
// Virtual print method for use with output overload
void BorrowBook::print() const
{
    cout << " " << transactionType << " " << endl;
} 

//---------------------------------------------------------------------
// Virtual function to perform the transaction
void BorrowBook::execute(const BookInventory lib[]) const
{
    // if book and patron exist and book is in the tree
    if(book && patron)
    {
        if(book->inStock()) // if book still has copies available
        {
            patron->addToBorrowList(book); // add to patron's borrow list
            // decrement copies available
            book->setNumCopies(book->getNumCopies()-1);
        }
        else
        {
            // else return error
            const Book* bcast = static_cast<const Book*>(*&book);
            cout << "ERROR: No copies of " << bcast->getTitle();
            cout << " available for checkout." << endl;
        }
    }
}

//---------------------------------------------------------------------
// Function for printing errors when book is not found in library
void BorrowBook::notFoundError(Patron* p, Item* b) const
{
    if(b && p) // if book and patron are defined
    {
        const Book* bcast = static_cast<const Book*>(*&b);
        cout << "ERROR: " << p->getFirstName() << " ";
        cout << p->getLastName() << " tried to ";
        cout << "check out '" << bcast->getTitle();
        cout << "' - not found in catalog." << endl;
    }
}