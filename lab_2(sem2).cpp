#include <iostream>

void fillArray(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(ptr + i) = rand() % 100 - 50;
    }
}

void fillArrayFloats(float* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(ptr + i) = (float)(rand() % 1000) / 100;
    }
}

void bubbleSort(int* ptr, int size, std::string order = "asc"){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (*(ptr + j) > *(ptr + j + 1) && order == "asc"){
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
            else if (*(ptr + j) < *(ptr + j + 1) && order == "desc"){
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}

void findThree(float* ptr, int size)
{
    bool found = false;
    if (size < 3){
        std::cout<<"Array is too small\n";
        return;
    }
    for (int i = 0; i < size - 2; i++)
    {
        if (*(ptr + i) > *(ptr + i + 1) && *(ptr + i + 1) > *(ptr + i + 2))
        { 

            std::cout << "Descending part starts from " << i + 1 << " element to " << i + 3 <<"\n";
            found = true;
            std::cout << "First element: " << *(ptr + i) << std::endl;
            std::cout << "Second element: " << *(ptr + i + 1) << std::endl;
            std::cout << "Third element: " << *(ptr + i + 2) << std::endl;
        }  
    }
    if (found = false) std::cout << "No descending parts\n";
}

int numbersBiggerThanLeft(int *ptr, int size){
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        if (*(ptr + i) > *(ptr + i - 1))
        {
            count++;
        }
    }
    return count;
}

int numbersBelowZero(int *ptr, int size){
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(ptr + i) < 0)
        {
            count++;
        }
    }
    return count;
}
int main() {
    while(1) {
        int num;
        std::cout << "Enter number of task(1-6, 0 for exit): \n";
        std::cin >> num;
         switch(num)
           {
            case 0:
                return 0;
            case 1:
                {
                    int size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    float arr[size];
                    float *ptr = arr;
                    fillArrayFloats(ptr, size);
                    std::cout << "Array: ";
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *(ptr + i) << " ";
                    }
                    std::cout << "\n";
                    float min = *ptr;
                    for (int i = 0; i < size; i++)
                    {
                        if (*(ptr + i) < min && i % 2 == 0)
                        {
                            min = *(ptr + i);
                        }
                    }
                    std::cout << "Min element: " << min << std::endl;
                }
            break;
            case 2:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                float arr[size];
                float *ptr = arr;
                fillArrayFloats(ptr, size);
                std::cout << "Array: ";
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *(ptr + i) << " ";
                    }
                    std::cout << "\n";
                for (int i = 0; i < size; i++)
                {
                    std::cout << *(ptr + i) << " ";
                }
                std::cout<<"\n";
                findThree(ptr, size);
            }
            break;
            case 3:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                int arr[size];
                int *ptr = arr;
                fillArray(ptr, size);
                std::cout << "Array: ";
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *(ptr + i) << " ";
                    }
                    std::cout << "\n";
                std::cout << "Number of elements bigger than left: " << numbersBiggerThanLeft(ptr, size) << std::endl;
            }
            break;
            case 4:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                int arr[size];
                int *ptr = arr;
                std::cout << "address of array = " << ptr << "\n";
                fillArray(ptr, size);
                std::cout << "Array: ";
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *(ptr + i) << " ";
                    }
                    std::cout << "\n";
                std::cout << "Numbers below 0: "<< numbersBelowZero(ptr, size) << "\n";
                for (int i = 0; i < size; i++){
                    if (*(ptr + i) < 0)
                    std::cout << "address of " << i + 1 << " element = " << ptr + i << "\n";
                }
            }
            break;
            case 5:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                float arr[size];
                float *ptr = arr;
                fillArrayFloats(ptr, size);
                std::cout << "Array: ";
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *(ptr + i) << " ";
                    }
                    std::cout << "\n";
                int newSize = size;
                for (int i = 0; i < size; i++){
                    if((int)(*(ptr + i)) % 5 == 0 && (int)(*(ptr + i)) != 0)
                    newSize++;
                }
                float* newArr = new float[newSize];
                float *newPtr = newArr;
                float sum = 0;
                for (int i = 0; i < size; i++){
                    *newPtr = *(ptr + i);
                    sum += *(ptr + i);
                    newPtr++;
                    if ((int)(*(ptr + i))  % 5 == 0 && (int)(*(ptr + i)) != 0){
                       *newPtr = sum - *(ptr + i);
                        newPtr++;
                    }
                }
                newPtr = newArr;
                std::cout << "New array: ";
                for (int i = 0; i < newSize; i++){
                    std::cout << *(newPtr + i) << " ";
                }
                std::cout << "\n";
            }
            break;
            case 6:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                int arr[size];
                int *ptr = arr;
                fillArray(ptr, size);
                std::cout << "Array: ";
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *(ptr + i) << " ";
                    }
                    std::cout << "\n";
                int evenCount = 0;
                int oddCount = 0;
                for (int i = 0; i < size; i++){
                    if (*(ptr + i) % 2 == 0){
                        evenCount++;
                    }
                    else{
                        oddCount++;
                    }
                }
                int* evenArr = new int[evenCount];
                int* oddArr = new int[oddCount];
                int* evenPtr = evenArr;
                int* oddPtr = oddArr;
                for (int i = 0; i < size; i++){
                    if(*(ptr + i) % 2 == 0){
                        *evenPtr = *(ptr + i);
                        evenPtr++;
                    }
                    else{
                        *oddPtr = *(ptr + i);
                        oddPtr++;
                    }
                }
                evenPtr = evenArr;
                oddPtr = oddArr;
                bubbleSort(evenPtr, evenCount, "asc");
                bubbleSort(oddPtr, oddCount, "desc");
                evenPtr = evenArr;
                oddPtr = oddArr;
                for (int i = 0; i < size; i++) {
                    if (*(ptr + i) % 2 == 0) {
                         *(arr + i) = *evenPtr++;
                    } 
                    else {
                        *(arr + i) = *oddPtr++;
                    }
                }
                std::cout << "New array: ";
                for (int i = 0; i < size; i++){
                    std::cout << *(ptr + i) << " ";
                }
                std::cout << "\n";
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}