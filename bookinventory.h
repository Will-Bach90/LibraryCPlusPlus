// William Bach

//---------------------------------------------------------------------------
// BookInventory.h
// Class representing the inventory of book items in the library as
// a Binary Search Tree
//---------------------------------------------------------------------------
// Implementation and assumptions:
// - Inherits from Item class and assumes the class has been defined
// - Utilizes common binary search tree methods, such insert, retrieve,
// deleting all nodes, and print all nodes inorder, and these method can be
// applies for all the different book items in the library. 
// - Assumes that item class and its derived class contain comparative 
// operators (<,>,==,!=)
//---------------------------------------------------------------------------
#ifndef BOOKINVENTORY_H
#define BOOKINVENTORY_H

#include "item.h"
#include <iostream>
using namespace std;

class BookInventory
{
    public:
        //-------------------------------------------------------------------
        // Constructor
        BookInventory();

        //-------------------------------------------------------------------
        // Destructor
        virtual ~BookInventory();

        //-------------------------------------------------------------------
        // Checks to see if tree is empty
        bool isEmpty() const;

        //-------------------------------------------------------------------
        // Deletes all nodes in tree (but not the node data)
        void makeEmpty();

        //-------------------------------------------------------------------
        // Inserts Item* into tree
        bool insert(Item*);

        //-------------------------------------------------------------------
        // Retrieves item from tree
        bool retrieve(const Item&, Item*&) const;

        //-------------------------------------------------------------------
        // Checks to see if given char is valid for printing
        bool validChar(char) const;

        //-------------------------------------------------------------------
        // Prints out all items in tree in-order
        void inOrderPrint() const;

        //-------------------------------------------------------------------
        // Retrieves Book Type name (e.g. "Fiction Book") for printing out
        // all trees contained in array of trees in library
        string getRootTypeName() const;

        //-------------------------------------------------------------------
        // sets up printing of tree based on type of book in tree
        void printSetUp() const;

    private:
        //-------------------------------------------------------------------
        // Node contained in tree
        struct Node
        {
            Item* data; // item pointer is data
            Node* left; // left pointer
            Node* right; // right pointer
        };
        Node* root; // root node

        //-------------------------------------------------------------------
        // Recursive helper function for in-order print
        void inOrderHelper(Node*) const;

        //-------------------------------------------------------------------
        // Recursive helper function for retrieve
        bool retrieveHelper(const Item&, Item*&, Node*) const;

        //-------------------------------------------------------------------
        // Recursive helper function to delete tree
        void makeEmptyHelper(Node*&);
};

#endif