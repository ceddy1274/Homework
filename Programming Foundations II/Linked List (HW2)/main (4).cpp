/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include "Library.h"

int main()
{
    //DONE: Ask user for the name of the input file(include checkout and return data)
    //get input from user and check that the number they inputted is between 1 and 5
    string input;
    cout << "What file would you like to open: ";
    cin >> input;
    //open the file
    ifstream inFile;
    inFile.open(input);
    //make sure the file is opened, if not tell the user there was en error
    if(inFile.fail())
        cout << "Error in loading the file\n"; 
    else
    {
        //intalize variables
        Library book;
        int choice;
        while(inFile.peek() != EOF)
        {
            inFile >> choice;
            //DONE: 1)[Search and Update/Insert] Return a book
            if (choice == 1)
            {
                string title, author;
                inFile >> title;
                inFile >> author;
                //if not copies of book are in the system add the book to the linked list with one copy
                if(book.searchTitle(title) == NULL)
                {
                    book.insert(title, author);
                    cout << title << " by " << author << " has been returned; there is 1 copy available\n"; 
                }
                else
                {
                    BookNode *tmp = book.searchTitle(title);
                    tmp->returnBook(1);
                    cout << title << " by " << author << " now has " << tmp->getNumAvailable() << " copies\n";
                }
                cout << endl;
            }
            //DONE: 2)[Search and Update/Delete] Checkout a book
            else if (choice == 2)
            {
                string title, author;
                inFile >> title;
                inFile >> author;
                book.deleteNode(title, author);
                cout << endl;
            }
            //DONE: 3)[Search] Check for an author
            else if (choice == 3)
            {
                string author;
                inFile >> author;
                book.searchAuthor(author);
                cout << endl;
            }
            //DONE: 4)[Print] Print the list
            else if (choice == 4)
            {
                book.print();
                cout << endl;
            }
            //DONE: 5)[Destructor] Quit the program
            else if (choice == 5)
            {
                Library book2 = Library(book);
                cout << "Ending program\n";
            }
            //You never know...
            else
                cout << "Something was formatted incorrectily in your input file\n";
        }
    }
    return 0;
}
