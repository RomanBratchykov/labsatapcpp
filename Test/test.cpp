#include <iostream>
#include <cstdarg>

void fillArray(int* ptr, int size = 10){
    for (int i = 0; i < size; i++){
        *(ptr + i) = rand() % 100;
    }
}

void fillMatrix(int** ptr, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            *(*(ptr + i) + j) = rand() % 100;
    }
}

void showMatrix(int** ptr, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            std::cout << *(*(ptr + i) + j) << " ";
        std::cout << "\n";
    }
   
}

void showArray(int* ptr, int size = 10){
    for (int i = 0; i < size; i++){
        std::cout << *(ptr + i) << " ";
    }
    std::cout << "\n";
}

int findMax(int* ptr, int size){
    int max = *ptr;
    for (int i = 0; i < size; i++){
        if (max < *(ptr + i)){
            max = *(ptr + i);
        }
    }
    return max;
}

int findMin(int* ptr, int size){
    int min = *ptr;
    for (int i = 0; i < size; i++){
        if (min > *(ptr + i)){
            min = *(ptr + i);
        }
    }
    return min;
}

void calculator(int x, int y, int choice){
    switch (choice){
        case 1:
            std::cout << x + y;
        break;
        case 2:
        std::cout << x - y;
        break;
        case 3:
        std::cout << x * y;
        break;
        case 4:
            if (y == 0){
                std::cout << "You can`t divide by zero\n";
                break;
            }
            std::cout << x / y;
            break;
        default:
            std::cout << "Choose something above\n";
            break;
    }
}

double average (int count, ...){
    va_list args;
    va_start(args, count);
    double sum = 0;
    for (int i = 0; i < count; i++){
        sum += va_arg(args, int);
    }
    return sum / count;
}

int main() {
    srand(time(0));
    std::cout << "Select task (1 - 5, 0 for exit)\n";
    int choice;
    std::cin >> choice;
    switch (choice){
        case 0:
        return 0;
        case 1:{
            std::cout << "Enter size of array:\n";
            int size;
            std::cin >> size;
            int* array = new int[size];
            int* ptr = array;
            fillArray(ptr, size);
            std::cout << "Your Array:\n";
            showArray(ptr, size);
            int min = findMin(ptr, size);
            int max = findMax(ptr, size);
            int maxIndex, minIndex;
            for (int i = 0; i < size; i++){
                if (*(ptr + i) == min)
                    minIndex = i;
                if (*(ptr + i) == max){
                    maxIndex = i;
                }
            }   
            std::cout << "Min num is = " << min << " and index is " << minIndex << "\nMax num is " << max << " and index is " << maxIndex << "\n";
            delete[] array;
        }
        break;
        case 2:{
            std::cout << "Enter size of array:\n";
            int size;
            std::cin >> size;
            int** array = new int*[size];
            for (int i = 0; i < size; i++){
                array[i] = new int[size];
            }
            
            fillMatrix(array, size);
            std::cout << "Your matrix = \n";
            showMatrix(array, size);
            int* secondArray = new int[size];
            int* ptr = secondArray;
            for (int i = 0; i < size; i++){
                *(ptr + i) = *(*(array + i) + i);
            }
            std::cout << "Array:\n";
            showArray(ptr, size);
            delete[] array;
            delete[] secondArray;
        }
        break;
        case 3:{
            std::cout << average(5, 2, 5, 6, 9, 1) << "\n";
            std::cout << average(5, 5, 7, 6, 2, 4) << "\n";
        }   
        break;
        case 4:{
            int* array = new int[2];
            std::cout << "Enter first number and second number\n";
            int num1, num2;
            std::cin >> num1>> num2;
            array[0] = num1;
            array[1] = num2;
            std::cout << "Choose operation(1 - add, 2 - find difference, 3 - multiply, 4 - divide)";
            int choice;
            std::cin >> choice;
            calculator(array[0], array[1], choice);
            void (*funcPtr)(int x, int y, int choice);
            funcPtr = &calculator;
            funcPtr(array[0], array[1], choice);
            delete[] array;
        }
        break;
        case 5:{
            std::cout << "Enter size of array:\n";
            int size;
            std::cin >> size;
            int* array = new int[size];
            int* ptr = array;
            fillArray(ptr, size);
            std::cout << "Your Array:\n";
            showArray(ptr, size);
            int* secondArray = new int[20];
            fillArray(secondArray);
            std::cout << "your second array with default size\n";
            showArray(secondArray);
            delete[] array;
            delete[] secondArray;
        }
        break;
        default:
            std::cout << "Invalid choice\n";
        break;
    }
    return 0;
}