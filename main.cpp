// William Bach

//---------------------------------------------------------------------------
// main.cpp
// Main file for implementing library
//---------------------------------------------------------------------------
// List class Implementation and assumptions:  
//   -- Assumes library class is implemented
//   -- Data files are hard coded
//---------------------------------------------------------------------------
#include "library.h"
#include <iostream>
using namespace std;

int main() {

    Library library;                   // Create instance of library class
    ifstream inFile("data4patrons.txt"); // open patron data file
    library.addPatrons(inFile);        // add patrons to library
    ifstream inFile2("data4books.txt");   // open book data file
    library.addBooks(inFile2);         // add books to library
    ifstream inFile3("data4commands.txt");   // open transaction data file
    library.processTransactions(inFile3); // process transactions
    
    return 0;
}