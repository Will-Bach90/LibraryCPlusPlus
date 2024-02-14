// William Bach

#include "bookfactory.h"

//---------------------------------------------------------------------------
// Default constructor initializes Item* array with different kinds of books
BookFactory::BookFactory()
{
    for(int i = 0; i < CHARACTERS; i++)
    {
        objFactory[i] = NULL;
    }
    objFactory[hash('C')] = new ChildrensBook();
    objFactory[hash('P')] = new Periodical();
    objFactory[hash('F')] = new Fiction();
}

//---------------------------------------------------------------------------
// Destructor
BookFactory::~BookFactory()
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
// Creates and returns item pointer to derived class objects
Item* BookFactory::createObject(char ch) const
{
    if(objFactory[hash(ch)]!=NULL) // if objFactory at index is defined
    {
        //create and return instance of that object
        return objFactory[hash(ch)]->create();
    }
    return NULL; // else return null
}