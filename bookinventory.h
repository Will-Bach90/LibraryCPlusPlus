#ifndef BOOKINVENTORY
#define BOOKINVENTORY

#include "item.h"
#include <iostream>
using namespace std;

class BookInventory
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        BookInventory();
    
        //---------------------------------------------------------------------
        // Destructor
        ~BookInventory();
    
        //---------------------------------------------------------------------
        // Checks if the Binary Tree contains any book item nodes  
        bool isEmpty() const;
    
        //---------------------------------------------------------------------
        // Empty all book item nodes contained in the Binary Tree    
        void makeEmpty();

        //---------------------------------------------------------------------
        // Inserts a book item node contained in the Binary Tree
        bool insert(Item*);
    
        //---------------------------------------------------------------------
        // Retrieves a book item node contained in the Binary Tree 
        bool retrieve(const Item&, Item*&) const;
    
        //---------------------------------------------------------------------
        // Print out all book item nodes contained in the Binary Tree inorder
        void inOrderPrint() const;

    private:
        struct Node
        {
            Item* data;
            Node* left;
            Node* right;
        };
        Node* root;
    
        // helper function for inOrderPrint
        void inOrderHelper(Node*) const;
    
        // helper function for retrieve
        bool retrieveHelper(const Item&, Item*&, Node*) const;
    
        // helper function for makeEmpty
        void makeEmptyHelper(Node*&);
};

#endif
