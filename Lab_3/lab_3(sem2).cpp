#include <iostream>
#include <cmath>

int findMin(int* ptr, int size){
    int min = *ptr;
    for (int i = 0; i < size; i++){
        if (*(ptr + i) < min){
            min = *(ptr + i);
        }
    }
    return min;
}

void fillMatrix(int **matrix, int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            *(*(matrix + i) + j) = rand() % 100 - 50;
        }
    }
}

void bubbleSort(int* ptr, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (*(ptr + j) > *(ptr + j + 1)){
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
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
                    int rows = 0;
                    std::cout << "Enter number of rows and columns: ";
                    std::cin >> rows;
                    int** matrix = new int*[rows];
                    for (int i = 0; i < rows; i++)
                    {
                        *(matrix + i) = new int[rows];
                    }
                    fillMatrix(matrix, rows, rows);
                    std::cout << "Filled matrix: \n";
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < rows; j++)
                        {
                            std::cout << *(*(matrix + i) + j) << " ";
                        }
                        std::cout << "\n";
                    }
                    int maxMain = 0;
                    int minSecondary = 0;
                    maxMain = *(*(matrix + 0) + 0);
                    minSecondary = *(*(matrix + 0) + rows - 1);
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < rows; j++)
                        {
                            if (i == j && *(*(matrix + i) + j) > maxMain)
                            {
                                maxMain = *(*(matrix + i) + j);
                            }

                            if (i + j == rows - 1 && *(*(matrix + i) + j) < minSecondary)
                            {
                                minSecondary = *(*(matrix + i) + j);
                            }
                        }
                    }
                    std::cout << "Max element of main diagonal is: " << maxMain << "\n";
                    std::cout << "Min element of secondary diagonal is: " << minSecondary << "\n";
                    std::cout << "Difference between max elements is: " << maxMain - minSecondary << "\n";
                    delete[] matrix;
                }
            break;
            case 2:
            {
                int rows = 0,
                columns = 0;
                std::cout << "Enter number of rows and columns: ";
                std::cin >> rows;
                int** matrix = new int*[rows];
                for (int i = 0; i < rows; i++)
                {
                    *(matrix + i) = new int[rows];
                }
                fillMatrix(matrix, rows, rows);
                std::cout << "Filled matrix: \n";
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < rows; j++)
                    {
                        std::cout << *(*(matrix + i) + j) << " ";
                    }
                    std::cout << "\n";
                }
                std::cout << "Final matrix: \n";
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < rows; j++)
                    {
                        if (i % 2 == 0)
                        std::cout << *(*(matrix + i) + j) << " ";
                        else
                        std::cout << *(*(matrix + i) + rows - j - 1) << " ";
                    }
                    std::cout << "\n";
                }
                delete[] matrix;
            }
            break;
            case 3:
            {
                int rows = 0,
                columns = 0;
                std::cout << "Enter number of rows and columns: ";
                std::cin >> rows;
                int** matrix = new int*[rows];
                for (int i = 0; i < rows; i++)
                {
                    *(matrix + i) = new int[rows];
                }
                fillMatrix(matrix, rows, rows);
                std::cout << "Filled matrix: \n";
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < rows; j++)
                    {
                        std::cout << *(*(matrix + i) + j) << " ";
                    }
                    std::cout << "\n";
                }
                int index = 0;
                int min = *(*(matrix + 0) + 0);
                int *arr = new int[rows];
                int *ptr = arr;
                for (int i = 0; i < rows; i++)
                { 
                    for (int j = 0; j < rows; j++)
                    {
                        int* matrix_ptr = *(matrix + i);
                        if (*(*(matrix + i) + j) == findMin(matrix_ptr, rows))
                            *(ptr + index++) = j;
                    }
                }
                std::cout << "Array with indexes of min elements: \n";
                for (int i = 0; i < index; i++){
                    std::cout << *(ptr + i) << " ";
                }
                std::cout << "\n";
                delete[] matrix;
            }
            break;
            case 4:
            {
                int rows = 0,
                columns = 0;
                std::cout << "Enter number of rows and columns: ";
                std::cin >> rows;
                int** matrix = new int*[rows];
                for (int i = 0; i < rows; i++)
                {
                    *(matrix + i) = new int[rows];
                }
                fillMatrix(matrix, rows, rows);
                double avgPositive = 0;
                double avgNegative = 0;
                int counterZeroes = 0;
                std::cout << "Filled matrix: \n";
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < rows; j++)
                    {
                        if (*(*(matrix + i) + j) > 0){
                            avgPositive += *(*(matrix + i) + j);
                        }

                        if (*(*(matrix + i) + j) < 0){
                            avgNegative += *(*(matrix + i) + j);
                        }

                        if (*(*(matrix + i) + j) == 0){
                            counterZeroes++;
                        }
                        std::cout << *(*(matrix + i) + j) << " ";
                    }
                    std::cout << "\n";
                }
                avgPositive /= rows * rows;
                avgNegative /= rows * rows;
                std::cout << "Number of zeroes = " << counterZeroes << "\n";
                std::cout << "Average positive = " << avgPositive << "\n";
                std::cout << "Average negative = " << avgNegative << "\n";
                delete[] matrix;
            }
            break;
            case 5:
            {
                int rows = 0,
                columns = 0;
                std::cout << "Enter number of rows and columns: ";
                std::cin >> rows;
                int** matrix = new int*[rows];
                for (int i = 0; i < rows; i++)
                {
                    *(matrix + i) = new int[rows];
                }
                fillMatrix(matrix, rows, rows);
                std::cout << "Filled matrix: \n";
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < rows; j++)
                    {
                        std::cout << *(*(matrix + i) + j) << " ";
                    }
                    std::cout << "\n";
                }

                for (int j = 0; j < rows; j++)
                    for (int i = 0; i < rows - 1; i++)
                    {
                        if (i < rows - 1 && *(*(matrix + i) + i) > *(*(matrix + i + 1) + i + 1))
                        {
                            int temp = *(*(matrix + i) + i);
                            *(*(matrix + i) + i) = *(*(matrix + i + 1) + i + 1);
                            *(*(matrix + i + 1) + i + 1) = temp;
                        } 
                    }
                std::cout << "Final matrix: \n";
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < rows; j++)
                    {
                        std::cout << *(*(matrix + i) + j) << " ";
                    }
                    std::cout << "\n";
                }
                delete[] matrix;
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}