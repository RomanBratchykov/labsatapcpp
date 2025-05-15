#include <iostream>
#include <cmath>
#include <vector>

class Figure {
public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void area() override {
        std::cout << "Area of Rectangle: " << length * width << "\n";
    }
    void perimeter() override {
        std::cout << "Perimeter of Rectangle: " << 2 * (length + width) << "\n";
    }
};

class Triangle : public Figure {
private:
    double sideA, sideB, sideC;
public:
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}
    void area() override {
        double s = (sideA + sideB + sideC) / 2;
        double area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
        std::cout << "Area of Triangle: " << area << "\n";
    }
    void perimeter() override {
        std::cout << "Perimeter of Triangle: " << (sideA + sideB + sideC) << "\n";
    }
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void area() override {
        std::cout << "Area of Circle: " << 3.14 * radius * radius << "\n";
    }
    void perimeter() override {
        std::cout << "Perimeter of Circle: " << 2 * 3.14 * radius << "\n";
    }
};

class Worker {
    private:
        int numberOfWorker;
        std::string surname;
    public:
        virtual int salary(int fixedWage = 10000) = 0;
    Worker(int numberOfWorker, std::string surname) : numberOfWorker(numberOfWorker), surname(surname) {}
        virtual ~Worker() {}
    int getNumberOfWorker() {
        return numberOfWorker;
    }
    std::string getSurname(){
        return surname;
    }
    bool operator==(Worker& other){
        return numberOfWorker == other.getNumberOfWorker(); 
    }
};

class Manager : public Worker {
    int numberOfWorkers;
    public:
        Manager (int numberOfWorker, std::string surname, int numberOfWorkers) : Worker(numberOfWorker, surname), numberOfWorkers(numberOfWorkers){}
        int salary(int fixedWage) override {
            return numberOfWorkers > 5 ? fixedWage + (fixedWage * 0.1) : fixedWage;;
        }
};
class Developer : public Worker {
    int hourWage;
    int hoursWorked;
    public:
        Developer(int numberOfWorker, std::string surname, int hourWage, int hoursWorked) : Worker(numberOfWorker, surname), hourWage(hourWage), hoursWorked(hoursWorked){}
    int salary(int fixedWage) override {
        return hourWage * hoursWorked;
    }
};
int main() {
    srand(time(0));
    std::cout << "Enter number of task(1-2, 0 for exit):\n";
    int task;
    std::cin >> task;
    
    switch (task) {
        case 1: {
            std::cout << "Enter number of figures:\n";
            int num;
            std::cin >> num;

            std::vector<Figure*> figuresVec;

            for (int i = 0; i < num; ++i) {
                std::cout << "Enter type of figure (1 - Rectangle, 2 - Triangle, 3 - Circle):\n";
                int type;
                std::cin >> type;

                if (type == 1) {
                    double length, width;
                    std::cout << "Enter length and width of rectangle:\n";
                    std::cin >> length >> width;
                    figuresVec.push_back(new Rectangle(length, width));
                }
                else if (type == 2) {
                    double a, b, c;
                    std::cout << "Enter sides of triangle:\n";
                    std::cin >> a >> b >> c;
                    figuresVec.push_back(new Triangle(a, b, c));
                }
                else if (type == 3) {
                    double r;
                    std::cout << "Enter radius of circle:\n";
                    std::cin >> r;
                    figuresVec.push_back(new Circle(r));
                }
                else {
                    std::cout << "Invalid figure type!\n";
                    --i;
                }
            }

            std::cout << "\nYour results:\n";
            for (int i = 0; i < figuresVec.size(); ++i) {
                std::cout << "Figure " << i + 1 << ":\n";
                figuresVec[i]->area();
                figuresVec[i]->perimeter();
                std::cout << "\n";
            }


            for (Figure* fig : figuresVec)
                delete fig;
            figuresVec.clear();

            break;
        }
        case 2:
            {
                std::cout << "Enter number of workers:\n";
                int num;
                std::cin >> num;
                std::vector<Worker*> workersVec;
                for (int i = 0; i < num; ++i) {
                    std::cout << "Enter type of worker (1 - Manager, 2 - Developer):\n";
                    int type;
                    std::cin >> type;

                    if (type == 1) {
                        int numberOfWorker, numberOfWorkers;
                        std::string surname;
                        std::cout << "Enter number of worker, surname and number of workers:\n";
                        std::cin >> numberOfWorker >> surname >> numberOfWorkers;
                        workersVec.push_back(new Manager(numberOfWorker, surname, numberOfWorkers));
                    }
                    else if (type == 2) {
                        int numberOfWorker, hourWage, hoursWorked;
                        std::string surname;
                        std::cout << "Enter number of worker, surname, hour wage and hours worked:\n";
                        std::cin >> numberOfWorker >> surname >> hourWage >> hoursWorked;
                        workersVec.push_back(new Developer(numberOfWorker, surname, hourWage, hoursWorked));
                    }
                    else {
                        std::cout << "Invalid worker type!\n";
                        --i;
                    }
                }
                std::cout << "\nYour results:\n";
                for (int i = 0; i < workersVec.size(); ++i) {
                    std::cout << "Worker " << i + 1 << ":\n";
                    std::cout << "Number of worker: " << workersVec[i]->getNumberOfWorker() << "\n";
                    std::cout << "Surname: " << workersVec[i]->getSurname() << "\n";
                    std::cout << "Salary: " << workersVec[i]->salary() << "\n";
                    std::cout << "\n";
                }
                for (int i = 0; i < workersVec.size(); i++){
                    if (workersVec[i] == workersVec[i + 1]){
                        std::cout << "Worker " << i + 1 << " is the same as Worker " << i + 2 << "\n";
                    }
                }
                for (Worker* fig : workersVec)
                    delete fig;
                    workersVec.clear();
                
            }
        break;

        case 0:
        break;
        default:
            std::cout << "Invalid task number.\n";
        break;
    }

    return 0;
}
