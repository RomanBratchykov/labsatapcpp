#include <iostream>
#include <vector>


class Worker {
    std::string surname;
    protected:
    
    int age;
    int experience;
    public:
    Worker(std::string surname, int age, int exp){
        this->age = age;
        this->experience = exp;
        this->surname = surname;
    }
    Worker(){
        this->age = 18;
        this->experience = 0;
        this->surname = "Smith";
    }
    void fillWorker(){
        std::cout << "Enter surname: \n";
        std::cin >> surname;
        std::cout << "Enter age: \n";
        std::cin >> age;
        std::cout << "Enter experience: \n";
        std::cin >> experience;

    }
    void printWorker(){
        std::cout << "Surname: " << surname << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Experience: " << experience << "\n";
    }
    int getYearOfStart(int currentYear){
        return currentYear - experience;
    }
    std::string getSurname(){
        return surname;
    }
    void setSurname(std::string surname){
        this->surname = surname;
    }
    ~Worker(){}
};


class Car {
    int numberOfRegistration;
    std::string name;
    int runned;
    protected:
    int yearOfManufacture;
    public:
    Car(std::string name, int numberOfRegistration, int runned, int yearOfManufacture){
        this->name = name;
        this->numberOfRegistration = numberOfRegistration;
        this->runned = runned;
        this->yearOfManufacture = yearOfManufacture;
    }
    Car(){
        this->name = "BMW";
        this->numberOfRegistration = 123456;
        this->runned = 150000;
        this->yearOfManufacture = 2020;
    }
    void fillCar(){
        std::cout << "Enter name: \n";
        std::cin >> name;
        std::cout << "Enter number of registration: \n";
        std::cin >> numberOfRegistration;
        std::cout << "Enter time of run: \n";
        std::cin >> runned;
        std::cout << "Enter year of manufacture: \n";
        std::cin >> yearOfManufacture;
    }
    void printCar(){
        std::cout << "Name: " << name << "\n";
        std::cout << "Number of registration: " << numberOfRegistration << "\n";
        std::cout << "Time of run: " << runned << "\n";
        std::cout << "Year of manufacture: " << yearOfManufacture << "\n";
    }
    double averageRun(){
        return (double)runned / (2025 - yearOfManufacture);
    }
    void setName(std::string name){
        this->name = name;
    }
    void setNumber(int numberOfRegistration){
        this->numberOfRegistration = numberOfRegistration;
    }
    void setRunned(int runned){
        this->runned = runned;
        this->name = name;
    }
    std::string getName(){
        return name;
    }
    int getNumber(){
        return numberOfRegistration;
    }
    int getRunned(){
        return runned;
    }
    ~Car(){}
};

class Driver : public Worker, public Car
{
    public:
    int yearOfStart;
    bool isFined;
    Driver(std::string surname, int age, int exp, std::string name, int numberOfRegistration, int runned, int yearOfManufacture, int yearOfStart, bool isFined) : Worker(surname, age, exp), Car(name, numberOfRegistration, runned, yearOfManufacture){
        this->yearOfStart = yearOfStart;
        this->isFined = isFined;
    }
    Driver(){
        this->yearOfStart = 2020;
        this->isFined = false;
    }
    void changeAllInfo(bool& isErrors){
        std::vector<std::string> errors;
        int experience, age, yearOfManufacture, numberOfRegistration, runned;
        std::string surname, name;
        try{
            std::cout << "Enter experience of driver: \n";
            std::cin >> experience;
            if (experience < 0){
                errors.push_back("Experience cannot be negative\n");
                isErrors = true;
            }
            std::cout << "Enter age of driver: \n";
            std::cin >> age;
            if (age < 0){
                errors.push_back("Age cannot be negative\n");
                isErrors = true;
            }
            std::cout << "Enter surname of driver: \n";
            std::cin >> surname;
            setSurname(surname);
            std::cout << "Enter name of car: \n";
            std::cin >> name;
            setName(name);
            std::cout << "Enter number of registration: \n";
            std::cin >> numberOfRegistration;
            if (numberOfRegistration < 0){
                errors.push_back("Number of registration cannot be negative\n");
                isErrors = true;
            }
            std::cout << "Enter time of run: \n";
            std::cin >> runned;
            if (runned < 0){
                errors.push_back("Time of run cannot be negative\n");
                isErrors = true;
            }
            std::cout << "Enter year of manufacture: \n";
            std::cin >> yearOfManufacture;
            if (yearOfManufacture < 0){
                errors.push_back("Year of manufacture cannot be negative\n");
                isErrors = true;
            }
            if (!errors.empty()){
                throw errors;
            }  
                setRunned(runned);
                setNumber(numberOfRegistration);
                this->age = age;
                this->experience = experience;
                this->yearOfManufacture = yearOfManufacture;
                std::cout << "All data successfully updated.\n";
        }
        catch (std::vector<std::string> errors){
            std::cout << " errors:\n";
            for (auto& error : errors){
                std::cout << error << "\n";
                
            }
            return;
        }
    }
    void printDriver(){
        std::cout << "Surname: " << getSurname() << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Experience: " << experience << "\n";
        std::cout << "Name of car: " << getName() << "\n";
        std::cout << "Number of registration: " << getNumber() << "\n";
        std::cout << "Time of run: " << getRunned() << "\n";
        std::cout << "Year of manufacture: " << yearOfManufacture << "\n";
        std::cout << "Year of start: " << yearOfStart << "\n";
        std::cout << "Is fined: " << (isFined ? "yes\n" : "no\n");
    }
    std::string whatIsBigger(){
        if (2025 - experience > yearOfManufacture){
            return "Experience is bigger than year of manufacture\n";
        }
        else if (2025 - experience < yearOfManufacture){
            return "Year of manufacture is bigger than experience\n";
        }
        else{
            return "Experience and year of manufacture are equal\n";
        }
    }
    ~Driver(){}
};
 
int main(){
    // Driver driver;
    // driver.fillCar();
    // std::cout << "Driver with filled car, all other default:\n";
    // driver.printDriver();
    // Driver driver1("Hamilton", 30, 5, "Audi", 124456, 20000, 2018, 2021, false);
    // std::cout << "Driver constructor:\n";
    // driver1.printDriver();
    // Driver driver2;
    // std::cout << "Driver with filled worker, all other default:\n";
    // driver2.fillWorker();
    // driver2.printDriver();
    Driver driver3;
    bool isErrors = false;
    std::cout << "Driver filled via fuction:\n";
    driver3.changeAllInfo(isErrors);
    if (isErrors){
        return 0;
    }
    else{
        driver3.printDriver();
        std::cout << driver3.whatIsBigger() << "\n";
        std::cout << "Average run: " << driver3.averageRun() << "\n";
    }
}