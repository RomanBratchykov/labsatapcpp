#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>

class Book {
    std::string name;
    std::string author;
    int yearOfPublish;
    int price;
    int numberOfPages;
    public:
    Book();
    Book(std::string name, std::string author, int yearOfPublish, int numberOfPages);
    void show();
    void fillInfo();
    void fillInfoRand();
    void setName(std::string name);
    void setAuthor(std::string author);
    void setYearOfPublish(int yearOfPublish);
    void setNumberOfPages(int numberOfPages);
    std::string getName();
    std::string getAuthor();
    int getYearOfPublish();
    int getPrice();
    int getNumberOfPages();
    int getPrice(int numberOfPages);
    ~Book();
};
double averageNumberOfPages(Book* books, int size);

int maxPrice(Book* books, int size);

int minPrice(Book* books, int size);

void sortByPrice(Book* books, int size);
#endif