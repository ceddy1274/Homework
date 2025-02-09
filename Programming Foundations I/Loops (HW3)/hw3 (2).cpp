/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

int main() {
    //Variables needed for options
    int option;
    int value;
    //Prompt user for three options
    cout << "Where would you like your coffee shop\n" << endl;
    cout << "\t1) $250/month, Coffee truck\n";
    cout << "\t2) $500/month, In a retail store\n";
    cout << "\t3) $750/month, A shop in the downtown area\n" << endl;
    cout << "Which location would you like: ";
    cin >> option;
    cout << endl;
    //While loop for error checking
    while (option != 1 && option != 2 && option != 3) {
        cout << "Invalid option please try again: ";
        cin >> option;
        cout << endl;
    }
    //Print headers for display of results
    cout << "Week" << "\tCustomers" << "\tEarnings" << "\tExpenses" << "\tProfits" << "\t" << "\tTotal Profits" << endl;
    //Vaariables needed for caculating profits and expenses
    srand((time(nullptr)));
    int rent = option * 250;
    int customers; 
    int customer_count;
    int earnings;
    int expenses;
    int profits;
    int total_profits;
    //Loop through every week with for Loop
    for (int week = 1; week <= 5; week++)
    {
        customers = (rand() % rent) + 1;  
        customer_count = 0;
        earnings = 0;
        expenses = 0;
        profits = 0;
        //Do while loop for profits
        do {
            
            earnings += 5;
            expenses += 2;
            customer_count += 1;
        } while (customer_count < customers);
        //Add up rent and expenses
        expenses += rent;
        profits = earnings - expenses;
        total_profits += profits;
        //Print out week stats
        cout << week << "\t$" << customers << "\t\t$" << earnings << "\t\t$" << expenses << "\t\t$" << profits << "\t\t$" << total_profits; 
        cout << endl;
    }
    
    //Print how much money Donna made and say if she made above minimum wage
    if (total_profits >= 1450)
    {
        cout << "\nDonna made $" << total_profits << " so she can keep her shop open"; 
    }
    else 
    {
        cout << "\nDonna made $" << total_profits << " which is less the minimum wage so she will have to close her shop";
    }
    return 0;
}






