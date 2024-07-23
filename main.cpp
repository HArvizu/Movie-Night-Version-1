#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Define the Movie structure
struct Movie
{
    string title;                                                                                           // Movie title
    double score;                                                                                           // Total score
    Movie* next;                                                                                            // Pointer to the next movie
};

// Define the MovieList class
class MovieList
{
private:
    Movie* head;                                                                                            // Pointer to the head of the list

public:
    // Constructor
    MovieList()
    {
        head = NULL;                                                                                        // Initialize the head to NULL
    }

    // Function to add a movie to the list
    void addMovie(string title, double score)
    {
        Movie* n = new Movie;                                                                               // Create a new movie
        n->title = title;                                                                                   // Set the title of the new movie
        n->score = score;                                                                                   // Set the score of the new movie
        n->next = head;                                                                                     // Add the new movie to the beginning of the list
        head = n;                                                                                           // Update the head of the list
    }

    // Function to list all movies
    void listMovies()
    {
        Movie* p = head;                                                                                    // Start at the head of the list
        while (p != NULL)                                                                                   // Traverse the list
        {
            cout << p->title << ": " << p->score << "/10" << endl;                                          // Print the title and score of each movie
            p = p->next;                                                                                    // Move to the next movie
        }
        cout << " " << endl;
    }

    // Function to compare movies
    void compareMovies()
    {
        Movie* p = head;                                                                                    // Start at the head of the list
        Movie* best = p;                                                                                    // Keep track of the movie with the highest score
        while (p != NULL)                                                                                   // Traverse the list
        {
            if (p->score > best->score)                                                                     // If the current movie's score is higher than the best score
            {
                best = p;                                                                                   // Update the best movie
            }
            p = p->next;                                                                                    // Move to the next movie
        }
        cout << "Best Movie: " << best->title << " with a score of " << best->score << "/10" << endl;       // Print the best movie and its score
        cout << " " << endl;
    }
};






















// Main function
int main()
{
    MovieList movies;                                                                                       // Create a new linked list of movies
    char choice;                                                                                            // Variable to store the user's choice

    string title;                                                                                           // Variable to store the movie title
    double IScore, RScore, OScore, TScore;                                                                  // Variables to store the scores

    do
    {
        cout << "Movie Night" << endl;                                                                      // Print welcome message
        
        // Print menu options
        cout << "A) Add Movie" << endl;
        cout << "B) My Movies" << endl;
        cout << "C) Quit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;                                                                                      // Get the user's choice
        cin.ignore();                                                                                       // Ignore the newline character
        cout << " " << endl;
        // Perform action based on user's choice
        switch (choice)
        {
            case 'A':
                //system("CLS");                                                                            // For Windows
                system("clear");                                                                            // for Unix-based systems
                do
                {
                    // Add a movie
                    cout << "Enter Movie: ";
                    getline(cin, title);
                    cout << "Enter IMDb Score: ";
                    cin >> IScore;
                    cout << "Enter Rotten Tomatoe Score: ";
                    cin >> RScore;
                    RScore = RScore / 10.0;                                                                // Move the decimal up one place
                    cout << "Enter Metric Score: ";
                    cin >> OScore;
                    OScore = OScore / 10.0;                                                                // Move the decimal up one place
                    TScore = (IScore + RScore + OScore) / 3;                                                // Calculate the average score
                    TScore = round(TScore * 10) / 10;                                                       // Round to the nearest tenth
                    cout << "Total Score: " << TScore << "/10" << endl;
                    movies.addMovie(title, TScore);
                    cout << " " << endl;            
                
                    cout << "Return To Menu (Y/N): ";
                    cin >> choice;
                    cin.ignore();                                                                           // Ignore the newline character
                    cout << " " << endl;
                    if (toupper(choice) == 'Y')
                    {
                        //system("CLS");                                                                    // For Windows
                        system("clear");                                                                    //for Unix-based systems
                    }
                } while (toupper(choice) != 'Y');
                break;

        
        
        
        
            
            case 'B':
                //system("CLS");                                                                            // For Windows
                system("clear");                                                                            // for Unix-based systems    
                do
                {
                    // List all movies
                    movies.listMovies();
                    movies.compareMovies();
                    cout << "Return To Menu (Y/N): ";
                    cin >> choice;
                    cin.ignore();                                                                           // Ignore the newline character
                    cout << " " << endl;
                    if (toupper(choice) == 'Y')
                    {
                        //system("CLS");                                                                    // For Windows
                        system("clear");                                                                    //for Unix-based systems            
                    }
                } while (toupper(choice) != 'Y');
                break;
        }
    } while (toupper(choice) != 'C');                                                                       // Repeat until the user chooses to quit

    cout << "Goodbye" << endl;                                                                              // Print goodbye message
    return 0;                                                                                               // End the program
}
