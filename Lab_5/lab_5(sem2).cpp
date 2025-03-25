#include <iostream>
#include <iomanip>
#include <fstream>

void showArray(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << std::setw(3) << arr[i][j] << " ";
        std::cout << "\n";
    }
    
}

void fillArray(int** arr, int size, char type = 'b')
{
    std::cout << "Enter min and max value: ";
    int minValue, maxValue;
    std::cin >> minValue >> maxValue;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            if (type == 'b'){
                if (rand() % 2 == 0)
                    arr[i][j] = rand() % (maxValue - minValue) + minValue;
                else
                    arr[i][j] = -(rand() % (maxValue - minValue) + minValue);
            }
            else if (type == '-'){
                int temp = rand() % (maxValue - minValue) + minValue;
                if (temp > 0)
                arr[i][j] = -temp;
                else 
                arr[i][j] = temp;
            }
            else if (type == '+'){
                int temp = rand() % (maxValue - minValue) + minValue;
                if (temp < 0)
                arr[i][j] = -temp;
                else 
                arr[i][j] = temp;
                
            }
    }
}

void bubbleSort(int* arr, int size, std::string order = "asc"){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1] && order == "asc"){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if (arr[j] < arr[j + 1] && order == "desc"){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int numberOfColumns(int** arr, int size){
    int counter = 0;
    bool isPreviousBigger = true;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (arr[j][i] < arr[j + 1][i])
            {
                isPreviousBigger = false;
                break;
            }
        }
        if (isPreviousBigger)
            counter++;
    }
    return counter;
}

bool isSameDigit(int num){
    int firstDigit = num % 10;
    int secondDigit = num / 10;
    return firstDigit == secondDigit;
}


int main() {
    srand(time(0));
    while(1) {
        int num;
        std::cout << "Enter number of task(1-4, 0 for exit): \n";
        std::cin >> num;
         switch(num)
           {
            case 0:
            return 0;
            case 1:
            {
                std::cout << "Enter size of array(it will be matrix NxN): ";
                int size;
                std::cin >> size;
                int** firstArray = new int*[size];
                for (int i = 0; i < size; i++){
                    firstArray[i] = new int[size];
                }
                fillArray(firstArray, size);
                std::cout << "Filled matrix: \n";
                showArray(firstArray, size);
                int average = 0;
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        average += firstArray[i][j];
                    }
                }
                int* arrayForCounter = new int[size];
                average /= size * size;
                std::cout << "Your average = " << average << "\n";
                std::ofstream fileToWrite("matrix_task1.txt", std::ios::app);
                fileToWrite << "Your results: " << "\n";
                for (int i = 0; i < size; i++){
                    int counter = 0;
                    for (int j = 0; j < size; j++){
                        if (firstArray[i][j] < average)
                            counter++;
                    }
                    arrayForCounter[i] = counter;
                    fileToWrite << "Row " << i + 1 << " has " << counter << " elements less than average\n";
                    std::cout << "Row " << i + 1 << " has " << counter << " elements less than average\n";
                }
                std::cout << "test\n";
                for (int i = 0; i < size; i++){
                    std::cout << arrayForCounter[i] << " ";
                }
                std::cout << "\n";
                fileToWrite.close();
                delete[] firstArray;
                delete[] arrayForCounter;
            }
            break;
            case 2:
            {
                std::cout << "Enter size of array(it will be matrix NxN): ";
                int size;
                std::cin >> size;
                int** firstArray = new int*[size];
                for (int i = 0; i < size; i++){
                    firstArray[i] = new int[size];
                }
                fillArray(firstArray, size);
                std::cout << "Filled matrix: \n";
                showArray(firstArray, size);
                std::cout << "Number of columns which have elements in ascending order: " << numberOfColumns(firstArray, size) << "\n";
                delete[] firstArray;
            }
            break;
            case 3:
            {
                std::cout << "Enter size of array(it will be matrix NxN): ";
                int size;
                std::cin >> size;
                int** firstArray = new int*[size];
                for (int i = 0; i < size; i++){
                    firstArray[i] = new int[size];
                }
                fillArray(firstArray, size);
                std::cout << "Filled matrix: \n";
                showArray(firstArray, size);
                for (int i = 0; i < size; i++){
                    bubbleSort(firstArray[i], size, "desc");
                }
                std::cout << "Sorted matrix: \n";
                showArray(firstArray, size);
                std::ofstream fileToWrite("matrix_task3.txt", std::ios::app);
                fileToWrite << "Sorted matrix: \n";
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        fileToWrite << firstArray[i][j] << " ";
                    }
                    fileToWrite << "\n";
                }
                fileToWrite.close();
                delete[] firstArray;
            }
            break;
            case 4:
            {
                std::cout << "Enter size of array(it will be matrix NxN): ";
                int size;
                std::cin >> size;
                int** firstArray = new int*[size];
                for (int i = 0; i < size; i++){
                    firstArray[i] = new int[size];
                }
                fillArray(firstArray, size);
                std::cout << "Filled matrix: \n";
                showArray(firstArray, size);
                for (int i = 0; i < size; i++){
                    int sum = 0;
                    for (int j = 0; j < size; j++){
                        sum+= firstArray[j][i];
                        if (isSameDigit(firstArray[j][i])){
                            i++;
                            break;
                        }
                    }
                    std::cout << "Column number " << i + 1 << " has no same digits, and sum of numbers in it = " << sum << "\n";
                }
                delete[] firstArray;
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}
