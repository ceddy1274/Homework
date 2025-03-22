#include <iostream>

using namespace std;

class Dog
{
    public:
        //constructors
        Dog(); 
        ~Dog(); 
        Dog(const Dog &copyme);
        Dog(const string n, const float a, const string b, const float s, const int e);
        
        //setters
        void setName(string n);
        void setBreed(string b);
        void setAge(float a);
        void setSize(float s);
        void setEnergy(int e);
        void setNext(Dog *Next);
        
        //getters
        string getName() const;
        string getBreed() const;
        float getAge() const;
        float getSize() const; 
        int getEnergy() const;
        Dog* getNext() const;
        
        //other methods
        void print() const;
        
    //dog variables
    private:
        string name;
        string breed;
        float age;
        float size;
        int energy;
        Dog *next;
};