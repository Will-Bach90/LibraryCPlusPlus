#ifndef BOOKINVENTORY
#define BOOKINVENTORY

#include "item.h"
#include <iostream>
using namespace std;

class BookInventory
{
    public:
        BookInventory();
        ~BookInventory();
        bool isEmpty() const;
        void makeEmpty();

        bool insert(Item*);
        bool retrieve(const Item&, Item*&) const;
        bool validChar(char) const;
        void inOrderPrint() const;

    private:
        struct Node
        {
            Item* data;
            Node* left;
            Node* right;
        };
        Node* root;
        void inOrderHelper(Node*) const;
        bool retrieveHelper(const Item&, Item*&, Node*) const;
        void makeEmptyHelper(Node*&);
};

#endif