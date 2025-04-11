#include "header.hpp"


std::string bookNames[10] = {"Godfather", "Harry Potter", "Lord of the Rings", "War and Peace", "1984", "Brave New World", "Fahrenheit 451", "Dune", "Foundation", "The Hitchhiker's Guide to the Galaxy"};
std::string authors[10] = {"J.K. Rowling", "J.R.R. Tolkien", "Mario Puzo", "George R.R. Martin", "Agatha Christie", "Stephen King", "Dan Brown", "Isaac Asimov", "Arthur C. Clarke", "Ray Bradbury"};
Book::Book(std::string name, std::string author, int yearOfPublish, int numberOfPages) {
    this->name = name;
    this->author = author;
    this->yearOfPublish = yearOfPublish;
    this->numberOfPages = numberOfPages;
    this->price = getPrice(numberOfPages);
}
Book::~Book() {
}
Book::Book(){
    this->name = "Discrete Mathematics";
    this->author = "Yatsko O.";
    this->yearOfPublish = 2023;
    this->numberOfPages = 300;
    this->price = 295;
}

void Book::show() {
    std::cout << "--------------------------\n";
    std::cout << "Name of book: " << name << "\n";
    std::cout << "Author: " <<  author << "\n";
    std::cout << "Year of publish: " << yearOfPublish << "\n";
    std::cout << "Number of Pages: " << numberOfPages << "\n";
    std::cout << "price: " << getPrice(numberOfPages) << "\n";
}
void Book::setName(std::string name){
    this->name = name;
}

void Book::fillInfo() {
    std::string name, author;
    int yearOfPublish, numberOfPages;
    std::cout << "Enter name:\n";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter author:\n";
    std::getline(std::cin, author);
    std::cout << "Enter year of publish:\n";
    std::cin >> yearOfPublish;
    std::cout << "Enter numberOfPages:\n";
    std::cin >> numberOfPages;
    this->name = name;
    this->author = author;
    this->yearOfPublish = yearOfPublish;
    this->numberOfPages = numberOfPages;
    this->price = getPrice(numberOfPages);
}

void Book::fillInfoRand() {
    this->name = bookNames[rand() % 10];
    this->author = authors[rand() % 10];
    this->yearOfPublish = rand() % 400 + 1625;
    this->numberOfPages = rand() % 1000 + 50;
    this->price = getPrice(numberOfPages);
}
void Book::setAuthor(std::string author) {
    this->author = author;
}
void Book::setYearOfPublish(int yearOfPublish) {
    this->yearOfPublish = yearOfPublish;
}
void Book::setNumberOfPages(int numberOfPages) {
    this->numberOfPages = numberOfPages;
}
std::string Book::getName() {
    return this->name;
}
std::string Book::getAuthor() {
    return this->author;
}
int Book::getYearOfPublish() {
    return this->yearOfPublish;
}
int Book::getNumberOfPages() {
    return this->numberOfPages;
}
int Book::getPrice() {
    return this->price;
}


int Book::getPrice(int numberOfPages) {
    if (numberOfPages < 100) {
        return (getNumberOfPages() * 1) + 25;
    }
    else if (numberOfPages > 300) {
        return int((getNumberOfPages() * 0.8) + 25);
    }
    else {
        return int((getNumberOfPages() * 0.9) + 25);
    }
}

double averageNumberOfPages(Book* Books, int size){
    double totalPages = 0.0;
    for (int i = 0; i < size; i++) {
        totalPages += Books[i].getNumberOfPages();
    }
    return totalPages / size;
}

int maxPrice(Book* books, int size) {
    int max = books[0].getPrice();
    for (int i = 0; i < size - 1; i++) {
        if (books[i].getPrice() < books[i + 1].getPrice()) {
            max = books[i + 1].getPrice();
        }
    }
    return max;
}

int minPrice(Book* books, int size) {
    int min = books[0].getPrice();
    for (int i = 0; i < size - 1; i++) {
        if (books[i].getPrice() > books[i + 1].getPrice()) {
            min = books[i + 1].getPrice();
        }
    }
    return min;
}

void sortByPrice(Book* books, int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getPrice() > books[j + 1].getPrice()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

}