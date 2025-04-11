#include "header.hpp"

int main() {
    srand(time(0));
    while (1){
        std::cout << "Enter number of books(0 for exit):\n";
        int size;   
        std::cin >> size;
        if (size == 0) {
            break;
        }   
        Book* books = new Book[size];
        for (int i = 0; i < size; i++) {
            std::cout << "What book to create? (1 - default, 2 - custom, 3 - custom with setting all from class):\n";
            int bookType;
            std::cin >> bookType;
            switch (bookType) {
                case 1:
                    books[i] = Book();
                    break;
                case 2:
                {
                    std::string name, author;
                    int yearOfPublish, numberOfPages;
                    std::cout << "Enter name:\n";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    std::cout << "Enter author:\n";
                    std::getline(std::cin, author);
                    std::cout << "Enter year of publish:\n";
                    std::cin >> yearOfPublish;
                    std::cout << "Enter number of pages:\n";
                    std::cin >> numberOfPages;
                    books[i] = Book(name, author, yearOfPublish, numberOfPages);
                    break;
                }
                case 3: {
                    std::cout << "Enter how you want to fill info (1 - random, 2 - manual):\n";
                    int type;
                    std::cin >> type;
                    switch (type) {
                        case 1:
                            books[i].fillInfoRand();
                        break;
                        case 2:
                            books[i].fillInfo();
                        break;
                        default:
                            std::cout << "Invalid type\n";
                        break;
                    }
                }      
                break;
                default:
                    std::cout << "Invalid type\n";
                    break;
            }
        }
        std::cout << "books:\n";
        for (int i = 0; i < size; i++) {
            books[i].show();
        }
        std::cout << "----------------------\n";
        std::cout << "Average number of pages: " << averageNumberOfPages(books, size) << "\n";
        std::cout << "Max price: " << maxPrice(books, size) << "\n";
        std::cout << "Min price: " << minPrice(books, size) << "\n";
        sortByPrice(books, size);
        std::cout << "books ordered by price:\n";
        for (int i = 0; i < size; i++) {
            books[i].show();
        }
        std::cout << "Books cleared\n";
        delete[] books;
}
}