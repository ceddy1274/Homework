#include <iostream>
using namespace std;

class Dog
{
    public:
        Dog(); //default constructor
        ~Dog(); //deconstructor
        Dog(const Dog &copyme); //copy constructor
        Dog(const string n, const float a, const string b, const float s, const int e); //parameterized constructor
        
        //setters
        void setName(string n);
        void setBreed(string b);
        void setAge(float a);
        void setSize(float s);
        void setEnergy(int e);
        
        //getters
        string getName() const;
        string getBreed() const;
        float getAge() const;
        float getSize() const; 
        int getEnergy() const;
        
        //other methods
        void print() const;
        
    //dog variables
    private:
        string name;
        string breed;
        //age in dog years (this is a joke) (also I choose float over integer incase they are an age such as 6 months old)
        float age;
        //size in pounds
        float size;
        int energy;
};