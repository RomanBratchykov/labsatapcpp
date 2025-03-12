#include <iostream>

int main() 
{
    std::cout << "Enter size of array:\n";
    int size;
    std::cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    size *= 2;
    for (int i = size/2; i < size; i++){
        arr[i] = arr[i - size/2];
    }
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    delete[] arr;
}