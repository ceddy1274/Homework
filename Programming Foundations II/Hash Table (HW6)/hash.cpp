//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     Cameron Eddy
//-----------------------------------------------------------
#include "hash.h"

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
   Size = size;
   Table = new DogList[size];
}


//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
   Size = 0;  
   delete [] Table;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(string word, string name, float age, string breed, float size, int energy)
{
   // Find hash index
   //pass in name, etc.
   int index = hashFunction2(word);
   return Table[index].insert(name, age, breed, size, energy);
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(string word)
{
    int index = hashFunction2(word);
    return Table[index].search(word);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(string word)
{
    int index = hashFunction2(word);
    return Table[index].del(word);
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print(ofstream &outFile)
{
    for(int i = 0; i < Size; i++)
        Table[i].ListPrint(outFile);
}

//-----------------------------------------------------------
// HashFunction1
//-----------------------------------------------------------
int HashTable::hashFunction1(string word)
{
    int hash = 0;
    int wordLength = word.length();
    // hash == sum of word's ascii characters % SIZE
    for (int i = 0; i < wordLength; i++)
	    hash += word[i];
    hash = hash % Size;
    return hash;
}

//-----------------------------------------------------------
// HashFunction2
//-----------------------------------------------------------
int HashTable::hashFunction2(string word)
{
    int hash = 1;
    int wordLength = word.length();
    // hash == word's length % by the size
    for(int i = 0; i < wordLength; i++)
        hash += i;
    hash = hash % Size;
    return hash;
}

//-----------------------------------------------------------
// HashFunction3(from Gauch's slides)
//-----------------------------------------------------------
int HashTable::hashFunction3(string word)
{
    int hash = 0;
    int wordLength = word.length();
    // hash == letters as digits base 26 % by the size
    for (int i = 0; i < wordLength; i++)
    	hash = 26 * hash + tolower(word[i]) - 'a';
    hash = hash % Size;
    return hash;
}

//-----------------------------------------------------------
// Collisions function to track Collisions
//-----------------------------------------------------------
int HashTable::Collisions(string word)
{
    int index = hashFunction2(word);
    return Table[index].getCollisions();
}