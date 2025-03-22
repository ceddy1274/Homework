#include "Library.h"

//default constructor
Library::Library()
{
    Head = NULL;
}

//copy constructor
Library::Library(const Library & copylib)
{
    //Make a new Library called copy
   BookNode *copy = new BookNode();
   //Set the copy Head equal to copy (will be NULL)
   Head = copy;
   //Make a temporary pointer for when we walk the list starting at the head of the list we are copying
   BookNode *temp = copylib.Head;
   //Walk the list and set each BookNode from our orginal list in same order in our copy list
   while (temp != NULL)
   {
      copy->setNext(new BookNode());
      copy = copy->getNext();
      copy->setTitle(temp->getTitle());
      copy->setAuthor(temp->getAuthor());
      copy->returnBook(temp->getNumAvailable());
      copy->setNext(NULL);
      temp = temp->getNext();
   }
   //Set copy back to our null head
   copy = Head;
   //Set head to our actual first BookNode in our new linked list
   Head = copy->getNext();
   //Delete the null copy
   delete copy;
}

//destructor
Library::~Library()
{
    BookNode * temp = Head;
    while (temp != NULL)
    {
       Head = Head->getNext();
       delete temp;
       temp = Head;
    }
}

//sorted insert by author then by title
void Library::insert(const string t, const string a)
{
   // Intalize curr and prev pointer for list walking
   BookNode *curr = Head;
   BookNode *prev = Head;
   // Loop till you find a spot for the author (sorted ascendingly)
   // WON"T RUN LOOP IF ITS FIRST ALPHABETICAL AUTHOR
   while ((curr != NULL) && (curr->getAuthor() <= a))
   {
       // If author is already in library with other books they have written
       if ((curr->getAuthor() == a))
       {
           // Loop till you find a place for the book (sorted ascendingly)
           // WON"T RUN LOOP IF ITS FIRST ALPHABETICAL BOOK
           while ((curr != NULL) && (curr->getTitle() < t) && (curr->getAuthor() <= a))
           {
              prev = curr;
              curr = curr->getNext();
           }
           // Break out of orginal loop for sorting authors
           break;
       }
       //if it is not the same author
       else
       {
            prev = curr;
            curr = curr->getNext();
       }
   }
   //creat new node and connect to current node setting title, author, and 1 copy
   BookNode *temp = new BookNode();
   temp->setTitle(t);
   temp->setAuthor(a);
   temp->returnBook(1);
   temp->setNext(curr);
   //for empty list
   if (prev == curr)
   {
       Head = temp;
   }
   //for non-empty list
   else
   {
       prev->setNext(temp); 
   }
}

//used to delete individual nodes from linked list
void Library::deleteNode(const string t, const string a)
{
    //Intalize current and previous node for list walking
    BookNode * curr = Head;
    BookNode * prev = NULL;
    //Walk list until you find where the node you want to delete is
    while(curr != NULL && !(curr->getTitle() == t && curr->getAuthor() == a))
    {
        prev = curr;
        curr = curr->getNext();
    }
    //This is executed if the node you wanted to delete is not in the linked list
    if (curr == NULL)
    {
        cout << t << " by " << a << " is not currently in our system.  Please check back another time.\n";
    }
    //If only one copy of the book is available delete it from the list
    else if (curr->getNumAvailable() == 1)
    {
        //If the author and book were the first in the list
        if(curr != NULL && curr == Head)
            Head = Head->getNext();
        //If the author or book were not the first in the list
        else
            prev->setNext(curr->getNext());
        cout << "The last copy of " << t << " by " << a << " has been checked out.\n";
        //delete the node and set it equal to NULL
        delete curr;
        curr = NULL; 
    }
    //If more then one copy is available decrement the number of available copies by 1
    else
    {
        curr->checkoutBook(1);
        cout << t << " by " << a << " has been sucessfully checked out.  There are " << curr->getNumAvailable() << " copies/copy left.\n";
    }
}

//Used in input 1 for when we need to search the list to find where we need to insert that book.  Returns a single BookNode
BookNode* Library::searchTitle(const string t)
{
    //set a temporary value equal to the head of the list
    BookNode *temp = Head;
    //Walk the list until you hit null or find the title
    while((temp != NULL) && (temp->getTitle() != t))
        temp = temp->getNext();
    //If the temporary BookNode is not null return it
    if(temp != NULL)
        return temp;
    else
        return NULL;
}

//Used in input 3 for for searching the list for the author input.
void Library::searchAuthor(const string a)
{
    //Set a temporary value equal to the head of the list
    BookNode *temp = Head;
    //Walk the list until you hit null or find the author
    while((temp != NULL) && (temp->getAuthor() != a))
        temp = temp->getNext();
    //If the temporary BookNode is null we need to print all the books that author has
    if(temp != NULL)
    {
        cout << "The following titles by " << a << " are currently in stock:\n";
        //While the author still has a book we need to print it
        while(temp->getAuthor() == a)
        {
            cout << "\t";
            temp->print();
            temp = temp->getNext();
            // In case the author is the last in the linked list
            if (temp == NULL)
                break;
        }
    }
    //If author is not in the linked list
    else
    {
        cout << "There are no titles by " << a << endl;   
    }
}

//Library class print function
void Library::print()
{
    cout << "The library currently has the following books in stock:\n";
    //Set a temporary value equal to the head of the list
    BookNode *temp = Head;
    //While not at the end of the list, print out all books in the libraries' linked list
    while (temp != NULL)
    {
        cout << "\t";
        temp->print();
        temp = temp->getNext();
    }
}