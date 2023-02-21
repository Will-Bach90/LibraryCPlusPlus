#ifndef PATRON_HASHMAP
#define PATRON_HASHMAP

#include <iostream>
#include "patronlist.h"
using namespace std;

const int TABLE_SIZE = 101; // number of slots in hash table
class PatronHashMap
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        PatronHashMap();

        //---------------------------------------------------------------------
        // Destructor
        ~PatronHashMap();

        //---------------------------------------------------------------------
        // Insert patron into hash map
        void insert(Patron*);

        //---------------------------------------------------------------------
        // Find patron in hash map
        bool retrieve(int, Patron*&);

        //---------------------------------------------------------------------
        // Delete the entire hash table
        void makeEmpty();
    
        //---------------------------------------------------------------------
        // Print out all patrons contained in the hashmap
        void print();

    private:
        PatronList* table[TABLE_SIZE]; // the hash table
        //---------------------------------------------------------------------
        // Hash function
        int hash(int) const;
};

#endif
