#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include "patronlist.h"
#include "bookinventory.h"
#include "bookfactory.h"
#include "transactionfactory.h"

class LibraryManager
{
    public:
        LibraryManager();
        ~LibraryManager();
        void processTransactions(string fileName);
        void addBooks(string fileName);
        void addPatrons(string fileName);
        void insertBook(Book* book);
        void retrieveBook(Book* book, Book& retrievedBook);
        void insertPatron(Patron* patron);
        void retrievePatron(Patron* patron, Patron& retrievedPatron);

    private:
        PatronList patrons;
        BookInventory books[numBookTypes];
        BookFactory bookFactory;
        TransactionFactory transactionFactory;
};

#endif 
