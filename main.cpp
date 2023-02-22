#include "library.h"
#include <iostream>
using namespace std;

int main() {
    
    Library library;
    ifstream inFile("patrondata.txt");
    library.addPatrons(inFile);
    ifstream inFile2("booktxt.txt");
    library.addBooks(inFile2);
    ifstream inFile3("txndata.txt");
    library.processTransactions(inFile3);
    
    return 0;
}