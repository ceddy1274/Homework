#include "BookNode.h"

// Default Constructor
BookNode::BookNode()
{
    title = "";
    author = "";
    numAvailable = 0;
    next = NULL;
}

// Copy Constructor
BookNode::BookNode(const BookNode & book)
{
    title = book.title;
    author = book.author;
    numAvailable = book.numAvailable;
    next = NULL;
}

// Destructor
BookNode::~BookNode()
{
    title = "";
    author = "";
    numAvailable = 0;
    next = NULL;
}

// Getters
string BookNode::getTitle() const
{
    return title;
}

string BookNode::getAuthor() const
{
    return author;
}

int BookNode::getNumAvailable() const
{
    return numAvailable;
}

BookNode* BookNode::getNext() const
{
    return next;
}

// Setters
void BookNode::setTitle(const string t)
{
    title = t;
}

void BookNode::setAuthor(const string a)
{
    author = a;
}
//(checkoutBook and returnBook are numAvailable setters either decrementing or incrementing)
void BookNode::returnBook(const int n)
{
    //because we add to number of copies and don't set
    numAvailable += n;
}

void BookNode::checkoutBook(const int n)
{
    //because we subtract to number of copies and don't set
    numAvailable -= n;
}

void BookNode::setNext(BookNode* n)
{
    next = n;
}

void BookNode::print() const
{
    cout << "The book " << title << " by " << author << " has " << numAvailable << " copies/copy available\n";  
}