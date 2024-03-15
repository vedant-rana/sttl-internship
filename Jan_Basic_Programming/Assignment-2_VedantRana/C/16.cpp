#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
private:
    string title;
    string genre;
    int releaseYear;

public:
    Movie(const string& title, const string& genre, int releaseYear)
        : title(title), genre(genre), releaseYear(releaseYear) {}

    const string& getTitle() const {
        return title;
    }

    const string& getGenre() const {
        return genre;
    }

    int getReleaseYear() const {
        return releaseYear;
    }
};

class BookingSystem {
private:
    vector<Movie> movies;

public:
    void addMovie(const string& title, const string& genre, int releaseYear) {
        movies.push_back(Movie(title, genre, releaseYear));
    }

    void displayMovies() const {
        cout << "Available Movies:\n";
        for (const auto& movie : movies) {
            cout << movie.getTitle() << " (" << movie.getReleaseYear() << ") - " << movie.getGenre() << "\n";
        }
    }

    void bookTicket(const string& title) {
        for (auto& movie : movies) {
            if (movie.getTitle() == title) {
                cout << "Ticket booked for movie: " << title << "\n";
                return;
            }
        }
        cout << "Movie not found.\n";
    }
};

int main() {
    BookingSystem bookingSystem;

    bookingSystem.addMovie("Inception", "Sci-Fi", 2010);
    bookingSystem.addMovie("The Shawshank Redemption", "Drama", 1994);
    bookingSystem.addMovie("The Dark Knight", "Action", 2008);

    bookingSystem.displayMovies();

    cout << "\n";

    bookingSystem.bookTicket("Inception");
    bookingSystem.bookTicket("The Dark Knight");
    bookingSystem.bookTicket("Titanic");

    return 0;
}
