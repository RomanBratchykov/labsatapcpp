#include "header.hpp"


std::string surnames[10] = {"Smith", "Johnson", "Williams", "Jones", "Brown",
    "Davis", "Miller", "Wilson", "Moore", "Taylor"};
std::string departments[10] = {"HR", "IT", "Finance", "Marketing", "Sales",
    "Operations", "Customer Service", "Legal", "Research", "Development"};
Worker::Worker(std::string surname, std::string department, int yearOfStart, int salary) {
    this->surname = surname;
    this->department = department;
    this->yearOfStart = yearOfStart;
    this->salary = salary;
    this->bonus = getBonus(2025 - yearOfStart);
}
Worker::~Worker() {
    std::cout << "Destructor called for " << surname << "\n";
}
Worker::Worker(){
    this->surname = "Shevchenko";
    this->department = "IT";
    this->yearOfStart = 2000;
    this->salary = 1000;
    this->bonus = 400;
}

void Worker::show() {
    std::cout << "--------------------------\n";
    std::cout << "Surname: " << surname << "\n";
    std::cout << "Department: " << department << "\n";
    std::cout << "Year of start: " << yearOfStart << "\n";
    std::cout << "Salary: " << salary << "\n";
    std::cout << "Bonus: " << bonus << "\n";
}
void Worker::setSurname(std::string surname){
    this->surname = surname;
}

void Worker::fillInfo() {
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
    this->surname = surname;
    this->department = department;
    this->yearOfStart = yearOfStart;
    this->salary = salary;
    this->bonus = getBonus(2025 - yearOfStart);
}

void Worker::fillInfoRand() {
    this->surname = surnames[rand() % 10];
    this->department = departments[rand() % 10];
    this->yearOfStart = rand() % 25 + 2000;
    this->salary = rand() % 10000 + 1000;
    this->bonus = getBonus(2025 - yearOfStart);
}
void Worker::setDepartment(std::string department) {
    this->department = department;
}
void Worker::setYearOfStart(int yearOfStart) {
    this->yearOfStart = yearOfStart;
}
void Worker::setSalary(int salary) {
    this->salary = salary;
}
void Worker::setBonus(int bonus) {
    this->bonus = bonus;
}
std::string Worker::getSurname() {
    return this->surname;
}
std::string Worker::getDepartment() {
    return this->department;
}
int Worker::getYearOfStart() {
    return this->yearOfStart;
}
int Worker::getSalary() {
    return this->salary;
}
int Worker::getBonus() {
    return this->bonus;
}


double Worker::getBonus(int yearsOfWork) {
    if (yearsOfWork < 10) {
        return getSalary() * 0.1;
    }
    else if (yearsOfWork < 25 && yearsOfWork >= 10) {
        return getSalary() * 0.2;
    }
    else {
        return getSalary() * 0.4;
    }
}

double averageYearsOfWork(Worker* workers, int size, int currentYear) {
    if (size == 0) return 0.0;
    double totalYears = 0.0;
    for (int i = 0; i < size; i++) {
        totalYears += (currentYear - workers[i].getYearOfStart());
    }
    return totalYears / size;
}

void orderByExpirience(Worker* workers, int size, int currentYear){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (workers[j].getYearOfStart() > workers[j + 1].getYearOfStart()){
                Worker temp = workers[j];
                workers[j] = workers[j + 1];
                workers[j + 1] = temp;
            }
        }
    }
}