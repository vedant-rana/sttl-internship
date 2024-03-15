package P91;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

class Author {
    private String authorName;

    public Author(String authorName) {
        this.authorName = authorName;
    }

    public String getAuthorName() {
        return authorName;
    }
}

class Book {
    private String bookTitle;
    private Author author;
    private int bookId;
    private boolean isAvailable;

    public Book(String bookTitle, Author author, int bookId) {
        this.bookTitle = bookTitle;
        this.author = author;
        this.bookId = bookId;
        this.isAvailable = true;
    }

    public String getBookTitle() {
        return bookTitle;
    }

    public Author getAuthor() {
        return author;
    }

    public int getBookId() {
        return bookId;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            System.out.println("Book '" + bookTitle + "' has been borrowed.");
        } else {
            System.out.println("Book '" + bookTitle + "' is not available for borrowing.");
        }
    }

    public void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            System.out.println("Book '" + bookTitle + "' has been returned.");
        } else {
            System.out.println("Book '" + bookTitle + "' is already available.");
        }
    }
}

class Member {
    private int memberId;
    private String memberName;
    private List<Book> borrowedBooks;

    public Member(int memberId, String memberName) {
        this.memberId = memberId;
        this.memberName = memberName;
        this.borrowedBooks = new ArrayList<>();
    }

    public int getMemberId() {
        return memberId;
    }

    public String getMemberName() {
        return memberName;
    }

    public List<Book> getBorrowedBooks() {
        return borrowedBooks;
    }

    public void borrowBook(Book book) {
        if (book.isAvailable()) {
            borrowedBooks.add(book);
            book.borrowBook();
        } else {
            System.out.println("Book '" + book.getBookTitle() + "' is not available for borrowing.");
        }
    }

    public void returnBook(Book book) {
        if (borrowedBooks.contains(book)) {
            borrowedBooks.remove(book);
            book.returnBook();
        } else {
            System.out.println("You did not borrow the book '" + book.getBookTitle() + "'.");
        }
    }
}

class Library {
    private List<Book> books;
    private List<Member> members;

    public Library() {
        this.books = new ArrayList<>();
        this.members = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public void addMember(Member member) {
        members.add(member);
    }

    public void displayAvailableBooks() {
        System.out.println("Available Books in the Library:");
        for (Book book : books) {
            if (book.isAvailable()) {
                System.out.println("Book ID: " + book.getBookId() +
                        ", Title: " + book.getBookTitle() +
                        ", Author: " + book.getAuthor().getAuthorName());
            }
        }
        System.out.println("----------------------");
    }

    public void displayBorrowedBooks(Member member) {
        System.out.println("Borrowed Books by Member " + member.getMemberName() + ":");
        for (Book book : member.getBorrowedBooks()) {
            System.out.println("Book ID: " + book.getBookId() +
                    ", Title: " + book.getBookTitle() +
                    ", Author: " + book.getAuthor().getAuthorName());
        }
        System.out.println("----------------------");
    }
}


public class TestLibrarySystem {
    public static void main(String[] args) {
        Author author1 = new Author("John Doe");
        Author author2 = new Author("Jane Smith");

        Book book1 = new Book("Introduction to Java", author1, 1);
        Book book2 = new Book("Data Structures and Algorithms", author2, 2);

        Member member1 = new Member(101, "Alice");
        Member member2 = new Member(102, "Bob");

        Library library = new Library();

        library.addBook(book1);
        library.addBook(book2);


        library.addMember(member1);
        library.addMember(member2);

        library.displayAvailableBooks();

        member1.borrowBook(book1);
        library.displayAvailableBooks();
        library.displayBorrowedBooks(member1);

        member2.borrowBook(book2);
        library.displayAvailableBooks();
        library.displayBorrowedBooks(member2);


        member1.returnBook(book1);
        library.displayAvailableBooks();
        library.displayBorrowedBooks(member1);
    }
}
