//---------------------------------------------------------------------------
// library.h
// Primary manager class to be called by the main. Handles building of the
// library, creating list of patrons, and processing transactions.
//---------------------------------------------------------------------------
// Library class Implementation and assumptions:  
//   -- Data members include the hashmap of patrons, hash table of binary 
//      trees holding all books, book and transaction factory objects for
//      instantiating book and transaction objects.
//   -- Hash function maps char of book type (C for childrens book, F for
//      fiction, and P for Periodical) to indexes in the array of Binary 
//      Trees. Assumes 1:1 mapping (closed hashing), no collision handling
//
//---------------------------------------------------------------------------
#ifndef LIBRARY_H
#define LIBRARY_H

#include "patronhashmap.h"
#include "bookinventory.h"
#include "bookfactory.h"
#include "transactionfactory.h"

class Library
{
    public:
        Library();
        ~Library();
        void processTransactions(istream&);
        void addBooks(istream&);
        void addPatrons(istream&);
        void print(char) const; // prints out entire library

    private:
        PatronHashMap patrons;
        BookInventory books[numBookTypes];
        BookFactory bookFactory;
        TransactionFactory transactionFactory;
        int hash(char) const;
};

#endif 
