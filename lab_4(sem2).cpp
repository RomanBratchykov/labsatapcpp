#include <iostream>
#include <iomanip>

void showArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

float* createDynamicArrayFloat(float arr[], int size, int& newSize)
{
    newSize = 0;
    for (int i = 0; i < size; i++){
        if ((int)arr[i] % 2 == 0 && i % 2 != 0) 
            newSize++;
    }
    if (newSize == 0) {
        std::cout << "No elements that are even and have odd index\n";
        return nullptr;
    }
    float* secondArray = new float[newSize];
    int j = 0;
    for (int i = 0; i < size; i++){
        if ((int)arr[i] % 2 == 0 && i % 2 != 0) 
            secondArray[j++] = arr[i];
    }
    return secondArray;
}

void fillArray(int arr[], int size)
{
    std::cout << "Enter min and max value: ";
    int minValue, maxValue;
    std::cin >> minValue >> maxValue;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (maxValue - minValue) + minValue;
    }
}

void showArrayFloats(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << std::fixed << std::setprecision(2)<< arr[i] << " ";
    }
    std::cout << "\n";
}

void fillArrayFloats(float arr[], int size)
{
    std::cout << "Enter min and max value: ";
    int minValue, maxValue;
    std::cin >> minValue >> maxValue;
    minValue *= 100;
    maxValue *= 100;
    for (int i = 0; i < size; i++){
        arr[i] = (float)(rand() % (maxValue - minValue) + minValue) / 100.0;
    }
    
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

int findMax(int arr[], int size){
    int max = arr[0];
    for (int j = 0; j < size; j++){
        if (arr[j] > max){
            max = arr[j];
        }
    }
    return max;
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
                std::cout << "Enter size of array: ";
                int size;
                std::cin >> size;
                float* firstArray = new float[size];
                float* secondArray = new float[size];
                fillArrayFloats(firstArray, size);
                std::cout << "First array: \n";
                showArrayFloats(firstArray, size);
                fillArrayFloats(secondArray, size);
                std::cout << "Second array: \n";
                showArrayFloats(secondArray, size);
                int counterFirst = 0, counterSecond = 0;
                for (int i = 0; i < size; i++){
                    if ((int)firstArray[i] % 3 != 0 )
                        counterFirst++;
                    if ((int)secondArray[i] % 3 != 0 )
                        counterSecond++;
                }
                if (counterFirst > counterSecond){
                    std::cout << "First array got more numbers that are divisible by 3\n";
                    showArrayFloats(firstArray, size);
                }
                
                if (counterFirst < counterSecond){
                    std::cout << "Second array got more numbers that are divisible by 3\n";
                    showArrayFloats(secondArray, size);
                }
                if (counterFirst == counterSecond)
                    std::cout << "Both arrays have the same number of elements that are not divisible by 3\n";
                delete[] firstArray;
                delete[] secondArray;
            }
            break;
            case 2:
            {
                std::cout << "Enter size of array: ";
                int size;
                std::cin >> size;
                float* firstArray = new float[size];
                fillArrayFloats(firstArray, size);
                std::cout << "First array: \n";
                showArrayFloats(firstArray, size);
                int newSize;
                float* (*funcPointer)(float*, int, int&);
                funcPointer = createDynamicArrayFloat;
                float* secondArray = funcPointer(firstArray, size, newSize);
                std::cout << "Second array: \n";
                showArrayFloats(secondArray, newSize);
                delete[] firstArray;
                delete[] secondArray;
            }
            break;
            case 3:
            {
                std::cout << "Enter size of array: ";
                int size;
                std::cin >> size;
                float* firstArray = new float[size];
                fillArrayFloats(firstArray, size);
                std::cout << "First array: \n";
                showArrayFloats(firstArray, size);
                int counter = 0;
                for (int i = 0; i < size; i++){
                    if ((int)firstArray[i] % 2 == 0 ){
                        counter++;
                    }
                }
                int j = 0;
                float* secondArray = new float[counter];
                for (int i = 0; i < size; i++)
                {
                    if ((int)firstArray[i] % 2 == 0)
                    {
                        secondArray[j++] = firstArray[i];
                        for (int k = j; k > 0; k--)
                        { 
                            if (firstArray[i] < secondArray[k - 1])
                            {
                                float temp = secondArray[k];
                                secondArray[k] = secondArray[k - 1];
                                secondArray[k - 1] = temp;
                            }
                        }     
                    }
                }
                std::cout << "Second array: \n";
                showArrayFloats(secondArray, counter);
                delete[] firstArray;
                delete[] secondArray;
            }
            break;
            case 4:
            {
                std::cout << "Enter size of array: ";
                int size;
                std::cin >> size;
                int* firstArray = new int[size];
                fillArray(firstArray, size);
                std::cout << "First array: \n";
                showArray(firstArray, size);
                for (int i = 0, j = 0; i < size; i++){
                    if (firstArray[i] < 0 && i != 0){
                     
                       std::cout <<  findMax(firstArray, i) + findMin(firstArray, i) << " ";
                       std::cout << firstArray[i] << " ";
                    }
                    else
                        std::cout << firstArray[i] << " ";

                    std::cout << "\n";
                    delete[] firstArray;
                }
                // int currentSize = size;
                // for (int i = 0; i < size; i++){
                //     if (firstArray[i] < 0){
                //         currentSize++;
                //     }
                // }
                // int* secondArray = new int[currentSize];
                // for (int i = 0, j = 0; i < size; i++){
                //     if (firstArray[i] < 0 && i != 0){
                        
                //         secondArray[j++] = findMax(firstArray, i) + findMin(firstArray, i);
                //         secondArray[j++] = firstArray[i];
                //     }
                //     else
                //         secondArray[j++] = firstArray[i];
                // }
                // std::cout << "Final array: \n";
                // showArray(secondArray, currentSize);
                // delete[] firstArray;
                // delete[] secondArray;
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}