/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "CStack.h"
#include "CQueue.h"
#include <string>
#include <string.h>

// Function for checking brackets
bool bracketChecker(string bracket) 
{
    // Intalize a stack
    CStack stack;
    // I used this boolean to check if a value was pushed (I did this because if the user typed no brackets it would say they were balanced)
    bool pushed = false;
    // Character that we use to see what the top of the stack is
    char b;
    // String of available characters
    string brackets = "[{(<>)}]";
    // Int value I use to check if inputs are valid using the find function from the string library
    int in;
    // Check if input was valid
    for(int i = 0; i < bracket.length(); i++)
    {
        // Check for first occurence of that bracket
        in = brackets.find(bracket[i]);
        // If a character is not a bracket, in will equal -1 and be false
        if(in == -1)
        {   
            continue;
        }
        // For the first four brackets (opening brackets) set push to be true and push them onto the stack
        else if (in < 4)
        {
            pushed = true;
            stack.Push(bracket[i]);
        }
        // If bracket[i] is one of the last four brackets (closing brackets) get the top and decide what to push off with a switch statement
        else
        {
            // Getting top of the stack and setting it equal to b
            b = stack.Top();
            // For the switch statement I made sure the opening bracket had an equivalent clsoing bracket before popping
            // If not the brackets are not balanced and I have my function return false
            switch(b)
            {
                case '[':
                    if(bracket[i] == ']')
                        // Since pop has a return value I set it equal to b.
                        // I understand this is improper programming pratice because I'm not using the return value for anything
                        // But I put it in anyways because I wanted to show off that the function works how intended
                        b = stack.Pop();
                    else
                        return false;
                    break;
                case '{':
                    if(bracket[i] == '}')
                        b = stack.Pop();
                    else
                        return false;
                    break;
                case '(':
                    if(bracket[i] == ')')
                        b = stack.Pop();
                    else
                        return false;
                    break;
                case '<':
                    if(bracket[i] == '>')
                        b = stack.Pop();
                    else
                        return false;
                    break;
                default:
                    break;
            }
        }
    }
    // If an item was pushed onto the stack AND all the items were popped off (the stack is empty) then the brackets were balanced
    if(pushed && stack.IsEmpty())
        return true;
    else
        return false;
}

// Function to run our tag-system
bool tagChecker(string tag)
{
    // Intalize queue
    CQueue queue;
    // Possible tag values
    string tags = "abc#";
    // Int value I use to check if inputs are valid using the find function from the string library
    int in;
    // Loop through the string
    for(int i = 0; i < tag.length(); i++)
    {
        // Check if a letter is in the tag that shouldn't be in there
        in = tags.find(tag[i]);
        if(in == -1)
        {   
            cout << "Character in your string input was not formatted correctly (use only a, b, c, #)\n";
            return false;
        }
        // Otherwise insert onto circular array
        queue.Insert(tag[i]);
    }
    // Tag system part
    for(int i = 0; i < 100; i++)
    {
        // Print Tag
        queue.Print();
        cout << endl;
        // If top is # then break
        if(queue.GetFront() == '#')
            break;
        // Get and remove first letter
        char letter;
        queue.Remove(letter);
        // See what the letter is and decide what to do
        switch(letter)
        {
            case 'a':
               queue.Insert('b');
               queue.Insert('c');
               queue.Insert('c');
               break;
            case 'b':
               queue.Insert('a');
               queue.Insert('#');
               break;
            case 'c':
               queue.Insert('a');
               queue.Insert('a');
               queue.Insert('a');
               break;
        }
        // Remove second letter
        queue.Remove(letter);
        // If one hundered iterations have been made then stop the program
        if(i == 99)
            cout << "100 iterations I'm done\n";
    }
    // Print the final tag and return that the system worked sucessfully
    cout << "Final tag...\n";
    queue.Print();
    cout << endl;
    return true;
}

int main()
{
    //DONE: Create menu
    //DONE: Implement bracket checker using stack
    //DONE: Implement tag checker using queue
    
    do {
        // Ask user what input they want, if they don't type 1, 2, or 3 reask them
        int input = 0;
        while(input != 1 && input != 2 && input != 3)
        {
            cout << "What would you like todo:\n";
            cout << "\t1) Check an expression for balanced brackets\n";
            cout << "\t2) Display the results of a tag-system algorithm on input\n";
            cout << "\t3) Quit\n";
            cin >> input;
        }
        // If input is 1, run the bracket checker system
        if(input == 1)
        {
            // If use types in the bracket string incorrectly bracket checker will return false and the brackets will be Balanced
            // Otherwise the bracket checker will return true
            string bracket;
            cout << "Provide input for the bracket checker: ";
            cin >> bracket;
            if(bracketChecker(bracket))
                cout << "Balanced brackets\n";
            else
                cout << "Not balanced\n";
        }
        // If the user inputs 2, run the tag system
        else if(input == 2)
        {
            // Tell the user what the tag rules are
            string tag;
            cout << "Here are the rules for the tag-system:\n";
            cout << "\ta-->bcc\n";
            cout << "\tb-->a#\n";
            cout << "\tc-->aaa\n";
            // While the user doesn't type in a correct tag, ask them to retype the tag
            // If they do type it correctly the tag-system will run sucessfully
            do {
                cout << "Provide input for tag-system (type ONLY a, b, c, or # characters): ";
                cin >> tag; 
            } while(!tagChecker(tag));
        }
        // If the user inputs 3 quit the program with a nice message
        else
        {
            cout << "Have a good day :)\n";
            break;
        }
    } while(true);
    return 0;
}