// William Bach

#include "transactionfactory.h"

//---------------------------------------------------------------------------
// default constructor creates hash table of transaction object pointers
TransactionFactory::TransactionFactory()
{
    for(int i = 0; i < CHARACTERS; i++)
    {
        objFactory[i] = NULL;
    }    
    objFactory[hash('C')] = new BorrowBook;
    objFactory[hash('R')] = new ReturnBook;
    objFactory[hash('H')] = new DisplayHistory; 
    objFactory[hash('D')] = new DisplayLibrary; 

}

//---------------------------------------------------------------------------
// destructor deletes hash table
TransactionFactory::~TransactionFactory()
{
    for(int i = 0; i < CHARACTERS; i++)
    {
        if(objFactory[i] != NULL)
        {
            delete objFactory[i];
            objFactory[i] = NULL;
        }
    }
}

//---------------------------------------------------------------------------
// Creates and returns transaction pointer to derived class objects
Transaction* TransactionFactory::createObject(char ch) const
{
    if(objFactory[hash(ch)]!=NULL) // if objFactory at index is defined
    {
        //create and return instance of that object
        return objFactory[hash(ch)]->create(); 
    }
    return nullptr; // else return null pointer
}