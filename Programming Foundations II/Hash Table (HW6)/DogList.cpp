#include "DogList.h"
#include <fstream>
using namespace std;

//constructor
DogList::DogList()
{
    Head = NULL;
}

//destructor
DogList::~DogList()
{
    //walk list deleting nodes
    Dog * temp = Head;
    while (temp != NULL)
    {
       Head = Head->getNext();
       delete temp;
       temp = Head;
    }
}

//sorted insert by dog name
bool DogList::insert(const string name, const float age, const string breed, const float size, const int energy)
{
    //set collision to be false in beggining
    bool collision = false;
    //set a temp variable equal to the head of the list
    Dog *temp = Head;
    //while the temp node is not null and the name of that dog plus its breed is not in the list
    while(temp != NULL && (temp->getName() + temp->getBreed() != name + breed))
    {
        //increment collisionCount and countinue walking the list
        collisionCount += 1;
        temp = temp->getNext();
    }
    //this means the dog is all ready in the list 
    if(temp != NULL)
        collisionCount = 0;
    //else insert new dog
    else
    {
        collision = true;
        temp = new Dog(name, age, breed, size, energy);
        temp->setNext(Head);
        Head = temp;
    }
    return collision;
}

//search DogList
bool DogList::search(const string word)
{
    //walk list
    Dog *temp = Head;
    while(temp != NULL && (temp->getName() + temp->getBreed() != word))
        temp = temp->getNext();
    //if found print the node
    if(temp != NULL)
    {
        temp->print();
        return true;
    }
    return false;
}

//delete a dog record
bool DogList::del(const string word)
{
    //walk dog list to find the node
    Dog *prev = NULL;
    Dog *curr = Head;
    while(curr != NULL && (curr->getName() + curr->getBreed() != word))
    {
        prev = curr;
        curr = curr->getNext();
    }
    //if node is found, delete the node
    if(curr != NULL)
    {
        if(prev == NULL)
        {
            Head = curr->getNext();
            curr = NULL;
        }
        else
        {
            //For the node previous to the node being deleted
            //We need to change its next node
            //So we set the previous node's next pointer to be the deleted node's next
            string name = curr->getName();
            string breed = curr->getBreed();
            prev->setNext(curr->getNext());
            curr = NULL;
            cout << name << ", who is a " << breed << " was deleted.\n";
        }
        return true;
    }
    return false;
}

//print the dog list
void DogList::ListPrint(ofstream &outFile)
{
    //walk through doglist and print in output file
    Dog *temp = Head;
    while(temp != NULL)
    {
        outFile << temp->getName() << "," 
        << temp->getAge() << "," 
        << temp->getBreed() << ","
        << temp->getSize() << ","
        << temp->getEnergy() << endl;
        temp = temp->getNext();
    }
}

//return number of collisions variable
int DogList::getCollisions()
{
    return collisionCount;   
}