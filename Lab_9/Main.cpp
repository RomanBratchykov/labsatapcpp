#include "header.hpp"

int main() {
    std::cout << "Enter number of workers:\n";
    int size;   
    std::cin >> size;
    Worker* workers = new Worker[size];
    for (int i = 0; i < size; i++) {
        std::cout << "What Worker to create? (1 - default, 2 - custom, 3 - custom with setting all from class):\n";
        int workerType;
        std::cin >> workerType;
        switch (workerType) {
            case 1:
                workers[i] = Worker();
                break;
            case 2:
            {
                std::string surname, department;
                int yearOfStart, salary;
                std::cout << "Enter surname:\n";
                std::cin.ignore();
                std::getline(std::cin, surname);
                std::cout << "Enter department:\n";
                std::getline(std::cin, department);
                std::cout << "Enter year of start:\n";
                std::cin >> yearOfStart;
                std::cout << "Enter salary:\n";
                std::cin >> salary;
                workers[i] = Worker(surname, department, yearOfStart, salary);
                break;
            }
            case 3: {
                std::cout << "Enter how you want to fill info (1 - random, 2 - manual):\n";
                int type;
                std::cin >> type;
                switch (type) {
                    case 1:
                        workers[i].fillInfoRand();
                    break;
                    case 2:
                        workers[i].fillInfo();
                    break;
                    default:
                        std::cout << "Invalid type\n";
                    break;
                }
            }      
            default:
                std::cout << "Invalid type\n";
                break;
        }
    }
    std::cout << "Workers:\n";
    for (int i = 0; i < size; i++) {
        workers[i].show();
    }
    std::cout << "Average years of work: " << averageYearsOfWork(workers, size, 2025) << "\n";
    orderByExpirience(workers, size, 2025);
    std::cout << "Workers ordered by expirience:\n";
    for (int i = 0; i < size; i++) {
        workers[i].show();
    }
}