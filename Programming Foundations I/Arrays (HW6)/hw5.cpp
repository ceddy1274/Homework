/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
//I included this library to reset my array.  I figured out how to do this by looking it up from this link: https://www.geeksforgeeks.org/how-to-reset-int-array-to-zero-in-cpp/
#include <cstring>
using namespace std;

//ask user how many sides they want and return an error if less than 1
void getSides(int &sides)
{
   cout << "How many sides do you want your dice to have: ";
   cin >> sides;
   while(sides < 1)
   {
        cout << "Dice must have at least one side, try again: " ;
        cin >> sides;
   }
}

//ask user how many dice they want to roll and return an error if less than 1
void getDice(int &dice)
{
   cout << "How many dice do you want to roll: ";
   cin >> dice;
   while(dice < 1)
   {
        cout << "You must have at least one dice, try again: ";
        cin >> dice;
   }  
}

//ask user how many rolls they want and return an error if less than 1
void getRolls(int &rolls)
{
   cout << "How many dice rolls do you want: ";
   cin >> rolls;
   while(rolls < 1)
   {
        cout << "You musy roll at least once, try again: ";
        cin >> rolls;
   } 
}

//takes in rollsArray by reference and sides, dice, and rolls by value to caculate 
//the number of times each number is lannded on in the given amount of rolls
void simulateRolls(int rollsArray[], const int sides, const int dice, const int rolls)
{
    int counter = 0;
    //I found the srand function from programming assignment 3
    srand((time(nullptr)));
    do {
        int rollTotal= 0;
        int rollNum = 0;
        int rollIndex = 0;
        for (int i = 0; i < dice; i++)
        {
            rollNum = (rand() % sides) + 1;
            rollTotal += rollNum;
        }
        counter += 1;
        rollIndex = rollTotal-dice;
        rollsArray[rollIndex] += 1;
    } while (counter < rolls);
}

int main()
{
   //intalize variables for user input
   int sides;
   int dice;
   int rolls;
   
   //get user input needed
   getSides(sides);
   getDice(dice);
   getRolls(rolls);
   
   //intalize array length and array itself
   int length = dice*sides-(dice-1);
   int rollsArray[length] = {};
   
   //simulate dice roll
   simulateRolls(rollsArray, sides, dice, rolls);
   
   //print row headers
   cout << "\nHere are the  simulation results from rolling a " << dice << "d" << sides << " " << rolls << " time(s):\n";
   cout << "Row Total\t" << "Count\t" << "Percentage\n";
   //intalize variables needed for finidng percentages, most rolled dice number, and if there was a tie
   int row;
   int mostRolled;
   float tempPercent;
   int winners[length] = {};
   bool tie;
   //for loop to find percentage of each dice number rolled
   for (int i = 0; i < length; i++)
   {
       //changed number in rollsArray to a float so percentage would be a float
       float num = rollsArray[i];
       float Percentage = num/rolls;
       //needed to add i+dice so range will be from number of dice to number of dice mutipled by the number of sides
       row = i+dice;
       //print each individual row
       cout << row << "\t\t" << rollsArray[i] <<  "\t" << fixed << setprecision(5) << Percentage << "\n";
       //checks to see which percentage is the highest
       if (tempPercent < Percentage)
       {
           //set new highest Percentage
           tempPercent = Percentage;
           //reset winners array so no winner yet because a new highest percentage has just been found
           //(memset and sizeof I had to look up inorder to reset the array)
           memset(winners, 0, sizeof(winners));
           //sets the location of the winner in the winners array
           winners[i] +=1;
           tie = false;
       }
       //in cases where there are mutiple winners we need mutiple places in the array with a value of one to indicate mutiple winners
       else if (tempPercent == Percentage)
       {
           winners[i] +=1;
           tie = true;
       }
   }
   //intalize a num variable used in both conditional statements to find the number of dice rolled at the most common number(s)
   int num = 0;
   //checks if there was a tie first and if so prints all numbers that were marked as being the most common
   if (tie == true)
   {
       cout << "The numbers that appeared the most were";
       for (int i = 0; i < length; i++)
       {
            if (winners[i] == 1)
            {
                num = rollsArray[i];
                cout << " " << i+dice;
            }
       }
       cout << " with " << num << " roll(s)";
   }
   //for case with only one winner
   else
   {
        for (int i = 0; i < length; i++)
        {
            num = rollsArray[i];
            if (winners[i] == 1)
            {
                cout << "The most rolled number was " << i+dice << " with " << num << " roll(s)";
            }
        }
   }
}

