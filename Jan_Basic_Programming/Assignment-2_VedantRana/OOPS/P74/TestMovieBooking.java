package P74;

import java.util.ArrayList;
import java.util.List;

class Movie {
    public String title;
    public String genre;

    public Movie(String title, String genre) {
        this.title = title;
        this.genre = genre;
    }
}

class Ticket {
    public Movie movie;
    public int seatNumber;

    public Ticket(Movie movie, int seatNumber) {
        this.movie = movie;
        this.seatNumber = seatNumber;
    }
}

class Customer {
    private String name;
    private List<Ticket> bookedTickets;

    public Customer(String name) {
        this.name = name;
        this.bookedTickets = new ArrayList<>();
    }

    public void bookTicket(Movie movie, int seatNumber) {
        Ticket ticket = new Ticket(movie, seatNumber);
        bookedTickets.add(ticket);
    }

    public void viewBookedTickets() {
        for (Ticket ticket : bookedTickets) {
            System.out.println("Movie: " + ticket.movie.title + ", Seat: " + ticket.seatNumber);
        }
    }
}

class Cinema {
    private List<Movie> movies;

    public Cinema() {
        this.movies = new ArrayList<>();
    }

    public void addMovie(Movie movie) {
        movies.add(movie);
    }

    public List<Movie> getMovies() {
        return movies;
    }
}

public class TestMovieBooking {
    public static void main(String[] args) {
        Cinema cinema = new Cinema();

        Movie movie1 = new Movie("Inception", "Sci-Fi");
        Movie movie2 = new Movie("The Shawshank Redemption", "Drama");

        cinema.addMovie(movie1);
        cinema.addMovie(movie2);

        Customer customer = new Customer("John Doe");

        customer.bookTicket(movie1, 1);
        customer.bookTicket(movie2, 5);

        customer.viewBookedTickets();
    }
}
