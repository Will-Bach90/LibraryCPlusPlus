#ifndef TRANSACTION_FACTORY
#define TRANSACTION_FACTORY

#include "factory.h"
#include "transaction.h"
#include "borrowbook.h"
#include "returnbook.h"
#include "displayhistory.h"


class TransactionFactory : public Factory
{
    public:
        TransactionFactory();
        virtual ~TransactionFactory();
        Transaction* createObject(char) const;
    protected:
        Transaction* objFactory[CHARACTERS];

};

#endif