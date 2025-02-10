/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************
Purpose:    Function Recommendations for a space trip planner
Author:     Cameron Eddy
Date:       03/14/2024    
*******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//global variables
const char MERCURY = 'M';
const char VENUS = 'V';
const char MARS = 'R';
const char JUPITER = 'J';
const char SATURN = 'S';
const char URANUS = 'U';
const char NEPTUNE = 'N';
const char INNER = 'I';
const char OUTER = 'O';
const float BASE_COST_INNER = 10000.00;
const float BASE_COST_OUTER = 40000.00;
const float SIZE_UPCHARGE = 1000.00;
const float UPGRADE_COST = 2000.00;
const float ACTIVITY_COST = 1000.00;
const float DISCOUNT = 3000.00;

//----------------------------------------------------------------------
//Function: setDestination
//Purpose: To get the user's destination choice
//Parameters: char &destinationChoice, char &destinationType
//Returns: N/A
//----------------------------------------------------------------------
void setDestination(char &destinationChoice, char &destinationType)
{
    //get type of destination
    cout << "What type of destination are you planning to visit? Type (I) for inner or (O) for outer." << endl;
    cin >> destinationType;
    destinationType = toupper(destinationType);

    // error checking for destinationType
    while(destinationType != INNER && destinationType != OUTER)
    {
        cout << "Invalid choice! Try again." << endl;
        cin >> destinationType;
        destinationType = toupper(destinationType);
    }
    
    //get destinationChoice
    if(destinationType == INNER)
    {
        cout << "\nWhich destination would you like to plan for?" << endl;
        cout << "<\tM ~ for Mercury                     $10000.00       >" << endl;
        cout << "<\tV ~ for Venus                       $10000.00       >" << endl;
        cout << "<\tR ~ for Mars                        $10000.00       >" << endl;
    }
    
    if(destinationType == OUTER)
    {
        cout << "<\tJ ~ for Jupiter                     $40000.00       >" << endl;
        cout << "<\tS ~ for Saturn                      $40000.00       >" << endl;
        cout << "<\tU ~ for Uranus                      $40000.00       >" << endl;
        cout << "<\tN ~ for Neptune                     $40000.00       >" << endl;
    }
  
    cin >> destinationChoice; //get input 
    destinationChoice = toupper(destinationChoice);
  
    while ((destinationType == INNER && (destinationChoice != MERCURY && destinationChoice != VENUS && destinationChoice != MARS)) ||
       (destinationType == OUTER && (destinationChoice != JUPITER && destinationChoice != SATURN && destinationChoice != URANUS && destinationChoice != NEPTUNE)))
    {
        if(destinationType == INNER){
            // Display error message and available choices
            cout << "\nOops! Your choice is not included in the list. Try again." << endl;
            cout << "\nWhich destination would you like to plan for?" << endl;
            cout << "<\tM ~ for Mercury                     $10000.00       >" << endl;
            cout << "<\tV ~ for Venus                       $10000.00       >" << endl;
            cout << "<\tR ~ for Mars                        $10000.00       >" << endl;
        }
        if (destinationType == OUTER)
        {
            cout << "\nOops! Your choice is not included in the list. Try again." << endl;
            cout << "<\tJ ~ for Jupiter                     $40000.00       >" << endl;
            cout << "<\tS ~ for Saturn                      $40000.00       >" << endl;
            cout << "<\tU ~ for Uranus                      $40000.00       >" << endl;
            cout << "<\tN ~ for Neptune                     $40000.00       >" << endl;
        }

    // Get input again
    cin >> destinationChoice;
    destinationChoice = toupper(destinationChoice);
    }
}

//----------------------------------------------------------------------
//Function: setTripDuration
//Purpose: To determine the duration of the trip
//Parameters: N/A
//Returns: int - selected trip duration
//----------------------------------------------------------------------
int setTripDuration() 
{
    int tripDuration;
    cout << "How long do you want your trip to be?\n";
    cin >> tripDuration;
    while (tripDuration < 1) {
        cout << "Your trip has to be at least one day long, try again.\n";
        cin >> tripDuration;
    }
    if (tripDuration == 1) {
        cout << "Your trip will be " << tripDuration << " day long\n";
    }
    else {
        cout << "Your trip will be " << tripDuration << " days long\n";
    }
    return tripDuration;
}

//----------------------------------------------------------------------
//Function: addUpgrade
//Purpose: Ask user whether or not they want to upgrade their trip
//Parameters: bool &upgrade
//Return: N/A
//----------------------------------------------------------------------
void addUpgrade(bool &upgrade) {
    char value;
    cout << "Do you want to upgrade your trip to first class for $2000? (Y/N)\n";
    cin >> value;
    value = toupper(value);
    while (value != 'Y' && value != 'N') {
        cout << "The value you input was not 'Y' or 'N', try again\n";
        cin >> value;
        value = toupper(value);
    }
    if (value == 'N')
    {
        upgrade = false;
    }
    else 
    {
        upgrade = true;
    }
}

//----------------------------------------------------------------------
//Function: addInsurance
//Purpose: Ask user whether or not they want to add insurance to their trip
//Parameters: bool &insurance
//Return: N/A
//----------------------------------------------------------------------
void addInsurance(bool &insurance) {
    char value;
    cout << "Do you want to add insurance to your trip for $1000? (Y/N)\n";
    cin >> value;
    value = toupper(value);
    while (value != 'Y' && value != 'N') {
        cout << "The value you input was not 'Y' or 'N', try again\n";
        cin >> value;
        value = toupper(value);
    }
    if (value == 'N')
    {
        insurance = false;
    }
    else 
    {
        insurance = true;
    }
}

//----------------------------------------------------------------------
//Function: addExtra
//Purpose: Ask user whether or not they want to add any extra activities to their trip
//Parameters: bool &extra, const char destination
//Return: N/A
//----------------------------------------------------------------------
void addExtra(bool &extra, const char destination) {
    switch (destination) {
        case 'M':
            cout << "Do you want to add a surface exploration on Mercury to your trip for $1000? (Y/N)\n";
            break;
        case 'V':
            cout << "Do you want to add an atmospheric balloon ride on Venus to your trip for $1000? (Y/N)\n";
            break;
        case 'R':
            cout << "Do you want to add a rover exploration on Mars to your trip for $1000? (Y/N)\n";
            break;
        case 'J':
            cout << "Do you want to add an equator tour on Jupiter to your trip for $1000? (Y/N)\n";
            break;
        case 'S':
            cout << "Do you want to add a ring excursion on Saturn to your trip for $1000? (Y/N)\n";
            break;
        case 'U':
            cout << "Do you want to add the moons visit on Uranus to your trip for $1000? (Y/N)\n";
            break;
        case 'N':
            cout << "Do you want to add a deep space exploration on Neptune to your for $1000? (Y/N)\n";break;
            break;
        //incase for some reason the planet the user inut failed earlier error checking
        default:
            cout << "For some reason the planet you want to visit is not one we offer, sorry we don't offer Pluto anymore.  "; 
            cout << "\nTry running the program again\n";
            break;
    }
    char value;
    cin >> value;
    value = toupper(value);
    while (value != 'Y' && value != 'N') {
        cout << "The value you input was not 'Y' or 'N', try again\n";
        cin >> value;
        value = toupper(value);
    }
    if (value == 'N')
    {
        extra = false;
    }
    else 
    {
        extra = true;
    }
}

//----------------------------------------------------------------------
//Function: addMore
//Purpose: Ask user whether or not they want to add more destinations to their trip
//Parameters: None
//Return: bool - true if they want to add more, otherwise false
//----------------------------------------------------------------------
bool addMore() {
    char value;
    cout << "Do you want to add more destinations to your trip\n";
    cin >> value;
    value = toupper(value);
    while (value != 'Y' && value != 'N') {
        cout << "The value you input was not 'Y' or 'N', try again\n";
        cin >> value;
        value = toupper(value);
    }
    if (value == 'N')
    {
        value = false;
    }
    else 
    {
        value = true;
    }
    return value;
}

//----------------------------------------------------------------------
//Function: getDiscount
//Purpose: give the customer a $3000 discount if they book multiple destinations
//Parameter: int numDestinations
//Return: float - discount amount
//----------------------------------------------------------------------
float getDiscount(int numDestinations) {
    if (numDestinations > 2)
    {
        return DISCOUNT;
    }
    return 0;
}

//----------------------------------------------------------------------
//Function: getTripCost
//Purpose: To calculate cost of a trip and add to subtotal
//Parameters:  const char destination, const int duration, const bool upgrade, const bool insurance, const bool extra 
//Returns: float - cost of the trip
//----------------------------------------------------------------------
float getTripCost(const char destination, const int duration, const bool upgrade, const bool insurance, const bool extra)
{
    float cost = 0;
    
    //add base cost of destination choice
    if(destination == INNER)
        cost += BASE_COST_INNER;
    else if (destination == OUTER)
        cost += BASE_COST_OUTER;
    
    //add upcharge for longer duration   
    cost += (duration - 1) * SIZE_UPCHARGE; // $1000 per additional day
    
    //add upcharge for upgrade
    if(upgrade)
        cost += UPGRADE_COST;
    
    //add insurance cost
    if(insurance)
        cost += 1000.00;
    
    //add extra activity cost
    if(extra)
        cost += ACTIVITY_COST;
    
    return cost;
}


//----------------------------------------------------------------------
//Function: reset
//Purpose: Resets local trip variables
//Parameters:   char &destinationChoice, int &tripDuration, char &destinationType, 
// bool &extra, bool &upgrade, bool &insurance, float &tripCost
//Return: N/A
//----------------------------------------------------------------------
void reset(char &destinationChoice, int &tripDuration, char &destinationType, 
bool &extra, bool &upgrade, bool &insurance, float &tripCost) {
    destinationChoice;
    destinationType;
    tripDuration;
    upgrade;
    insurance;
    extra;
    tripCost;
}

//----------------------------------------------------------------------
//Function: confirmTrip
//Purpose: to confirm the trip details before calculating the total cost
//Parameters: const char destination, const int duration, const char type, const bool extra
//Return: bool - confirms all selection are correct
//----------------------------------------------------------------------
bool confirmTrip(const char userDestination, const char userType, const int userDuration, const bool userExtra)
{
    string confirmedDestination, confirmedType, confirmedExtra;
    char choice;
    
    cout << "Let's make sure the trip details are correct." << endl;
    
    switch(userDestination)
    {
        case MERCURY: 
            confirmedDestination = "Mercury"; 
            if(userExtra)
                confirmedExtra = "surface exploration";
            break;
        case VENUS: 
            confirmedDestination = "Venus"; 
            if(userExtra)
                confirmedExtra = "atmospheric balloon ride";
            break;
        case MARS: 
            confirmedDestination = "Mars"; 
            if(userExtra)
                confirmedExtra = "rover exploration";
            break;
        case JUPITER: 
            confirmedDestination = "Jupiter"; 
            if(userExtra)
                confirmedExtra = "equator tour";
            break;
        case SATURN: 
            confirmedDestination = "Saturn"; 
            if(userExtra)
                confirmedExtra = "ring excursion";
            break;
        case URANUS: 
            confirmedDestination = "Uranus"; 
            if(userExtra)
                confirmedExtra = "moons visit";
            break;
        case NEPTUNE: 
            confirmedDestination = "Neptune"; 
            if(userExtra)
                confirmedExtra = "deep space exploration";
            break;
    }
    
    if (userType == INNER)
        confirmedType = "inner";
    else
        confirmedType = "outer";
    
    if(userExtra)    
        cout << "You have planned a " << confirmedType << " trip to " << confirmedDestination << " with an additional " << confirmedExtra << "." << endl;
    else 
        cout << "You have planned a " << confirmedType << " trip to " << confirmedDestination << "." << endl;
        
    //check with user if everything is correct
	cout << "If everything seems correct, type (Y) for yes. Otherwise, type (N) for no." << endl;
	cin >> choice;
	choice = toupper(choice);
	while(choice != 'Y' && choice != 'N')
	{
		cout << "You entered an invalid input. Try again." << endl;
		cin >> choice;
		choice = toupper(choice);
	}

	//return true if Y
	if (choice == 'Y')
		return true;
	else
		return false;    
}

//----------------------------------------------------------------------
//Function: printBill
//Purpose: print item quantity, subtotal, and total for the trip
//Parameters: const float subtotal, const int quantity
//Return: N/A
//----------------------------------------------------------------------

int main ()
{
    //Counter is used as a counter to keep the loop.  At the begging of each trip 1 is subtracted,
    //but if the user wants to add more trips, trips will equal 1 to continue the loop
    int counter = 1;
    //Trips is used to count how many trips the user has done for discount purposes
    int trips = 0;
    //declaration of local variables to be used in funtions
    char destinationChoice;
    char destinationType;
    int tripDuration;
    bool upgrade;
    bool insurance;
    bool extra;
    bool value;
    float tripCost;
    
    do {
        //bill variables
        float subtotal = 0;
        float discount = 0;
        float total = 0;
        //subtracting 1 from counter and adding 1 to trips
        counter -= 1;
        trips += 1;
        //reset variables
        reset(destinationChoice, tripDuration, destinationType, upgrade, insurance, extra, tripCost);
        //set users destination
        setDestination(destinationChoice, destinationType);
        //set users trip duration
        tripDuration = setTripDuration();
        //see if user wants to upgrade their trip
        addUpgrade(upgrade);
        //see if user wants to add insurance
        addInsurance(insurance);
        //see if user wants to add extra activities to their trip
        addExtra(extra, destinationChoice);
        //calculate the cost of the trip
        tripCost = getTripCost(destinationType, tripDuration, upgrade, insurance, extra);
        //calculating subtotal
        subtotal += tripCost;
        //see if user got a discount and add it to discount if so
        discount += getDiscount(trips);
        //calculate total
        total += tripCost - discount;
        //print out bill
        cout << endl << "-------------------------------------\n";
        cout << "\tNumber of destinations: " << trips << endl;
        cout << "\tSubtotal: $" << subtotal << ".00" << endl;
        cout << "\tDiscount: $" << discount << ".00" << endl;
        cout << "\tTotal: $" << total <<".00"<<endl;
        cout << "-------------------------------------\n";
        //ask user if they want to confirm their trip
        if (confirmTrip(destinationChoice, destinationType, tripDuration, extra) == true)
        {
            //ask user if they want to add more destinations to their trip
            value = addMore();
            //add 1 to counter to continue the loop if the user wants to add more trips
            if (value) 
            {
                counter += 1;
            }
        }
        else
        {
            continue;
        }
        
    } while(counter == 1);
    
}
