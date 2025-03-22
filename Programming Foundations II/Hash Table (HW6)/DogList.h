#include "Dog.h"

class DogList
{
    public:
        //constructors
        DogList();
        ~DogList();
        
        //methods
        bool insert(const string name, const float age, const string breed, const float size, const int energy);
        bool search(const string word);
        bool del(const string word);
        void ListPrint(ofstream &outFile);
        int getCollisions();
        
    private:
        Dog * Head;
        int collisionCount;
};