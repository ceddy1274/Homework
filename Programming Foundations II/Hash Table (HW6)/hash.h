//-----------------------------------------------------------
//  Purpose:    Header file for the HashTable class.
//  Author:     Cameron Eddy
//-----------------------------------------------------------
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "DogList.h"
using namespace std;

//-----------------------------------------------------------
// Define the HashTable class interface
//-----------------------------------------------------------
class HashTable
{
    public:
       // Constructors
       HashTable(int size);
       ~HashTable();

       // Methods
       bool Insert(string word, const string name, const float age, const string breed, const float size, const int energy);
       bool Search(string word);
       bool Delete(string word);
       void Print(ofstream &outFile);
       int hashFunction1(string word);
       int hashFunction2(string word);
       int hashFunction3(string word);
       int Collisions(string word);

    private:
       // Private data
       int Size;
       DogList *Table;
};