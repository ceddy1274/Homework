/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "hash.h"

ifstream inFile;

// Size of ht
const int SIZE = 750000;

// function to open dog file
bool opendogfile(const string filename, HashTable &ht, int &collision)
{
    //set collision to 0
    collision = 0;
    
    //intalizing variables needed for the function
    string name, breed, a, s, e;
    float age, size;
    int energy;
    
    //open the file
    inFile.open(filename);
    //make sure the file is opened, if not tell the user there was en error
    if(inFile.fail())
    {
        cout << "Error in loading the file\n";
        return false;
    }
    else
    {
        //load dogs into file
        while(!inFile.eof())
        {
            getline(inFile, name, ',');
            getline(inFile, a, ',');
            getline(inFile, breed, ',');
            getline(inFile, s, ',');
            getline(inFile, e);
            age = stof(a);
            size = stof(s);
            energy = stoi(e);
            
            string word = name+breed;
            //pass in name, age, breed, size, and energy
            ht.Insert(word, name, age, breed, size, energy);
            collision += ht.Collisions(word);
        }
        //close file
        inFile.close();
    }
    return true;
}

int main()
{
    //DONE: Implement Algorithim for hash table (seperate chaining)
    //DONE: Three string hashing functions (name-breed key) (dog object value)
    //(Need array of strings and an array of dog objects)
    //DONE: Caculation of collision statistics
    
    //HashTable
    HashTable ht(SIZE);
    
    //Filename
    string filename;
    cout << "What file do you want to open?\n";
    cin >> filename;
    
    //Intailize collision variables
    int collision;
    
    //Open file and print output file
    if(opendogfile(filename, ht, collision))
    {
        if(filename == "dogs.txt")
        {
            //Search for first dog in dogs.txt
            string first = "Beargoldendoodle";
            if(!ht.Search(first))
                cout << "Dog not found\n";
            //Delete the dog then prove search says it can't be found after deleting it
            if(!ht.Delete(first))
                cout << "Dog couldn't be deleted, prehaps its not in the daycare\n";
            if(!ht.Search(first))
                cout << "Dog not found\n";
            
            //Delete middle dog in dogs.txt
            string middle = "Carmen Lydiadachshund";
            if(!ht.Delete(middle))
                cout << "Dog couldn't be deleted, prehaps its not in the daycare\n";
                
            //Delete last dog in dogs.txt
            string last = "Remibernedoodle dog";
            if(!ht.Delete(last))
                cout << "Dog couldn't be deleted, prehaps its not in the daycare\n";
        }
        ofstream outFile;
        outFile.open("output.txt");
        if(outFile.fail())
            cout << "Opening outfile failed\n";
        ht.Print(outFile);
        outFile.close();
        cout << "Collisions: " << collision << endl;
    }
    
     
    //Closing statement
    std::cout<<"Is the class over yet?\n";
    return 0;
}