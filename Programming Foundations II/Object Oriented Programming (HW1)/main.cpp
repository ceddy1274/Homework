/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Dog.h"

//DONE: name for file stream that will be used in input 1 and outfile stream in input 6
ifstream inFile;
ofstream outFile;
//constant variables
const int maxdogs = 20;

//function to open dog file for input 1
void opendogfile(const string filename, Dog dogs[])
{
    //intalizing variables needed for the function
    string name, breed, a, s, e;
    float age, size;
    int energy;
    //used as counter for seeing how many dogs are in the array
    int numDogs = 0;
    //open the file
    inFile.open(filename);
    //make sure the file is opened, if not tell the user there was en error
    if(inFile.fail())
        cout << "Error in loading the file\n"; 
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
            
            //finding spot is a bool that becomes false when a spot is found for the dog and is reset to true every time
            bool findingSpot = true;
            //check to make sure the spot being replaced doesn't already have a dog object in it, and that it loops until a spot is found for the dog
            while(findingSpot)
            {
                //check to see if the dog object at that index is blank or not
                if (dogs[numDogs].getName() == "")
                {
                    dogs[numDogs] = Dog(name, age, breed, size, energy);
                    findingSpot = false;
                }
                else
                    numDogs++;
            }
        }
        //close file
        inFile.close();
    }
}

//function to enroll dogs used in input 2
void enrollDog(Dog dogs[])
{
    //variables needed for the function
    string name, breed;
    float age, size;
    int energy;
    //bool that is used to check if there are spots available for the dog (used at end of function)
    bool emptyDogSpot;
    
    //gathering name input
    cout << "What is the name of your dog: ";
    //getline and cin.ignore() used to get input with spaces
    cin.ignore();
    getline(cin, name);
    
    //check to make sure the age is realistic (31.5 years is the oldest a dog has ever lived)
    do
    {
        //gathering age input
        cout << "What is the age of your dog: ";
        cin >> age;
    } while(age <= 0 || age > 32);
    
    //gathering breed input
    cout << "What is the breed of your dog: ";
    //getline and cin.ignore() used to get input with spaces
    cin.ignore();
    getline(cin, breed);
    
    //check to make sure the size is realistic (350 pounds is the biggest a dog has ever gotten)
    do
    {
        //gathering size input
        cout << "What is the size of your dog in pounds: ";
        cin >> size;
    } while(size < 1 || size > 350);
    
    //check to make sure energy is inbetween 1 and 10 inclusive
    do
    {
        cout << "What energy level does your dog have: ";
        cin >> energy;
    } while(energy < 1 || energy > 10);
    
    //loop over all dogs trying to find an empty dog spot, if one is not found error is thrown at user in later if statement
    for(int i = 0; i < maxdogs; i++)
    {
        //find first empty slot in dog list and print a dog for it
        if(dogs[i].getName() == "")
        {
            dogs[i] = Dog(name, age, breed, size, energy);
            dogs[i].print();
            emptyDogSpot = true;
            break;
        }
        //if no empty dog spot is found by the end of the loop this will still be false and a later if statment will let the user know
        else
        {
            emptyDogSpot = false;
        }
    }
    //if empty dog spot was never found, return a statment saying the doggy daycare is at full capacity
    if(emptyDogSpot == false)
    {
        cout << "The Doggy Daycare is at full capacity right now, you can't enroll your dog at this time\n";
    }
}

//function used to find dogs with a similar energy level for input 3
void findEnergyFriends(Dog dogs[])
{
    //intalize variables needed for the function
    int energy;
    int currentDogsEnergy;
    //bool used later to see if no similar energy dogs were found
    bool noFriends = true;
    
    //check to make sure energy is inbetween 1 and 10 inclusive
    do
    {
        cout << "What energy would you like to search for: ";
        cin >> energy;
    } while(energy < 1 || energy > 10);
    
    //loop over all dogs looking for one with a similar energy level
    for(int i = 0; i < maxdogs; i++)
    {
         //get currentDogsEnergy
         currentDogsEnergy = dogs[i].getEnergy();
         //long if statment but the first part finds dogs with an energy level in the range of +/- 1 and second part makes sure the energy is not 0 (aka not a blank dog object)
         if ((currentDogsEnergy < (energy+2)) && (currentDogsEnergy > (energy-2)) && (currentDogsEnergy != 0))
         {
            dogs[i].print();
            noFriends = false;
         }
    }
    //if no dogs with similar energy level were found send a message to the user
    if(noFriends)
    {
        cout << "No dogs were found in this energy level\n";
    }
}

//used to print information about all the dogs in input 4
void printDogs(Dog dogs[])
{
    for(int i = 0; i < maxdogs; i++)
    {
        //check to make sure dog item is not empty
        if(dogs[i].getName() == "")
        {
            break;
        }
        //else print the dog
        dogs[i].print();
    }
}

//used for copying dog objects into a new daycare object in input 5
void copy(Dog dogs[])
{
    //intalize dog 
    Dog copyDogs[maxdogs];
    
    //loop over size of both arrays and copy elements from first array into copy array
    for(int i = 0; i < maxdogs; i++)
    {
        //check to make sure dog item is not empty
        if(dogs[i].getName() == "")
        {
            break;
        }
        copyDogs[i] = Dog(dogs[i]);
    }
    //print all dogs so user can see that it was sucessfully copied
    printDogs(copyDogs);
}

//used for saving the file in input 6
void save(const string filename, Dog dogs[])
{
    //intalizing variables needed for the function
    string name, breed;
    float age, size;
    int energy;
    
    //open the file
    outFile.open(filename);
    //make sure the file is opened, if not tell the user there was en error
    if(outFile.fail())
        cout << "Error in loading the file\n"; 
    //if file is opened sucessfully, dogs array objects to the file
    else
    {
        //loop over all dog objects put them back into the file
        for (int i = 0; i < maxdogs; i++)
        {
            //check to make sure dog item is not empty
            if(dogs[i].getName() == "")
            {
                break;
            }
            //get all needed variables
            name = dogs[i].getName();
            age = dogs[i].getAge();
            breed = dogs[i].getBreed();
            size = dogs[i].getSize();
            energy = dogs[i].getEnergy();
            //add variables to the outfile
            outFile << name << "," << age << "," << breed << "," << size << "," << energy << endl;
        }    
    }
    //close file
    outFile.close();
}
int main()
{
    //DONE: dog array
    Dog dogs[maxdogs];
    
    //DONE: intalize filename
    string filename = "dogs.txt";
    while(true)
    {
        //DONE: menu
        cout << "Welcome to the Doggy Daycare! What would you like to do?\n";
        cout << "1. Load dogs from a file\n";
        cout << "2. Enroll a new dog in daycare\n";
        cout << "3. Display all dogs with a similar energy level to your pup\n";
        cout << "4. Print information about all currently enrolled dogs\n";
        cout << "5. Copy all dogs to a new daycare object\n";
        cout << "6. Quit (and save into the file)\n";
    
        //intalize integer for input and check to make sure input is between 1 and 6 inclusive
        int input;
        do {
            cin >> input;
        } while(input > 6 || input < 1);
    
        //switch statment for menu input
        switch (input)
        {
            //open the file
            case 1:
                opendogfile(filename, dogs);
                break;
            //enroll a new dog in doggy daycare else there will be an error
            case 2:
                enrollDog(dogs);
                break;
            case 3:
                findEnergyFriends(dogs);
                break;
            //print information about all currently enrolled dogs
            case 4:
                printDogs(dogs);
                break;
            //copy dogs array into copydog array
            case 5:
                copy(dogs);
                break;
            //save all files into specified filename
            case 6:
                save(filename, dogs);
                //return false to break while loop
                return false;
                break;
            //you never know
            default:
                cout << "Error\n";
                break;
        }
    }
    
    return 0;
}
