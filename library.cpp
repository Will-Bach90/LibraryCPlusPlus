// William Bach

#include "library.h"

//---------------------------------------------------------------------------
// Default constructor
Library::Library()
{
}

//---------------------------------------------------------------------------
// Destructor
Library::~Library()
{
    for(int i = 0; i < SIZE; i++)
    {
        books[i].makeEmpty(); // empty all trees in the hash table
    }
}

//---------------------------------------------------------------------------
// Function to process everything in the transaction data file
void Library::processTransactions(ifstream& inFile)
{
    // if id is provided on given line and hash table index
    int id, ndx; 

    string dataLine;  //each line provided in the transaction file

    // itemType (e.g. 'F' for Fiction books) and transaction type 
    // (e.g. 'C' for checkout)
    string itemType, txnType; 

    bool bookfound, patronfound;  // if book and patron are found
    Transaction* txn;   // transaction object pointer
    Item* book;        // Item object pointer

    // Return Item object pointer for retrieve function
    Item* rb;
    Patron* p;              // Patron object pointer
    for(;;)                
    {
        if (inFile.eof())   // If we've reached the end of the file
        { 
            break;          // break from for loop
        }
        inFile >> txnType;  // first char represents transaction type

        // if txnType is defined and there's more info on the rest of the line
        if(!txnType.empty()) 
        {
            bookfound = patronfound = true;
            // create new transaction object
            txn = txnfactory.createObject(txnType[0]); 
            getline(inFile, dataLine); // get the rest of the line
            if(!dataLine.empty())
            {
                istringstream ss(dataLine);
                ss >> id; // next string should be patron id
                patronfound = patrons.retrieve(id, p); // try to find patron 
                if(patronfound) // if patron exists
                { 
                    if(!ss.eof())
                    {
                        ss >> itemType; // next char should be item type
                        // create new item object
                        book = bookfactory.createObject(itemType[0]); 
                        if(book != NULL) // if itemType is valid
                        {
                            if(book->setTransactionData(ss)) // set item data
                            {
                                ndx = hash(itemType[0]);
                                // check if book exists in library
                                bookfound = books[ndx].retrieve(*book, rb);
                                // if not in library, return an error
                                if(txn!=NULL && !bookfound) 
                                {
                                    // return not found error
                                    txn->notFoundError(p, book); 
                                }
                            }
                            else // else return item format error
                            {
                                bookfound = false;
                                cout << "ERROR: " << book->getFormat();
                                cout << " is not a valid item format.";
                                cout << endl;
                            }
                            delete book;
                        }
                        else // else return item type error
                        {
                            bookfound = false;
                            cout << "ERROR: " << itemType << " is not a "; 
                            cout << "valid item type." << endl;
                        }
                    }
                }
                else // else return patron not found error
                {
                    cout << "ERROR: There is no patron with ID " << id << endl;
                }
            }
            if(txn!=NULL) // if transaction type valid
            {
                if(bookfound && patronfound)
                {
                    txn->setData(p, rb); // set txn data
                    txn->execute(books); // execute transaction
                }
                delete txn;
                txn = nullptr;
            }
            else if(!txnType.empty())// else return command type error
            {
                cout << "ERROR: " << txnType << " is not a "; 
                cout << "valid command type." << endl;
            }
        }
        txnType.clear(); // reset transaction type
    }
}

//---------------------------------------------------------------------------
// Function to add all books to library from book data file
void Library::addBooks(ifstream& inFile)
{
    string dataLine; // line of data from file
    string itemType;   // item type
    Item* book;      // Item pointer to object
    for(;;)
    {
        if (inFile.eof()) // if at end of file, break from for loop
        { 
            break; 
        }
        inFile >> itemType;  // first char should be item type
        getline(inFile, dataLine); // get rest of line
        if(!dataLine.empty())
        {
            // create new item object
            book = bookfactory.createObject(itemType[0]); 
            if(book != NULL) // if book type is valid
            {
                istringstream ss(dataLine);
                if(book->setData(ss)) // set book data
                {
                    // insert into library (in relevant tree)
                    books[hash(itemType[0])].insert(book); 
                }
                else
                {
                    delete book;
                }
            }
            else // else return item type error
            {
                cout << "ERROR: " << itemType << " is not a valid item type."; 
                cout << " Item could not be added to the Library." << endl;
            }
        }
        itemType.clear();
    }
}

//---------------------------------------------------------------------------
// Function to add all patrons to library database from patron data file
void Library::addPatrons(ifstream& inFile)
{
    Patron* patron; // Patron pointer
    for(;;)
    {
        if (inFile.eof()) // if at end of file, break from for loop
        { 
            break; 
        }
        patron = new Patron(); // initialize
        bool patronCreated = patron->setData(inFile); // set patron data
        if(patronCreated) // if patron was created
        {
            patrons.insert(patron); // insert into hashmap
        }
        else
        {
            delete patron; // else delete object
        }
    }
    patrons.print(); // print out entire patron hashmap
}

//---------------------------------------------------------------------------
// private hash function for hash table of binary trees
int Library::hash(char c) const 
{
    return c-'A';
}