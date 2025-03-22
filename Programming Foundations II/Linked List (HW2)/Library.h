//DONE: Make linked list to keep track of the books
//DONE: Implement sorted link list operations: insert, delete, search
//DONE: Implement a print method (others if necessary)
#include "BookNode.h"
#include <vector>

class Library
{
    public:
        //constructors
        Library();
        Library(const Library & copylib);
        ~Library();
        
        //methods
        void insert(const string t, const string a);
        void deleteNode(const string t, const string a);
        BookNode* searchTitle(const string t);
        void searchAuthor(const string a);
        void print();
        
    private:
        BookNode * Head;
};
