// William Bach

#include "transaction.h"
//---------------------------------------------------------------------
// Default Constructor
Transaction::Transaction()
{
}

//---------------------------------------------------------------------
// Destructor
Transaction::~Transaction() 
{

}

//---------------------------------------------------------------------
// Get transaction type (e.g. 'C' for checkout)
char Transaction::getTransactionType() const
{
    return this->transactionType;
}

//---------------------------------------------------------------------
// Get transaction type name (e.g. "Checkout" or "Return")
string Transaction::getTransactionName() const
{
    return this->txnName;
}

//---------------------------------------------------------------------
// Set transaction type (e.g. 'C' for checkout)
void Transaction::setTransactionType(char c)
{
    this->transactionType = c;
}

//---------------------------------------------------------------------
// Virtual print method for use with output overload
void Transaction::print() const
{
    cout << "Transaction of type: " << transactionType;
} 

//---------------------------------------------------------------------
// Set patron and item data members
void Transaction::setData(Patron* p, Item* b)
{
    patron = p;
    book = b;
}

//---------------------------------------------------------------------
// output overload
ostream & operator<<(ostream & output, const Transaction &t)
{
    t.print();
    output << endl;
    return output;
}