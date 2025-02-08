/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    //Print title of program
    cout << "\n\n\n\t\tBook Genre Selection Menu\n\n" << endl;
    
    //Genre selection menu
    //Intialize genres
    int fiction = 1;
    int non_fiction = 2;
    int sci_fiction = 3;
    int history = 4;
    int genre;
    string format;
    string price;
    //Print genres to screen
    cout << "\tFiction -------------------------------- 1\n";
    cout << "\tNon-Fiction ---------------------------- 2\n";
    cout << "\tScience Fiction ------------------------ 3\n";
    cout << "\tHistory -------------------------------- 4\n\n\n";
    //Ask user what genre they want
    cout << "What genre do you want: ";
    cin >> genre;
    //error checking for genre input
    if (genre != 1 && genre != 2 && genre != 3 && genre != 4) 
    {
        cout << "Sorry we don't carry that genre";
        return 1;
    }
    //Book format selection
    cout << "Would you like a hard copy or a paper copy (Type P/p for paperback and H/h for hardcopy): ";
    cin >> format;
    //error checking for format input
    if (format == "p" || format == "P")
    {
        format = "paperback";
    }
    else if (format == "h" || format == "H")
    {
        format = "hardcopy";
    }
    else
    {
        cout << "We don't have that format";
        return 1;
    }
    //Pricing information
    //Switch statement for genre
    switch (genre)
    {
        //for fiction
        case 1:
        if (format == "paperback")
        {
            price = "$12";
        }
        else 
        {
            price = "$20";
        }
        cout << "You selected fiction with a " << format << " cover, you owe: " << price;
        break;
        
        //for non-fiction
        case 2:
        if (format == "paperback")
        {
            price = "$15";
        }
        else 
        {
            price = "$25";
        }
        cout << "You selected non-fiction with a " << format << " cover, you owe: " << price;
        break;
        
        //for science fiction
        case 3:
        if (format == "paperback")
        {
            price = "$10";
        }
        else 
        {
            price = "$18";
        }
        cout << "You selected science fiction with a " << format << " cover, you owe: " << price;
        break;
        
        //for history
        case 4:
        if (format == "paperback")
        {
            price = "$14";
        }
        else 
        {
            price = "$22";
        }
        cout << "You selected history with a " << format << " cover, you owe: " << price;
        break;
        
        //just in case the user inputted something that was incorrect and wasn't caught in the earlier if statments
        default:
        cout << "There was an error somewhere";
        return 1;
    }
    
    return 0;
}

