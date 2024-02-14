// William Bach

#include "bookinventory.h"

//-------------------------------------------------------------------
// Default constructor: creates an empty tree
BookInventory::BookInventory()
{
    root = nullptr;
}

//-------------------------------------------------------------------
// Destructor
BookInventory::~BookInventory()
{
    this->makeEmpty();
}

//-------------------------------------------------------------------
// Checks to see if binary tree is empty
bool BookInventory::isEmpty() const
{
    return root==nullptr;
}

//-------------------------------------------------------------------
// Returns book type of root (e.g. "Fiction Book")
string BookInventory::getRootTypeName() const
{
    return root->data->getItemTypeName();
}

//-------------------------------------------------------------------
// Set up for printing out tree based on book type
void BookInventory::printSetUp() const
{
    root->data->printSetUp();
    cout << endl;
}

//-------------------------------------------------------------------
// Deletes tree, deletes all memory
void BookInventory::makeEmpty()
{
    if(!isEmpty())
    {
        makeEmptyHelper(root);
        delete root;
    }
}

//-------------------------------------------------------------------
// Recursive helper function to delete tree
void BookInventory::makeEmptyHelper(Node*& current)
{
    // as long as current is not null
    if(current != NULL)
    {
        makeEmptyHelper(current->left); // recurse to left
        makeEmptyHelper(current->right); // recurse to right 
        delete current->data; // delete item*
        delete current; // delete node
        current = nullptr; // set current ot null pointer
    }
}

//-------------------------------------------------------------------
// Recursive insert function, no duplicates allowed
bool BookInventory::insert(Item* dataptr) {
    Node* ptr = new Node;       // creates new node pointer to insert
    ptr->data = dataptr;        // data is given Item*
    dataptr = nullptr;          // reassigns given dataptr to be null
    ptr->left = ptr->right = nullptr; // left/right pointers are null
    if (isEmpty()) {        // if tree is empty, new node is root
        root = ptr;
    }
    else {
        // else we assign node pointer to root for traversal
        Node* current = root;      
        bool inserted = false;
        while (!inserted) {          // while new node is not inserted
            // if item is already in tree
            if(*ptr->data == *current->data)  
            {
                // dont insert, delete new node, return false
                delete ptr;
                ptr = NULL;
                return false;
            } // else we traverse tree to find right location
            else if (*ptr->data < *current->data) {
                // if new node belongs on the left of given node
                // and that slot is available
                if (current->left == nullptr) {          
                    // place on left and return true 
                    current->left = ptr;
                    inserted = true;
                }
                else
                    current = current->left; // else continue to left
            }
            else if(*ptr->data > *current->data){
                // if new node belongs on the right of given node
                // and that slot is available
                if (current->right == nullptr) { 
                    // place on right and return true
                    current->right = ptr;
                    inserted = true;
                }
                else
                    current = current->right; // else continue to right
            }
        }
    }
    return true;
}

//-------------------------------------------------------------------
// Retrieve function
bool BookInventory::retrieve(const Item& target, Item*& returnNode) const
{
    return retrieveHelper(target, returnNode, root);
}

//-------------------------------------------------------------------
// Recursive retrieve function. Returns true with pointer to the actual object
// and false if value not found
bool BookInventory::retrieveHelper(const Item& target, Item*& returnNode, Node* current) const
{
    // if current is null, we haven't found item, return false and 
    // return node is null pointer
    if (current == nullptr) {
        returnNode = nullptr;
        return false;
    }
    else if (target == *current->data) { // else if we've found our target
        returnNode = current->data; // set return node to current data
        return true;
    }
    else if (target < *current->data) { // else if target is less than curr
        // recurse to left
        return retrieveHelper(target, returnNode, current->left);
    }
    else
    {
        // else recurse to right
        return retrieveHelper(target, returnNode, current->right);
    }
}

//-------------------------------------------------------------------
// Checks to see char given is valid in library class
bool BookInventory::validChar(char c) const
{
    return c=='D';
}

//-------------------------------------------------------------------
// In-order print function, calls the recursive private function
// inOrderHelper
void BookInventory::inOrderPrint() const
{
    string linebreak2(64, '-');
    if (root != nullptr)
    {
        cout << this->getRootTypeName() << endl;
        cout << endl;
        this->printSetUp();
        inOrderHelper(root);
        cout << linebreak2 << endl;
    }
}

//-------------------------------------------------------------------
// Recursive in-order private helper function
void BookInventory::inOrderHelper(Node *current) const{
    if (current == nullptr) 
    {
        return;
    }
    inOrderHelper(current->left);
    cout << *current->data;
    inOrderHelper(current->right);
}