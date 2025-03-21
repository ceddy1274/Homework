/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Movie { 
private:
    // Movie tile
    string title;
    
    // Release year
    int year;
    
    // Movie genre
    string genre;

public:
    // Construcor
    Movie();
    
    // Setter for the movie title
    void setTitle(const string& t);

    // Setter for the movie year
    void setYear(int y);

    // Setter for the movie genre
    void setGenre(const string& g);

    // Getter for the movie title
    string getTitle() const;

    // Getter for the movie year
    int getYear() const;

    // Getter for the movie genre
    string getGenre() const;

    // Function to display movie details
    void displayMovie() const;
};


Movie::Movie() {
    
}

void Movie::setTitle(const string& t) {
    title = t;
}

void Movie::setYear(int y) {
    year = y;
}

void Movie::setGenre(const string& g) {
    genre = g;
}

string Movie::getTitle() const{
    return title;
}

int Movie::getYear() const{
    return year;
}

string Movie::getGenre() const{
    return genre;
}

void Movie::displayMovie() const{
    //DONE: Display as Title: <title>, Year: <year>, Genre: <genre>
    getTitle();
    cout << "Title: " << title << ", Year: " << year << ", Genre: " << genre << endl;
    
}

int main() {
    // Array of movie objects
    Movie movie[5];
    
    // Initalize variables
    string t;
    string g;
    int y;
    int search;
    bool found = false;
    //DONE: Use a loop to prompt the user for the title, year, and genre for each movie
    for(int i = 0; i < 5; i++)
    {
        //DONE: Use getline(cin, title) for the title and genre to allow spaces
        //DONE: Use cin >> year for the year and address newline character
        cout << "Details for movie " << i+1 <<":\n";
        cout << "Title: ";
        getline(cin, t);
        do {
            cout << "Year: ";
            cin >> y;
        } while (y > 2024 || y < 1920);
        cin.ignore(5, '\n');
        cout << "Genre: ";
        getline(cin, g);
        cout << endl;
        movie[i].setTitle(t);
        movie[i].setGenre(g);
        movie[i].setYear(y);
    }
    // Display all movies
    cout << "All movie details: \n";
    for(int i = 0; i < 5; i++)
    {
        movie[i].displayMovie();
    }
    cout << endl;
    //DONE: Prompt user to enter a year and search movies array for movies 
    // in that array
    cout << "What year would you like to search movies for: ";
    cin >> search;
    cout << "Searching movies from " << search << ":" << endl;
    for(int i = 0; i < 5; i++)
    {
        if (movie[i].getYear() == search)
        {
            movie[i].displayMovie();
            found = true;
        }
    }
    // If found == false this means no movies from that year were found in our movies array
    if (!found)
    {
        cout << "No movies found from " << search << ".";   
    }
    return 0;
}



