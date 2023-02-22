#ifndef BOOKFACTORY
#define BOOKFACTORY

#include "factory.h"
#include "fiction.h"
#include "childrensbook.h"
#include "periodical.h"
#include "item.h"

class BookFactory : public Factory
{
    public:
        BookFactory();
        virtual ~BookFactory();
        Item* createObject(char) const;
    protected:
        Item* objFactory[CHARACTERS];

};

#endif