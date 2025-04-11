#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

extern std::string publishers[5];
class Book {
    std::string name;
    std::string author;
    int yearOfPublish;
    int price;
    int numberOfPages;
    std::string publisher;
    std::string city;
    
    public:
    Book();
    Book(std::string name, std::string author, int yearOfPublish, int numberOfPages, std::string publisher, std::string city);
    void show();
    void fillInfo();
    void fillInfoRand();
    friend class Library;
    friend int numberOfPublishers(Book* books, int size, std::string publisher);
    void setName(std::string name);
    void setAuthor(std::string author);
    void setYearOfPublish(int yearOfPublish);
    void setNumberOfPages(int numberOfPages);
    friend void bibliography(const Book& book);
    std::string getName();
    std::string getAuthor();
    int getYearOfPublish();
    int getPrice();
    std::string getPublisher();
    std::string getCity();
    void setPublisher(std::string publisher);
    void setCity(std::string city);
    int getNumberOfPages();
    int calculatePrice(int numberOfPages);
    ~Book();
};

class Library{
    friend class Book;
    Book book;
    std::string genre;
    public:
    void show(Book book);
    void setGenre(std::string genre);
    std::string getGenre();
    Library(std::string genre);
    Library();
    ~Library();
};
double averageNumberOfPages(Book* books, int size);

int maxPrice(Book* books, int size);

int minPrice(Book* books, int size);

void sortByPrice(Book* books, int size);

#endif