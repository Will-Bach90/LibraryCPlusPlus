// William Bach

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
#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "patronhashmap.h"
#include "bookinventory.h"
#include "transactionfactory.h"
#include "bookfactory.h"
using namespace std;

const int SIZE = 36; // hash table size (characters A-Z, 0-9)

class Library
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Library();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Library();
        
        //---------------------------------------------------------------------
        // Processes transactions
        void processTransactions(ifstream&);

        //---------------------------------------------------------------------
        // Adds books to respective binary tree
        void addBooks(ifstream&);

        //---------------------------------------------------------------------
        // Adds patrons to patron hash map
        void addPatrons(ifstream&);


    private:
        PatronHashMap patrons;      // hash table of all patrons

        // hash table of binary trees containing different book types.
        // char value corresponds to different book types - e.g. 'F' 
        // for fiction, 'C' for children's books, 'P' for periodical.
        // No collision handling.
        BookInventory books[SIZE];  

        // Factory for returning transaction objects
        TransactionFactory txnfactory; 

        // Factory for returning item objects
        BookFactory bookfactory;

        // Hash function for mapping item types to their respective
        // trees
        int hash(char) const;
};

#endif