#include <iostream>
#include <stdio.h>

int main() {
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int **double_pointer;
    int *pointers[10];
    double_pointer = pointers;
    for(int i = 0; i < 3 ; i++){
        pointers[i] = a[i];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << *(*(double_pointer + i) + j) << " ";
        }
        std::cout << "\n";
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << *(*(pointers + j) + i) << " ";
        }
        std::cout << "\n";
    }
    
}
