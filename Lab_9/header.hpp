#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>

class Worker {
    std::string surname;
    std::string department;
    int yearOfStart;
    int salary;
    int bonus;
    public:
    Worker();
    Worker(std::string surname, std::string department, int yearOfStart, int salary);
    void show();
    void fillInfo();
    void fillInfoRand();
    void setSurname(std::string surname);
    void setDepartment(std::string department);
    void setYearOfStart(int yearOfStart);
    void setSalary(int salary);
    void setBonus(int bonus);
    std::string getSurname();
    std::string getDepartment();
    int getYearOfStart();
    int getSalary();
    int getBonus();
    double getBonus(int yearsOfWork);
    ~Worker();
};

double averageYearsOfWork(Worker* workers, int size, int currentYear);

void orderByExpirience(Worker* workers, int size, int currentYear);
#endif