/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//headers to include
#include <iostream>
#include <fstream>
#include <string>

//other things that are needed for code below to work
using namespace std;

//global size of array
const int SIZE = 50;
//STEP 1: Create global arrays to hold nouns, adjectives, and verbs
//intalize nouns, verbs, and adjectives array
string nouns[SIZE];
string verbs[SIZE];
string adjectives[SIZE];

//used for reading in nouns, verbs, and adjectives files into their respective arrays
void readFile(string arr[SIZE], const string filename, ifstream &inFile)
{
    //intalize a counter variable
    int i = 0;
    
    //open file
    inFile.open(filename);
        
    //loop until end of file taking each word from the file, adding it to the array, and then incrementing the index for the next word
    while(!inFile.eof())
    {
        inFile >> arr[i];
        i++;
    }
    
    //closing file
    inFile.close();
}

//function to iteratively read in file
void iterative(ifstream &inFile)
{
    //intalize word
    string word;
    //while not at the end of the file repeat
    while(inFile.peek() != EOF)
    {
        //generate random number between 0-49 for the indexes
        int num = rand() % 50;
        //get word from inFile
        inFile >> word;
        //find last index in the word
        int end = word.length()-1;
        //for potential punctuation marks
        string mark = "";
        //if the last character in the word is a punctuation and not a >
        if (ispunct(word.back()) && word.back() != '>')
        {
            //get the punctuation mark (we will readd it later)
            mark = word.back();
            //remove the punctuation for the if statement checks below
            word = word.replace(end, end, "");
        }
        //depending on what the word is, replace it with a word from its respective array
        if (word == "<noun>")
            word = nouns[num];
        else if (word == "<verb>")
            word = verbs[num];
        else if (word == "<adjective>")
            word = adjectives[num];
        //print the word with the punctuation mark(if one exists), plus a space
        cout << word + mark << " ";
    }
    //print out a new end line at the end of the mad lib for formatting purposes
    cout << endl;
}

//function to recursively read in the file
void recursive(ifstream &inFile)
{
    //intalize word
    string word;
    //generate random number between 0-49 for the indexes
    int num = rand() % 50;
    //get word from inFile
    inFile >> word;
    //find last index in the word
    int end = word.length()-1;
    //for potential punctuation marks
    string mark = "";
    //if the last character in the word is a punctuation and not a >
    if (ispunct(word.back()) && word.back() != '>')
    {
        //get the punctuation mark (we will readd it later)
        mark = word.back();
        //remove the punctuation for the if statement checks below
        word = word.replace(end, end, "");
    }
    //depending on what the word is, replace it with a word from its respective array
    if (word == "<noun>")
        word = nouns[num];
    else if (word == "<verb>")
        word = verbs[num];
    else if (word == "<adjective>")
        word = adjectives[num];
    //print the word with the punctuation mark(if one exists), plus a space
    cout << word + mark << " ";
    //if not at end of file recall the recursive function
    if(inFile.peek() != EOF)
        recursive(inFile);
    //print out a new end line at the end of the mad lib for formatting purposes
    else
        cout << endl;
}

int main()
{
    //intalize rand time
    srand((time(nullptr)));
    //DONE: Asks user which template they want to fill out (at least three scenarios)
    //DONE: Iteratively or Recursively 
    //DONE: Print madlib, ask if they want to do another or exit
    ifstream inFile;
    //read in the files to the respective arrays using the readFile function
    readFile(nouns, "nouns.txt", inFile);
    readFile(verbs, "verbs.txt", inFile);
    readFile(adjectives, "adjectives.txt", inFile);
    
    //loop until user quits the program
    while(true)
    {
        //STEP 2: User Menu (ask what scenario to run)
        cout << "1) sports.txt\n2) fairytale.txt\n3) work.txt\n(Enter the textfiles name as name.txt)\n";
        cout << "Which template would you like to fill out: ";
        //STEP 3: Open file with error checking
        //intalize filename
        string filename;
        //read in filename
        cin >> filename;
        //open the file
        inFile.open(filename);
        //if file couldn't be opened print error and exit the program
        if(inFile.fail())
        {
            cout << "Error in loading the file\n";
            break;
        }
        //STEP 4: Ask for Iteratively or Recursively call
        //intalize iterative or recursive call variable
        string call;
        //loop until user gives valid answer of whether they want an iterative or recursive call
        while(call != "i" && call != "r" && call != "I" && call != "R")
        {
            cout << "Recursive or iterative(type r or i): ";
            cin >> call;
        }
        
        
        //STEP 5: Write madlibs solver (one iterative other recursive)
            //use inFile >> variable
        
        //STEP 6: Create recursive algorithim (ifstream or string)
        if(call == "r" || call == "R")
            recursive(inFile);
        //STEP 7: Iterative algorithim
        else if(call == "i" || call == "I")
            iterative(inFile);
        
        //Step 8: Close file, ask to restart or quit
        inFile.close();
        //intalize answer variable
        string answer; 
        //Loop until user gives valid answer of either q or r case insensitive
        while(answer != "q" && answer != "r" && answer != "Q" && answer != "R")
        {
            cout << "Restart or quit(type q or r): ";
            cin >> answer;
        }
        //If user chose to quit exit the program
        if(answer == "q" || answer == "Q")
        {
            break;
        }
    }
    
    //print statement at end to make sure the program worked
    std::cout<<"You can be on the council, but we don't grant you the rank of master\n";
    return 0;
}
