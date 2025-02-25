#include <iostream>
#include <cmath>
#include <cstdlib>

bool CheckIfMultipleOf(int x){
    if (x % 5 == 0){
        return true;
    }
    else{
        return false;
    }
}
void FillArray(int *arr, int n){
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 8-2;
    }
}
void ShowArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void ShowMatrix(int arr[][5], int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            std::cout << arr[i][j] << " ";
    std::cout << "\n";
}
void createMatrix(int arr[], int matrix[][5], int n){
    for (int i = 0; i < n/5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = arr[i*5+j];
        }
    }
}

int main(){
        int m;
        while (1){
        std::cout << "Enter the number of elements in the array(m must be multiple of 5)\n";
        std::cin >> m;
        if (CheckIfMultipleOf(m)){
            break;
        }
        else{
            std::cout << "m is not multiple of 5\n";
        }
    }
    int arr[m];
    FillArray(arr, m);
    ShowArray(arr, m);

    int matrix[m/5][5];
}