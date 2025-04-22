#include <iostream>
#include <iomanip>

class Time {
    int hours;
    int minutes;
    int seconds;

    void fix(){
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (hours >= 24) {
            hours %= 24;
        }
        if (hours < 0) {
            hours = 24 + hours % 24;
        }
        if (minutes < 0) {
            minutes -= seconds / 60;
            seconds %= 60;
        }
        if (seconds < 0) {
            seconds = 60 + seconds % 60;
            minutes -= 1;
        }
    }
    public:
    Time(int h = 0, int m = 0, int s = 0){
        hours = h;
        minutes = m;
        seconds = s;
        fix();
    }
    ~Time(){}
    void setTime(){
        int h, m, s;
        std::cout << "Enter time (hours, minutes, seconds)\n";
        std::cin >> h >> m >> s;
        hours = h;
        minutes = m;
        seconds = s;
        fix();
    }
    void show(){
        std::cout << hours << ":" << minutes << ":" << seconds << "\n";
    }

    Time operator+(const Time& t2) {return Time(this->hours + t2.hours, this->minutes + t2.minutes, this->seconds + t2.seconds);}
    Time operator-(const Time& t2){return Time(this->hours - t2.hours, this->minutes - t2.minutes, this->seconds - t2.seconds);}


    bool operator<(const Time& t2){
        if (this->hours < t2.hours) return true;
        if (this->hours > t2.hours) return false;
        if (this->minutes < t2.minutes) return true;
        if (this->minutes > t2.minutes) return false;
        if (this->seconds < t2.seconds) return true;
        return false;
    }
    bool operator>(const Time& t2)
    {
        if (this->hours > t2.hours) return true;
        if (this->hours < t2.hours) return false;
        if (this->minutes > t2.minutes) return true;
        if (this->minutes < t2.minutes) return false;
        if (this->seconds > t2.seconds) return true;
        return false;
    }
    bool operator==(const Time& t2)
    {
        if (this->hours == t2.hours && this->minutes == t2.minutes && this->seconds == t2.seconds) return true;
        return false;
    }
};    

class Matrix{
    int size;
    int** info;
    public:
    Matrix(int s = 0){
        size = s;
        info = new int*[size];
        for (int i = 0; i < size; i++){
            info[i] = new int[size];

        }
    }
    void fillMatrix(int start, int range){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                info[i][j] = rand() % range + start;
            }
        }
    }
    void show(){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                std::cout << info[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend Matrix operator-(const Matrix& m1, const Matrix& m2);
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
    friend bool operator==(const Matrix& m1, const Matrix& m2);
    ~Matrix(){}
};

Matrix operator+(const Matrix& m1, const Matrix& m2){
    Matrix m(m1.size);
    for (int i = 0; i < m1.size; i++){
        for (int j = 0; j < m1.size; j++){
            m.info[i][j] = m1.info[i][j] + m2.info[i][j];
        }
    }
    return m;
}

Matrix operator-(const Matrix& m1, const Matrix& m2){
    Matrix m(m1.size);
    for (int i = 0; i < m1.size; i++){
        for (int j = 0; j < m1.size; j++){
            m.info[i][j] = m1.info[i][j] - m2.info[i][j];
        }
    }
    return m;
}

Matrix operator*(const Matrix& m1, const Matrix& m2){
    Matrix m(m1.size);
    for (int i = 0; i < m1.size; i++){
        for (int j = 0; j < m1.size; j++){
            m.info[i][j] = 0;
            for (int k = 0; k < m1.size; k++){
                m.info[i][j] += m1.info[i][k] * m2.info[k][j];
            }
        }
    }
    return m;
}

bool operator==(const Matrix& m1, const Matrix& m2){
    for (int i = 0; i < m1.size; i++){
        for (int j = 0; j < m1.size; j++){
            if (m1.info[i][j] != m2.info[i][j]) return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));
    while (1){
        std::cout << "Select task(1-2, 0 for exit):\n";
        int task;
        std::cin >> task;
        if (task == 0) break;
        switch(task){
            case 1:{
                std::cout << "Create first time(1 - manual, 2 - random):\n";
                int choice1;
                std::cin >> choice1;
                Time t1;
                switch(choice1){
                    case 1:{
                        t1.setTime();
                    }
                    break;
                    case 2:{
                        t1 = Time(rand() % 24, rand() % 60, rand() % 60);
                    }
                    break;
                    default:
                        std::cout << "Invalid choice\n";
                        break;
                }
                std::cout << "Create second time(1 - manual, 2 - random):\n";
                int choice2;
                std::cin >> choice2;
                Time t2;
                switch(choice2){
                    case 1:{
                        t2.setTime();
                    }
                    break;
                    case 2:{
                        t2 = Time(rand() % 24, rand() % 60, rand() % 60);
                    }
                    break;
                    default:
                        std::cout << "Invalid choice\n";
                        break;
                }
                std::cout << "First time: ";
                t1.show();
                std::cout << "Second time: ";
                t2.show();
                std::cout << "Sum: ";
                Time t3 = t1 + t2;
                t3.show();
                std::cout << "Difference: ";
                Time t4 = t1 - t2;
                t4.show();
                std::cout << "First time < Second time: " << ((t1 < t2) ? "Second time higher\n" : "First time higher\n");
                std::cout << "First time > Second time: " << ((t1 > t2) ? "First time higher\n" : "Second time higher\n");
                std::cout << "First time == Second time: " << ((t1 == t2) ? "Equal\n" : "Not Equal\n");
            }
            break;
            case 2:{
                std::cout << "Enter size of matrix\n";
                int size;
                std::cin >> size;
                Matrix m1(size);
                std::cout << "Enter start and range\n";
                int start, range;
                std::cin >> start >> range;
                m1.fillMatrix(start, range);
                std::cout << "First matrix:\n";
                m1.show();
                std::cout << "Second matrix:\n";
                Matrix m2(size);
                std::cout << "Enter start and range\n";
                std::cin >> start >> range;
                m2.fillMatrix(start, range);
                m2.show();
                std::cout << "Sum:\n";
                Matrix m3 = m1 + m2;
                m3.show();
                std::cout << "Difference:\n";
                Matrix m4 = m1 - m2;
                m4.show();
                std::cout << "Multiplication:\n";
                Matrix m5 = m1 * m2;
                m5.show();
                std::cout << "First matrix == Second matrix: " << ((m1 == m2) ? "Equal\n" : "Not Equal\n");
            }
            break;
            default:
                std::cout << "Invalid task number\n";
                break;
        }
    }
}
