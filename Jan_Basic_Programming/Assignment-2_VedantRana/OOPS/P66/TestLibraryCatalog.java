package P66;

import java.util.ArrayList;
import java.util.List;

class Library {
    private List<Book> books;

    public Library() {
        this.books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public void checkOutBook(Book book) {
        if (books.contains(book) && !book.isCheckedOut()) {
            book.setCheckedOut(true);
            System.out.println("Book checked out successfully.");
        } else {
            System.out.println("Book not available for checkout.");
        }
    }

    public List<Book> searchByAuthor(Author author) {
        List<Book> booksByAuthor = new ArrayList<>();
        for (Book book : books) {
            if (book.getAuthor().equals(author)) {
                booksByAuthor.add(book);
            }
        }
        return booksByAuthor;
    }
}

class Book {
    private String title;
    private Author author;
    private boolean checkedOut;

    public Book(String title, Author author) {
        this.title = title;
        this.author = author;
        this.checkedOut = false;
    }

    public String getTitle() {
        return title;
    }

    public Author getAuthor() {
        return author;
    }

    public boolean isCheckedOut() {
        return checkedOut;
    }

    public void setCheckedOut(boolean checkedOut) {
        this.checkedOut = checkedOut;
    }
}

class Author {
    private String name;

    public Author(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}


public class TestLibraryCatalog {
    public static void main(String[] args) {
        Library library = new Library();

        Author author1 = new Author("Author1");
        Author author2 = new Author("Author2");

        Book book1 = new Book("Book1", author1);
        Book book2 = new Book("Book2", author2);
        Book book3 = new Book("Book3", author1);

        library.addBook(book1);
        library.addBook(book2);
        library.addBook(book3);

        // Searching for books by author
        List<Book> booksByAuthor1 = library.searchByAuthor(author1);
        System.out.println("Books by " + author1.getName() + ": " + booksByAuthor1.size());

        // Checking out a book
        library.checkOutBook(book1);

        // Checking out an already checked-out book
        library.checkOutBook(book1);
    }
}
