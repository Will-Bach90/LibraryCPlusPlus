#ifndef FACTORY
#define FACTORY

#include <iostream>
using namespace std;

const int CHARACTERS = 26;

class Factory
{
    public:
        Factory();
        virtual ~Factory();
    protected:
        virtual int hash(char) const;
};

#endif