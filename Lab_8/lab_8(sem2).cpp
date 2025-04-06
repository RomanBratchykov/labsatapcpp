#include <iostream>
#include <ctime>

std::string addresses[10] = {"123 Main St", "456 Elm St", "789 Oak St", "101 Pine St", "202 Maple St",
                            "303 Birch St", "404 Cedar St", "505 Spruce St", "606 Willow St", "707 Cherry St"};
std::string surnames[10] = {"Smith", "Johnson", "Williams", "Jones", "Brown",
                            "Davis", "Miller", "Wilson", "Moore", "Taylor"};
std::string countries[10] = {"USA", "Canada", "UK", "Australia", "Germany",
                            "France", "Italy", "Spain", "Netherlands", "Ukraine"};
std::string educations[4] = {"High School", "Bachelor's", "Master's", "PhD"};

class Flat {
    private:
        std::string address;
        int floor;
        int rooms;
        double area;
    public:
        Flat(){
            this->address = "Unknown";
            this->floor = 2;
            this->rooms = 2;
            this->area = 55.0;
        }
        Flat(std::string address, int floor, int rooms, double area) {
            this->address = address;
            this->floor = floor;
            this->rooms = rooms;
            this->area = area;
        }
        
        void fillInfo(){
            std::cout << "Enter address, floor, rooms and area:\n";
            std::cin.ignore();
            std::getline(std::cin, address);
            std::cin >> floor >> rooms >> area;
            this->address = address;
            this->floor = floor;
            this->rooms = rooms;
            this->area = area;
        }
        
        void fillInfoRand() {
            this->address = addresses[rand() % 10];
            this->floor = rand() % 10 + 1;
            this->rooms = rand() % 5 + 1;
            this->area = (rand() % 100) + 20.0;
        }
        void show() {
            std::cout << "--------------------------\n";
            std::cout << "Flat details:\n";
            std::cout << "Address: " << address << "\n";
            std::cout << "Floor: " << floor << "\n";
            std::cout << "Rooms: " << rooms << "\n";
            std::cout << "Area: " << area << "\n";
        }
        void showFlatWithRooms(int numberOfRooms) {
            if (this->rooms == numberOfRooms) {
                std::cout << "--------------------------\n";
                std::cout << "Flat details:\n";
                std::cout << "Address: " << address << "\n";
                std::cout << "Floor: " << floor << "\n";
                std::cout << "Rooms: " << rooms << "\n";
                std::cout << "Area: " << area << "\n";
            }
        }
        void showFlatWithAreaWithinRange(double area, int start, int end) {
            if (this->area < area && this->floor >= start && this->floor <= end) {
                std::cout << "Flat details:\n";
                std::cout << "Address: " << address << "\n";
                std::cout << "Floor: " << floor << "\n";
                std::cout << "Rooms: " << rooms << "\n";
                std::cout << "Area: " << this->area << "\n";
            }
        }
        ~Flat() {
            std::cout << "Destructor called for flat at " << address << "\n";
        }
};

class People{
    private:
        std::string surname;
        std::string country;
        char gender;   
        std::string education;
        int yearOfBirth;
        int age;
    public:
        People(){
            this->surname = "Shevchenko";
            this->country = "Ukraine";
            this->gender = 'M';
            this->education = "High School";
            this->yearOfBirth = 2000;
            this->age = 25;
        }
        People(People& human){
            this->surname = human.surname;
            this->country = human.country;
            this->gender = human.gender;
            this->education = human.education;
            this->yearOfBirth = human.yearOfBirth;
            this->age = human.age;
        }
        ~People(){
            std::cout << "Destructor called for " << surname << "\n";
        }
        char getGender() {
            return this->gender;
        }
        
        void fillInfo(){
                std::cout << "Enter surname, country, education, age, yearOfBirth and gender:\n";
                std::string surname, country, education;
                int age, yearOfBirth;
                char gender;
                std::getline(std::cin, surname);
                std::getline(std::cin, country);
                std::getline(std::cin, education);
                std::cin.ignore();
                std::cin >> age >> yearOfBirth >> gender;
                this->surname = surname;
                this->country = country;
                this->education = education;
                this->age = age;
                this->yearOfBirth = yearOfBirth;
                this->gender = gender;

        }
        void fillInfoRand() {
                this->surname = surnames[rand() % 10];
                this->country = countries[rand() % 10];
                this->age = rand() % 100 + 1;
                this->education = educations[rand() % 4];
                this->gender = (rand() % 2 == 0) ? 'M' : 'F';
                this->yearOfBirth = 2025 - age;
        }
        void show(){
            std::cout << "--------------------------\n";
            std::cout << "Surname: " << surname << "\n";
            std::cout << "Country: " << country << "\n";
            std::cout << "Gender: " << gender << "\n";
            std::cout << "Education: " << education << "\n";
            std::cout << "Year of birth: " << yearOfBirth << "\n";
            std::cout << "Age: " << age << "\n";
        }
        void showHumanWithEducation(std::string education, int age){
            if (this->education == education && this->age > age){
            std::cout << "--------------------------\n";
            std::cout << "Surname: " << surname << "\n";
            std::cout << "Country: " << country << "\n";
            std::cout << "Gender: " << gender << "\n";
            std::cout << "Education: " << education << "\n";
            std::cout << "Year of birth: " << yearOfBirth << "\n";
            std::cout << "Age: " << age << "\n";
            }
        }
};

void deletePeople(People* people, int& size, char gender){
    for(int i = 0; i < size; i++){
        if(tolower(people[i].getGender()) == tolower(gender) ){
            for(int j = i; j < size - 1; j++){
                People temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
            size--;
            i--;
        }
    }
}

int main(){
    srand(time(0));
    while(1){
        std::cout << "Choose task(1 - flats, 2 - people):\n";
        int task;
        std::cin >> task;
        switch(task){
            case 1:
            {
                std::cout << "Enter number of flats(there will be + 1 with default values):\n";
                int size;
                std::cin >> size;
                size++;
                Flat* flats = new Flat[size];
                for(int i = 0; i < size - 1; i++){
                    std::cout << "Enter how you want to fill info (1 - random, 2 - manual):\n";
                    int type;
                    std::cin >> type;
                    switch (type){
                        case 1:
                            flats[i].fillInfoRand();
                            break;
                        case 2:
                            flats[i].fillInfo();
                            break;
                        default:
                            std::cout << "Invalid type\n";
                            break;
                    }
                }
                flats[size - 1] = Flat();
                std::cout << "Flats:\n";
                for(int i = 0; i < size; i++){
                    flats[i].show();
                }
                std::cout << "Enter number of rooms to show:\n";
                int numberOfRooms;
                std::cin >> numberOfRooms;
                std::cout << "Flats with " << numberOfRooms << " rooms:\n";
                for(int i = 0; i < size; i++){
                    flats[i].showFlatWithRooms(numberOfRooms);
                }
                std::cout << "Enter area (show flats with area lower) and range of floors to show:\n";
                double area;
                int start, end;
                std::cin >> area >> start >> end;
                std::cout << "Flats with area lower than " << area << " and floor between " << start << " and " << end << ":\n";
                for(int i = 0; i < size; i++){
                    flats[i].showFlatWithAreaWithinRange(area, start, end);
                }
                delete[] flats;
            }
            break;
            case 2:
            {
                std::cout << "Enter number of people(there will be + 1 with default values):\n";
                int size;
                std::cin >> size;
                size++;
                People* people = new People[size];
                for (int i = 0; i < size - 1; i++){
                    std::cout << "Enter how you want to fill info (1 - random, 2 - manual):\n";
                    int type;
                    std::cin >> type;
                    switch (type){
                        case 1:
                            people[i].fillInfoRand();
                            break;
                        case 2:
                            people[i].fillInfo();
                            break;
                        default:
                            std::cout << "Invalid type\n";
                            break;
                    }
                }
                people[size - 1] = People();
                std::cout << "People:\n";
                for (int i = 0; i < size; i++){
                    people[i].show();
                }
                std::cout << "choose education(1 - high school, 2 - bachelor, 3 - master, 4 - PhD):\n";
                int educationType;
                std::string education;
                std::cin >> educationType;
                switch (educationType){
                    case 1:
                        education = "High School";
                        break;
                    case 2:
                        education = "Bachelor's";
                        break;
                    case 3:
                        education = "Master's";
                        break;
                    case 4:
                        education = "PhD";
                        break;
                    default:
                        std::cout << "Invalid type\n";
                        break;
                }
                std::cout << "Enter age:\n";
                int age;
                std::cin >> age;
                std::cout << "People with edication " << education << " and older than " << age << ":\n";
                std::cout << "--------------------------\n";
                for (int i = 0; i < size; i++){
                    people[i].showHumanWithEducation(education, age);
                }
                People* newPeople = new People[size + 1];
                std::cout << "Enter index of person to copy:\n";
                int index;
                std::cin >> index;
                if (index < 0 || index >= size){
                    std::cout << "Invalid index\n";
                }
                else{
                    newPeople[0] = People(people[index]);
                }
                for (int i = 1; i < size + 1; i++){
                    newPeople[i] = People(people[i - 1]);
                }
                std::cout << "New people:\n";
                for (int i = 0; i < size + 1; i++){
                    newPeople[i].show();
                }
                deletePeople(people, size, 'M');
                std::cout << "People after deleting:\n";
                for (int i = 0; i < size; i++){
                    people[i].show();
                }
                delete[] people;
                delete[] newPeople;
            }
            break;
            default:
                std::cout << "Invalid task\n";
            break;
        }
    }
    return 0;
}