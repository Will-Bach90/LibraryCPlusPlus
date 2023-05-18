# Library
Basic implementation of a library system utilizing the factory design pattern and OOP. Basic functionality:
* Reads input from text file
* Creates patron list with custom built hashmap for quick lookup via Patron ID, with open hashing and collisions handled via linked lists.
* Creates book database with binary search tree.
* * Allows for several genres of books, each with their own tree.
* * Genre trees stored in hash table
* * Books created via bookfactory
* Transactions created via txnfactory
* * Allows for checking out books, returning books, displaying patron history, and displaying all books in the library with their current quantities.
* * Basic errory checking to ensure patron cannot return book that they had not checked out, cannot check out book if not enough quantity, books exists in library, patron is in library system, etc
* * Patron's transaction history stored in custom built singly linked list
