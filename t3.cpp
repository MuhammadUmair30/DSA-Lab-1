#include <iostream>
using namespace std;

template<typename T>
class LibraryItem {
public:
    virtual void display() = 0;
};

template<typename T>
class Book : public LibraryItem<T> {
    T pages;
    string author;
    string name;

public:
    Book() {}
    Book(string n, string a, T p) {
        name = n;
        author = a; 
        pages = p; 
    }
    string getTitle() {
        return name;
    }
    T getPages() {
        return pages;
    }
    void display() {
        cout << "Book Name: " << name << "  ";
        cout << "Author: " << author << "  ";
        cout << "Pages: " << pages << "\n";
    }
};

template<typename T>
class Newspaper : public LibraryItem<T> {
    string newsname;
    string date;
    string edition;

public:
    Newspaper() {}
    Newspaper(string n, string d, string e) {
        newsname = n;
        date = d; 
        edition = e;
    }
    string getName() {
        return newsname;
    }
    string getEdition() {
        return edition; 
    }
    void display() {
        cout << "Newspaper: " << newsname << "  ";
        cout << "Date: " << date << "  ";
        cout << "Edition: " << edition << "\n";
    }
};

template<typename T>
class Library {
    Book<T> books[10];
    Newspaper<T> newspapers[10];
    int bookCount = 0;
    int newspaperCount = 0;

public:
    void addBook(Book<T> b) {
        books[bookCount++] = b;
    }
    void addNewspaper(Newspaper<T> n) {
        newspapers[newspaperCount++] = n; 
    }

    void displayCollection() {
        cout << "Books:\n";
        for (int i = 0; i < bookCount; i++)
        {
            books[i].display();
        }
        cout << "Newspapers:\n";
        for (int i = 0; i < newspaperCount; i++)
        {
            newspapers[i].display();
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++)
            for (int j = i + 1; j < bookCount; j++) {
                if (books[i].getPages() > books[j].getPages()) {
                    Book<T> temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++)
            for (int j = i + 1; j < newspaperCount; j++)
                if (newspapers[i].getEdition() > newspapers[j].getEdition()) {
                    Newspaper<T> temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
    }

    Book<T>* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++)
            if (books[i].getTitle() == title) return &books[i];
        return NULL;
    }

    Newspaper<T>* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; i++)
            if (newspapers[i].getName() == name) return &newspapers[i];
        return NULL;
    }
};

int main() {
    Book<int> book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book<int> book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper<int> newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper<int> newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library<int> library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book<int>* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) { cout << "\nFound Book:\n"; foundBook->display(); }
    else { cout << "\nBook not found.\n"; }

    Newspaper<int>* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) { cout << "\nFound Newspaper:\n"; foundNewspaper->display(); }
    else { cout << "\nNewspaper not found.\n"; }

    return 0;
}