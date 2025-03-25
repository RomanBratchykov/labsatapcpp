#include <iostream>
#include <iomanip>
#include <cstdarg>


void fillArray(int arr[], int size)
{
    std::cout << "Choose how to fill array(1 for manually, 2 for random):\n";
    int choise;
    std::cin >> choise;
    switch (choise) {
        case 1:
        {
            for (int i = 0; i < size; i++)
            {
                std::cout << "Enter " << i + 1 << " element: \n";
                std::cin >> arr[i];
            }
        }
        break;
        case 2:{
            std::cout << "Enter min and max value: ";
             int minValue, maxValue;
            std::cin >> minValue >> maxValue;
            for (int i = 0; i < size; i++)
            {
                arr[i] = rand() % (maxValue - minValue) + minValue;
            }
        }
            break;
        default:
            std::cout << "Invalid choise\n";
            break;
    }
}

void fillArrayUniques(int arr[], int size)
{
   
    std::cout << "Enter min and max value: ";
     int minValue, maxValue;
    std::cin >> minValue >> maxValue;
    for (int i = 0; i < size; i++)
    {
        int temp = rand() % (maxValue - minValue) + minValue;
        for (int j = 0; j < i; j++){
            if (arr[j] == temp){
                i--;
                break;
            }
        }
        arr[i] = temp;
    }
}

void showArray(int arr[], int size)
{
    std::cout << "Choose how to display array(1 for row, 2 for column):\n";
    int choise;
    std::cin >> choise;
    switch (choise) {
        case 1:
            for (int i = 0; i < size; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << "\n";
            break;
        case 2:
            for (int i = 0; i < size; i++)
                {
                    std::cout << arr[i] << "\n";
                }
            std::cout << "\n";
            break;
        default:
            std::cout << "Invalid choise\n";
            break;
    }
}

bool isMoreThan1(int arr[], int size, int value){
    int counter = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == value)
            counter++;
    }
    if (counter > 1)
        return true;
    return false;
}

int findMax(int arr[], int size){
    int max = arr[0];
    for (int j = 0; j < size; j++){
        if (arr[j] > max){
            max = arr[j];
        }
    }
    return max;
}

int findMin(int arr[], int size){
    int min = arr[0];
    for (int j = 0; j < size; j++){
        if (arr[j] < min){
            min = arr[j];
        }
    }
    return min;
}

void deleteElementsWithMoreThan1(int arr[], int& size, int value, bool isMoreThan1){
    int counter = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == value){
            if (!isMoreThan1)
                break;
            if (counter == 0){
                counter++;
                continue;
            }
            for (int j = i; j < size - 1; j++){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            size--;
            counter++;
            i--;
        }
    }
}

void moveElements(int arr[], int& size, int value) {
    int index = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == value){
            index = i; 
            break;
        }
    }
    int* temp = new int[size];
    int j = 0;
    temp[j++] = value;
    for (int i = index + 1; i < size; i++){
        temp[j++] = arr[i];
    }
    for (int i = 0; i < index; i++){
        temp[j++] = arr[i];
    }
    for (int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
}

bool isEvenMore(int arr[], int size){
    int counterForEven = 0;
    int counterForOdd = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0)
            counterForEven++;
        else
            counterForOdd++;
    }
    if (counterForEven == counterForOdd)
        return true;
    return counterForEven > counterForOdd;
}

int* createArray(int arr[], int size, int& newSize, bool isEvenMore){
    newSize = 0;
    int j = 0;
    for (int i = 0; i < size; i++) {
        if ((isEvenMore && arr[i] % 2 == 0) || (!isEvenMore && arr[i] % 2 != 0))
            newSize++;
    }
    int* secondArray = new int[newSize];
    for (int i = 0; i < size; i++) {
        if ((isEvenMore && arr[i] % 2 == 0) || (!isEvenMore && arr[i] % 2 != 0))
            secondArray[j++] = arr[i];
    }
        return secondArray;
} 
    
double findArea(int a = 10, int b = 10, int c = 10){
    if (a <= 0 || b <= 0 || c <= 0){
        std::cout << "Invalid sides\n";
        return 0;
    }
    return 2 * (a * b + b * c + a * c);
}

int* createArray2(int arr[], int size, int secondSize = 5){
    int* secondArray = new int[secondSize];
    for (int i = 0; i < secondSize; i++){
        secondArray[i] = arr[rand() % size];
    }
    return secondArray;
} 
  
int* createArray3(int size, int i1, int i2, ...){
    int* secondArray = new int[i2 - i1];
    va_list args;
    va_start(args, i2);
    for (int i = 0; i < i1; ++i) {
        va_arg(args, int);
    }
    for (int i = i1; i < i2; i++){
        secondArray[i - i1] = va_arg(args, int);
    }
    va_end(args);
    return secondArray;
}

int* returnIndexes(int arr1[], int size1, int arr2[], int& newSize, ...){
    std::cout << "How many indexces you have?\n";
    int size2;
    std::cin >> size2;
    int* indexes = new int[20];
    newSize = 0;
    va_list args;
    va_start(args, newSize);
    for (int j = 0; j < size2; j++){
        int index = va_arg(args, int);
        if (arr1[index] != arr2[index] && index < size1 && index < size2 && index >= 0){ 
            indexes[newSize++] = index;
        }
    }   
    va_end(args);
    return indexes;
}

void deleteElements(int arr[], int& size, int value){
    for (int i = 0; i < size; i++){
        if (arr[i] == value){
            for (int j = i; j < size - 1; j++){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            size--;
            i--;
        }
    }
}

void deleteElementsOut(int secondArray[], int& secondSize, int indexMin, int indexMax){
    if (indexMin < indexMax){
        for(int i = 0; i < indexMin; i++){
            deleteElements(secondArray, secondSize, secondArray[i]);
        }
        for (int i = indexMax + 1; i < secondSize; i++){
            deleteElements(secondArray, secondSize, secondArray[i]);
        }
        std::cout << "Array with deleted elements out of max and min: \n";
        showArray(secondArray, secondSize);
    }
    else{
        for(int i = 0; i < indexMax; i++){
            deleteElements(secondArray, secondSize, secondArray[i]);
        }
        for (int i = indexMin + 1; i < secondSize; i++){
            deleteElements(secondArray, secondSize, secondArray[i]);
        }
        std::cout << "Array with deleted elements out of max and min: \n";
        showArray(secondArray, secondSize);
    }
}


int main() {
    srand(time(0));
    while(1) {
        int num;
        std::cout << "Enter number of task(1-5, 0 for exit): \n";
        std::cin >> num;
         switch(num)
           {
            case 0:
            return 0;
            case 1:
            {
                std::cout << "Enter size of array:\n";
                int size;
                std::cin >> size;
                int* array = new int[size];
                fillArray(array,size);
                int* secondArray = new int[size];
                std::cout << "Array: \n";
                showArray(array, size);
                int max = findMax(array, size);
                int min = findMin(array, size);
                bool maxBool = isMoreThan1(array, size, max);
                bool minBool = isMoreThan1(array, size, min);
                std::cout << "Array with only one max and min: \n";
                deleteElementsWithMoreThan1(array, size, max, maxBool);
                deleteElementsWithMoreThan1(array, size, min, minBool);
                for (int i = 0; i < size; i++){
                    secondArray[i] = array[i];
                }
                showArray(array, size);
                moveElements(array, size, min);
                int indexMin = 0, indexMax;
                for (int i = 0; i < size; i++){
                    if (secondArray[i] == min)
                        indexMin = i;
                        if (secondArray[i] == max)
                            indexMax = i;
                }
                int secondSize = size;
                deleteElementsOut(secondArray, secondSize, indexMin, indexMax);
                std::cout << "Array with moved min: \n";
                showArray(array, size);
                int newSize;
                int* arrPtr = createArray(array, size, newSize, isEvenMore(array, size));
                std::cout << "Array with " << (isEvenMore(array, size) ? "even" : "odd") << " numbers: \n";
                for (int i = 0; i < newSize; i++){
                    std::cout << *(arrPtr + i) << " ";
                }
                std::cout << "\n";
                delete[] array;
                delete[] arrPtr;
            }
            break;
            case 2:
            {
                std::cout << "Enter sides of paralelepiped(default: a = 10, b = 10, c = 10): ";
                int first, second, third;
                std::cin >> first >> second >> third;
                std::cout << "Area of yours paralelepiped = " << findArea(first, second, third) << "\n"; 
                std::cout << "Area of default paralelepiped: " << findArea() <<" \n";
                std::cout << "Area of paralelepiped with default a: " << findArea(second, third) <<" \n";
                std::cout << "Area of paralelepiped with default b: " << findArea(first, third) <<" \n";
                std::cout << "Area of paralelepiped with default c: " << findArea(first, second) <<" \n";
                std::cout << "Area of paralelepiped with default c and b: " << findArea(third) <<" \n";
            }
            break;
            case 3:
            {
                std::cout << "Enter size of array:\n";
                int size;
                std::cin >> size;
                int* array = new int[size];
                fillArrayUniques(array, size);
                std::cout << "Your array: \n";
                showArray(array, size);
                int secondSize;
                std::cout << "Enter size of second array: ";
                std::cin >> secondSize;
                if (secondSize > size){
                    std::cout << "Invalid size\n";
                    break;
                }
                int* secondArray = createArray2(array, size, secondSize);
                int* secondArrayDefault = createArray2(array, size);
                std::cout << "Second array: \n";
                showArray(secondArray, secondSize);
                std::cout << "Second array with default size: \n";
                showArray(secondArrayDefault, 5); 
                delete[] array;
                delete[] secondArray;
            }
            break;
            case 4:
            {
                std::cout << "Enter size of array:\n";
                int size;
                std::cin >> size;
                int* array = new int[size];
                fillArray(array,size);
                std::cout << "Array: \n";
                showArray(array, size);
                std::cout << "Enter i1 and i2(indexes of elements from first array that will be added in second): \n";
                int i1, i2;
                std::cin >> i1 >> i2;
                if (i1 < 0 || i1 >= size || i2 < 0 || i2 >= size){
                    std::cout << "Invalid indexes\n";
                    break;
                }
                int* secondArray = createArray3(size, i1, i2, array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9], array[10], array[11]); 
                std::cout << "Second array: \n";
                showArray(secondArray, i2 - i1);
                delete[] array;
                delete[] secondArray;
            }
            break;
            case 5:
            {
                std::cout << "Enter size of arrays:\n";
                int size;
                std::cin >> size;
                int* array = new int[size];
                fillArray(array,size);
                std::cout << "Array: \n";
                showArray(array, size);
                int* secondArray = new int[size];
                fillArray(secondArray, size);
                std::cout << "Second array: \n";
                showArray(secondArray, size);
                int newSize;
                int* indexes = returnIndexes(array, size, secondArray, newSize, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
                std::cout << "Indexes of elements from first array that are not in second array: \n";
                for (int i = 0; i < newSize; i++){
                    std::cout << indexes[i] << " ";
                }
                std::cout << "\n";
                delete[] array;
                delete[] secondArray;
                delete[] indexes;
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}