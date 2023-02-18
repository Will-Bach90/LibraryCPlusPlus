#ifndef BOOKINVENTORY
#define BOOKINVENTORY

#include "book.h"
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
        bool remove(const Book &);
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
        void deleteCurrent(Node*&);
        bool removeHelper(const Item &, Item*&, Item*&);
        bool retrieveHelper(const Item &, Item*&, Item*) const;
        Book* findAndDeleteJustSmaller(Node*&);
        void makeEmptyHelper(Node*&);
};

#endif