// William Bach

#include "currentbooks.h"

//---------------------------------------------------------------------------
// Default constructor
CurrentBooks::CurrentBooks()
{
    this->head = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
CurrentBooks::~CurrentBooks() {
    this->makeEmpty();
}

//---------------------------------------------------------------------------
// Checks to see if list is empty: returns true if empty
bool CurrentBooks::isEmpty() const
{
    return head==nullptr;
}

//---------------------------------------------------------------------------
// Adds book node to end of list
void CurrentBooks::append(Item* b)
{
    Node* temp = new Node; // create new node
    temp->data = b;        // node data is item pointer
    temp->next = nullptr;  // next pointer is null
    if(head == nullptr) {  // if list is empty
        head = temp;       // new node becomes head of the list
    }
    else{
        Node* current = head;  // else we traverse the list
        while(current->next!=nullptr) // until we reach the end
        {
            current = current->next;
        }
        current->next = temp; // add node to end of list
    }
}

//---------------------------------------------------------------------------
// Removes book from list: returns true if removed
bool CurrentBooks::remove(Item* b)
{
    if(isEmpty()) { return false; } // if list is empty, nothing to remove
    Node* current = head; // pointer to traverse the list
    if(*current->data == *b) //if head is our target
    { 
        head = head->next;  // set head to next node
        delete current;     // delete head
        current = nullptr;
        return true;
    }
    while(current->next != nullptr) //otherwise traverse the list
    {
        if(*current->next->data == *b) // if target is found
        {
            Node* temp = current->next; // set temp pointer to target node
            // prev node's next is set to target node's next
            current->next = current->next->next; 
            delete temp; // delete temp
            temp = nullptr;
            return true;  // return true
        }
        current = current->next; // otherwise continue traversing the list
    }
    return false;
}

//---------------------------------------------------------------------------
// Empties entire list. Does not delete node data.
void CurrentBooks::makeEmpty()
{
    if(isEmpty()) { return; } // if list is already empty, return
    Node* temp = head;        // else set pointer to head
    Node* next;               // a pointer to keep track of next node
    while(temp!=nullptr)      // until we reach the end of the list...
    {
        next = temp->next;    // next is equal to current's (temp's) next node
        delete temp;          // go ahead and delete temp
        temp = next;          // now temp is it's next node
    }
    head = nullptr;           // set head to null
}

//---------------------------------------------------------------------------
// Function to print out entire list of current check out books
void CurrentBooks::print() const
{
    if(isEmpty()) { return; } // if list is empty, return
    Node* current = head;     // node pointer to head
    while(current!=nullptr)   // traverse until we reach the end of the list
    {
        cout << *current->data << endl;  // print book data
        current = current->next;         // continue to next node
    }
}