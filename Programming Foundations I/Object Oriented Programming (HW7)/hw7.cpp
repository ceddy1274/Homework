/******************************************************************************
Spring 2024 Programming Foundations I
Author: Cameron Eddy
Date: April 22, 2024
Purpose: Make a character creator using the Character class
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Character.h"
using namespace std;

// size of complete_spell_list.txt
const int SPELL_DOC_SIZE = 46;

// -------------------------------------------------
// Name: readInSpells
// Parameters: pass-by-value string filename
//             string array arr
//             pass-by-value int arr_size
// Returns: bool - true when successful, false otherwise
// Purpose: Opens the file with filename and reads in spells line-by-line into the array arr of size arr_size
// -------------------------------------------------
bool readInSpells(string filename, string arr[], int arr_size) {
    bool spells = true;
    ifstream infile;
    infile.open( filename.c_str() );
    if ( infile.fail() ) 
    {
        spells = false;
    }
    else
    {
        for (int i = 0; i < arr_size; i++)
        {
            infile >> arr[i];
        }
    }
    return spells;
}


int main()
{
    /* YOU SHOULD NOT CHANGE CODE BELOW THIS LINE UNLESS TO UNCOMMENT IT */

    // declare and initialize needed variables
    string all_spells[SPELL_DOC_SIZE];
    for (int i = 0; i < SPELL_DOC_SIZE; i++)
        all_spells[i] = "Empty";
    
    string character_name = "";
    string character_class = "";
    int character_level, choice = 0;
    bool makeAnother = false;
    
   
    
    // Testing methods...
    cout << "Testing readInSpells()..." << endl;
    if (readInSpells("complete_spell_list.txt", all_spells, SPELL_DOC_SIZE))
    {
         cout << "Read in spells successfully" << endl << endl;
    }

    cout << "Testing constructor..." << endl;
    Character magnus;
    magnus.print();
    cout << endl;

    cout << "Testing parameterized constructor..." << endl;
    Character merle("Merle", "Cleric", 1, true);
    merle.generateSpellList(all_spells, SPELL_DOC_SIZE);
    merle.print();
    cout << endl;

    cout << "Testing copy constructor..." << endl;
    Character merle2(merle);
    merle2.print();
    cout << endl;
    
    cout << "Testing setters..." << endl;
    magnus.setName("Magnus");
    magnus.setClassName("Fighter");
    magnus.setIsCaster(false);
    magnus.setLevel(3);
    magnus.setStats(18, 14, 15, 10, 11, 12);
    magnus.setSingleStat(Character::STR, 20);
    magnus.generateHitPoints();
    magnus.print();
    cout << endl;

    cout << "Testing saveCharacterSheet()..." << endl;
    if (magnus.saveCharacterSheet())
    {
         cout << "Successfully saved character sheet." << endl << endl;
    }

    /* YOU SHOULD NOT CHANGE CODE ABOVE THIS LINE UNLESS TO UNCOMMENT IT*/

    /* WHERE CHARACTER CREATOR BEGINS! */
    /** YOUR CODE GOES BELOW! */

    // Welcome user
    cout << "Welcome to the D&D character creation\n";
    bool done;
    // do...
    do
    {
        // Prompt user for character name
        Character user;
        string name;
        cout << "What would you like your character's name to be?\n";
        cin >> name;
        user.setName(name);

        // Prompt user for character class
        string ClassName;
        bool valid_name;
        string classes[4] = {"Fighter", "Rogue", "Wizard", "Cleric"};
        cout << "What would you like you character's class to be?\n";
        do
        {
            valid_name = false;
            cout << "NOTE: You can only choose to be a Fighter, Rogue, Wizard, or Cleric(only a Wizard and Cleric are spellcasters)\n";
            cin >> ClassName;
            for (int i = 0; i < 4; i++)
            {
                if(classes[i] == ClassName)
                {
                    valid_name = true;
                }
            }
        } while (valid_name == false);
        // Set class
        user.setClassName(ClassName);
        if (ClassName == "Wizard" || ClassName == "Cleric")
        {
            user.setIsCaster(true);
            user.generateSpellList(all_spells, SPELL_DOC_SIZE);
        }

        // Prompt user for character level
        int level;
        cout << "What do you want your character's level to be?\n";
        do {
            cout << "Note level must be inbetween 1 and 20 inclusive\n";
            cin >> level;
        } while(level < 1 || level > 20);

        // Set level
        user.setLevel(level);

        // Now that level, class, and stats are known, generate the character's hit points
        user.generateHitPoints();
        bool okay;
        // do...
        do {
            //have test1 be equal to true and if user chooses to regenerate or to make new spells set it equal to false to have loop continue
            okay = true;
            // Print out the character
            user.print();

            // Print menu
            cout << "Are you happy with your character, if not you may regenerate stats and hitpoints or generate a new spells list\n";
            char changes;
            do {
                cout << "NOTE: Answer must be 'R' for  regenetating stats, 'N' for new spells, or 'O' for okay\n";
                cin >> changes;
            } while (changes != 'R' && changes != 'N' && changes != 'O');
            // If they chose to change stats and regenerate hit points...
            if (changes == 'R')
            {
                // Ask if user wants to generate random stats or enter stats
                char random;
                cout <<"Would you like to generate random stats(other option is to manually enter stats)\n";
                do {
                    cout << "NOTE: Answer must be 'Y' or 'N'\n";
                    cin >> random;
                } while (random != 'Y' && random != 'N');

                // if they want to generate random stats...
                if (random == 'Y')
                {
                    user.generateRandomStats();
                }
                // otherwise, if they want to enter stats by hand...
                else
                {
                    // Prompt user for stats
                    cout << "Stat entries are as follows: 1.Strength, 2.Dexterity, 3.Constitution, 4.Intelligence, 5.Wisdom, 6.Charisma\n";
                    cout << "NOTE: All stats must be inbetween 8 and 20\n";
                    int stat = 0;
                    // For each stat...
                    for (int i = 0; i < 6; i++)
                    {
                        // Get user input
                        cin >> stat;
                        // Check that the new score is valid...
                        while(stat > 20 || stat < 8)
                        {
                            cout << "Stat you entered wasn't inbetween 8 and 20\n";
                            cin >> stat;
                        }
                        // Set stat
                        user.setSingleStat(i, stat);
                    }
                }        
                
                // Generate new hit points
                user.generateHitPoints();
                // Set okay equal to false to continue do while loop
                okay = false;
            }
            // otherwise, if they want to generate a new spell list...
            else if (changes == 'N')
            {
                
                // if the character is a spellcaster...
                if(user.getIsCaster())
                {
                    // generate a new spell list
                    user.generateSpellList(all_spells, SPELL_DOC_SIZE);
                }
                // otherwise (if the character ISN'T a spellcaster)
                else
                {
                    // Print out message to user that their character isn't a caster
                    cout << "Your character is not a caster\n";
                }
                // Set okay equal to false to continue do while loop
                okay = false;
            }
        // while the user isn't finished with their character
        } while (okay == false);

        // Prompt the user if they would like to save or scrap their character
        char save;
        cout << "Would you like to save character(other option is to scrap it)\n";
        do 
        {
            cout << "NOTE: Answer must be 'Y' or 'N'\n";
            cin >> save;
        } while(save != 'Y' && save != 'N');
        
        // if they choose to save their character...
        if (save == 'Y')
        {

            // If the character sheet is saved successfully...
            if(user.saveCharacterSheet())
            {

                // Print out a message to the user saying so
                cout << "Character was saved\n";
                
            }
            // otherwise...
            else
            {

                // Print an error message
                cout << "Character was not saved\n";
            }

            // Prompt user to see if they want to make another character
            char another_one;
            cout << "Do you want to make another character\n";
            do 
            {
                cout << "NOTE: Answer must be 'Y' or 'N'\n";
                cin >> another_one;
            } while(another_one != 'Y' && another_one != 'N');

            // if the user said yes...
            if (another_one == 'Y')
            {
            
                // reset the character
                user.reset();

                // repeat the loop
                done = false;
            }   
            
            // otherwise (the user said no)
            else 
            {                

                // don't repeat the loop
                done = true;
            }   
        }
        // Otherwise, if they chose to scrap their character and start over...
        else
        {
        
            // reset the character
            user.reset();

            // repeat the loop
            done = false;
        }
        

    // while the user wants to repeat the loop and make another character
    } while (done == false);
    
    // Print goodbye message
    cout << "I hope you enjoyed creating your character, goodbye now!";
    
    return 0;
}