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
        void print(char) const;

    private:
        PatronList patrons;
        BookInventory books[numBookTypes];
        BookFactory bookFactory;
        TransactionFactory transactionFactory;
        int hash(char) const;
};

#endif 
