#include "Dog.h"

//default constructor
Dog::Dog()
{
    name = "";
    breed = "";
    age = 0;
    size = 0;
    energy = 0;
    next = NULL;
}

//deconstructor
Dog::~Dog()
{
    name = "";
    breed = "";
    age = 0;
    size = 0;
    energy = 0;
    next = NULL;
} 

//copy constructor
Dog::Dog(const Dog &copyme)
{
    name = copyme.name;
    breed = copyme.breed;
    age = copyme.age;
    size = copyme.size;
    energy = copyme.energy;
    next = copyme.next;
}

//parameterized constructor
Dog::Dog(const string n, const float a, const string b, const float s, const int e)
{
    name = n;
    breed = b;
    age = a;
    size = s;
    energy = e;
    next = NULL;
}

//name setter
void Dog::setName(string n) 
{
    name = n;
    
}

//breed setter
void Dog::setBreed(string b)
{
    breed = b;
    
}

//age setter
void Dog::setAge(float a)
{
    age = a;
    
}

//size setter
void Dog::setSize(float s)
{
    size = s;
}

//energy setter
void Dog::setEnergy(int e)
{
    energy = e;
}

//next setter
void Dog::setNext(Dog* Next)
{
    next = Next;
}

//name getter
string Dog::getName() const
{
    return name;
}

//name breed
string Dog::getBreed() const
{
    return breed;
}

//age getter
float Dog::getAge() const
{
    return age;
}

//size getter
float Dog::getSize() const 
{
    return size;
}

//energy getter
int Dog::getEnergy() const
{
    return energy;
}

//next getter
Dog* Dog::getNext() const
{
    return next;
}

//print
void Dog::print() const
{
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
    cout << "Age: " << age << endl;
    cout << "Size: " << size << endl;
}