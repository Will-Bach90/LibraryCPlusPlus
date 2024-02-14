// William Bach

#include "factory.h"

//---------------------------------------------------------------------------
// Default constructor (placeholder)
Factory::Factory() {}

//---------------------------------------------------------------------------
// Destructor (placeholder)
Factory::~Factory() {}

//---------------------------------------------------------------------------
// simple hash function
int Factory::hash(char ch) const
{
    return ch-'A';
}