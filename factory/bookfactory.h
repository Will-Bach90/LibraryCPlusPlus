// William Bach

//---------------------------------------------------------------------------
// bookfactory.h
// Derived Factory class for returning book objects
//---------------------------------------------------------------------------
// Bookfactory class Implementation and assumptions:  
//   -- Item* createObject(char) function returns new Book object, where the
//      type of book is determined by input char ('C' for ChildrensBook,
//      'F' for Fiction, 'P' for periodical).
//   -- objFactory data member is array of Item*, where each each index maps 
//      to a particular book type. 
//   -- Hashing function used to map a given char value to index of array
//   -- Invalid input chars return null pointers
//---------------------------------------------------------------------------
#ifndef BOOKFACTORY
#define BOOKFACTORY

#include "factory.h"
#include "fiction.h"
#include "childrensbook.h"
#include "periodical.h"
#include "item.h"

class BookFactory : public Factory
{
    public:
        //-------------------------------------------------------------------
        // Constructor
        BookFactory();

        //-------------------------------------------------------------------
        // Destructor
        virtual ~BookFactory();

        //-------------------------------------------------------------------
        // Returns item pointer to derived class
        Item* createObject(char) const;
    protected:
        //-------------------------------------------------------------------
        // Array that holds item pointers to different derived classes
        Item* objFactory[CHARACTERS];

};

#endif