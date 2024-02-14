// William Bach

#include "patronlist.h"

//---------------------------------------------------------------------------
// Default constructor creates empty list
PatronList::PatronList()
{
    this->head = nullptr;
}

//---------------------------------------------------------------------------
// Destructor 
PatronList::~PatronList() {
    this->makeEmpty();
}

//---------------------------------------------------------------------------
// Checks if list is empty
bool PatronList::isEmpty() const
{
    return head==nullptr;
}

//---------------------------------------------------------------------------
// Appends patron to end of list
void PatronList::append(Patron* p)
{
    Node* temp = new Node; // create new node
    temp->data = p; // data is the new patron
    temp->next = nullptr; // next node is null
    if(head == nullptr) { // if list is empty
        head = temp;      // new node is the head
    }
    else{ // else create a pointer to head to traverse the list
        Node* current = head; 
        while(current->next!=nullptr) // while we haven't reached the end
        {
            current = current->next; // continue traversing
        }
        current->next = temp; // at the end add the new node
    }
}

//---------------------------------------------------------------------------
// looks for patron in list, returns true if found with pointer to patron
bool PatronList::retrieve(int id, Patron*& rp)
{
    if(isEmpty()) { return false; } // if list is empty, return false
    Node* current = head; // pointer to head for traversing the list
    if(current->data->getID() == id)  // if patron is found
    { 
        rp = current->data; // set pointer to patron
        return true; // return true
    }
    while(current->next!=nullptr) // else continue traversing the list
    {
        if(current->next->data->getID() == id)
        {
            rp = current->next->data;
            return true;
        }
        current = current->next;
    }
    rp = nullptr;
    return false;
}

//---------------------------------------------------------------------------
// delete entire list, deletes patrons as well
void PatronList::makeEmpty()
{
    Node* temp = head;
    Node* next;
    while(temp!=nullptr)
    {
        next = temp->next;
        delete temp->data;
        delete temp;
        temp = next;
    }
    head = nullptr;
}

//---------------------------------------------------------------------
// Function to print out entire list of patrons
void PatronList::print() const
{
    Node* current = head;
    while(current!=nullptr)
    {
        cout << *current->data;
        current = current->next;
    }
}