#include "Dog.h"

//DONE: implement constructors

Dog::Dog()
{
    name = "";
    breed = "";
    age = 0;
    size = 0;
    energy = 0;
}; //default constructor

Dog::~Dog()
{
    name = "";
    breed = "";
    age = 0;
    size = 0;
    energy = 0;
}; //deconstructor

Dog::Dog(const Dog &copyme)
{
    name = copyme.name;
    breed = copyme.breed;
    age = copyme.age;
    size = copyme.size;
    energy = copyme.energy;
    cout << "Copy\n";
}; //copy constructor

Dog::Dog(const string n, const float a, const string b, const float s, const int e)
{
    name = n;
    breed = b;
    age = a;
    size = s;
    energy = e;
    cout << "parameterized\n";
}; //parameterized constructor

//DONE: implement setters
void Dog::setName(string n) 
{
    name = n;
    
}; //name setter

void Dog::setBreed(string b)
{
    breed = b;
    
}; //breed setter

void Dog::setAge(float a)
{
    age = a;
    
}; //age setter

void Dog::setSize(float s)
{
    size = s;
}; //size setter

void Dog::setEnergy(int e)
{
    energy = e;
}; //energy setter

//DONE: implement getters
string Dog::getName() const
{
    return name;
}; //name getter

string Dog::getBreed() const
{
    return breed;
}; //name breed

float Dog::getAge() const
{
    return age;
}; //age getter

float Dog::getSize() const 
{
    return size;
}; //size getter

int Dog::getEnergy() const
{
    return energy;
}; //energy getter

//DONE: implement other methods
void Dog::print() const
{
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
    cout << "Age: " << age << endl;
    cout << "Size: " << size << endl;
    cout << "Energy: " << energy << endl;
}; //print method
        