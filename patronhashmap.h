// William Bach

//---------------------------------------------------------------------------
// patronhashmap.h
// Hash table to store all patrons. 
//---------------------------------------------------------------------------
// PatronHashMap class Implementation and assumptions:  
//   -- Hash function computes index of array based on patron's id
//   -- Open hashing, collisions handled via linked lists stored in each slot
//      of array rather than the patrons themselves. This allows for the 
//      possibility of more than 10000 patrons.
//   -- Memory allocated dynamically as more patrons are added to the hash 
//      table.
//   -- Assumes patron's ids are determined randomly to maintain fast lookup 
//      time.
//---------------------------------------------------------------------------
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
        virtual ~PatronHashMap();

        //---------------------------------------------------------------------
        // Insert patron into hash map
        void insert(Patron*);

        //---------------------------------------------------------------------
        // Find patron in hash map
        bool retrieve(int, Patron*&);

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