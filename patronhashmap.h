#ifndef PATRON_HASHMAP
#define PATRON_HASHMAP

#include <iostream>
#include "patronlist.h"
using namespace std;

const int TABLE_SIZE = 101; // number of slots in hash table
class PatronHashMap
{
    friend ostream & operator<<(ostream &, const PatronHashMap &);
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        PatronHashMap();

        //---------------------------------------------------------------------
        // Destructor
        ~PatronHashMap();

        //---------------------------------------------------------------------
        // Hash function
        int hash(int k);

        //---------------------------------------------------------------------
        // Insert patron into hash map
        bool insert(Patron* p);

        //---------------------------------------------------------------------
        // Find patron in hash map
        Patron* retrieve(const Patron* p, Patron& rp);

        //---------------------------------------------------------------------
        // Print out all patrons contained in the hashmap
        void print();

    private:
        class HashNode{ // each slot of the hash table contains a hashnode
            public: 
                int key;
                PatronList* value;

                HashNode(int k, PatronList* p)
                {
                    this->key = k;
                    this->value = v;
                }
            }
        HashNode** table; // the hash table
};

#endif