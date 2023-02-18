#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include "PatronList.h"
#include "BookInventory.h"
#include "BookFactory.h"
#include "TransactionFactory.h"

class LibraryManager
{
    public:
        LibraryManager();
        ~LibraryManager();
        void processTransactions(std::string fileName);
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
