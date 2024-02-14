// William Bach

#include "accounthistory.h"

//-------------------------------------------------------------------------
// Default constructor creates an empty list
AccountHistory::AccountHistory()
{
    this->head = nullptr;
}

//-------------------------------------------------------------------------
// Destructor empties entire list, but does not delete Items stored in list
AccountHistory::~AccountHistory() {
    this->makeEmpty();
}

//-------------------------------------------------------------------------
// Checks to see if list is empty
bool AccountHistory::isEmpty() const
{
    return head==nullptr;
}

//-------------------------------------------------------------------------
// Appends a node containing the item pointer and transaction type (string)
void AccountHistory::append(Item* b, string t)
{
    Node* temp = new Node;      // Creates new node
    temp->txnType = t;          // Transaction type string set
    temp->book = b;             // Item pointer set
    temp->next = nullptr;       // Next node pointer set to null
    if(head == nullptr) {       // If list is empty
        head = temp;            // Set new node to be head
    }
    else{
        Node* current = head;   // else set a pointer to head
        while(current->next!=nullptr) // while next node is not null
        {
            current = current->next;    // traverse list until the end
        }
        current->next = temp;           // Last node is now the new node
    }
}

//-------------------------------------------------------------------------
// empties out entire list
void AccountHistory::makeEmpty()
{
    if(isEmpty()) { return; } // if list is already empty, return
    Node* temp = head;        // else set pointer to head
    Node* next;               // a pointer to keep track of next node
    while(temp!=nullptr)      // until we reach the end of the list...
    {
        next = temp->next;    // next is equal to temp's next node
        delete temp;          // go ahead and delete temp
        temp = next;          // now temp is it's next node
    }
    head = nullptr;           // set head to null
}

//---------------------------------------------------------------------
// Function to print out entire account history
void AccountHistory::print() const
{
    if(isEmpty()) { return; } // if empty we print out nothing
    cout << setw(12) << left << "ACTION" << setw(22) << left; // formatting
    cout << "AUTHOR" << setw(20) << left << "TITLE";
    cout << setw(18) << right << "DATE" << endl;
    Node* current = head; // pointer to head node
    while(current!=nullptr) // until we reach the end of the list
    {
        // print out all history nodes
        cout << setw(12) << left << current->txnType; 
        current->book->printHistoryFormat();
        cout << endl;
        current = current->next;
    }
}