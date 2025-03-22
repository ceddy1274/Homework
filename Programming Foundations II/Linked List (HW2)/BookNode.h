//DONE: BookNode class to store book information
//DONE: Add four private variables: title, author, # of copies, next pointer
//DONE: Getters and setters

#include <iostream>
using namespace std;

class BookNode
{
    public:
        // Constructors
        BookNode();
        BookNode(const BookNode & book);
        ~BookNode();
        
        // Getters
        string getTitle() const;
        string getAuthor() const;
        int getNumAvailable() const;
        BookNode* getNext() const;
        
        // Setters 
        //(checkoutBook and returnBook are numAvailable setters either decrementing or incrementing)
        void setTitle(const string t);
        void setAuthor(const string a);
        void returnBook(const int n);
        void checkoutBook(const int n);
        void setNext(BookNode* n);
        
        //Other methods 
        void print() const;
        
    private:
        string title;
        string author;
        int numAvailable;
        BookNode *next;
};
