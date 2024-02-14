// William Bach

//---------------------------------------------------------------------------
// factory.h
// Parent Factory class for use with derived BookFactory and 
// TransactionFactory classes
//---------------------------------------------------------------------------
// Implementation and assumptions:
//      -- Factory class not intended to be called directly.
//      -- Implementation is largely left to derived classes
//      -- Hash function assumes size of hash table in child classes to 
//         to be 36, with unique (closed) hashing.
//      -- No collision handling.
//---------------------------------------------------------------------------
#ifndef FACTORY
#define FACTORY

#include <iostream>
using namespace std;

// size of hash tables in derived classes (36 chars: A-Z, 0-9)
const int CHARACTERS = 36;

class Factory
{
    public:
        //-------------------------------------------------------------------
        // Default constructor
        Factory();

        //-------------------------------------------------------------------
        // Destructor
        virtual ~Factory();
    protected:
        //-------------------------------------------------------------------
        // Protected hash function for use in derived factory classes
        virtual int hash(char) const;
};

#endif