#include <iostream>
#include <cmath>



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
        std::cout << "Enter number of task(1-4, 0 for exit): \n";
        std::cin >> num;
         switch(num)
           {
            case 0:
                return 0;
            case 1:
                {
                    int rows = 0,
                    columns = 0;
                    std::cout << "Enter number of rows: ";
                    std::cin >> rows;
                    std::cout << "Enter number of columns: ";
                    std::cin >> columns;
                    int** matrix = new int*[rows];
                    for (int i = 0; i < rows; i++)
                    {
                        *(matrix + i) = new int[columns];
                    }
                    fillMatrix(matrix, rows, columns);
                    std::cout << "Filled matrix: \n";
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            std::cout << *(*(matrix + i) + j) << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "Reversed matrix: \n";
                    for (int i = 0; i < columns; i++)
                    {
                        for (int j = 0; j < rows; j++)
                        {
                            std::cout << *(*(matrix + j) + i) << " ";
                        }
                        std::cout << "\n";
                    }
                }
            break;
            case 2:
            {
                int rows = 0,
                    columns = 0;
                    std::cout << "Enter number of rows: ";
                    std::cin >> rows;
                    std::cout << "Enter number of columns: ";
                    std::cin >> columns;
                    int** matrix = new int*[rows];
                    for (int i = 0; i < rows; i++)
                    {
                        *(matrix + i) = new int[columns];
                    }
                    fillMatrix(matrix, rows, columns);
                    std::cout << "Filled matrix: \n";
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            std::cout << *(*(matrix + i) + j) << " ";
                        }
                        std::cout << "\n";
                    }
                    for (int i = 0; i < rows; i++)
                    {
                        bubbleSort(*(matrix + i), columns);
                    }
                    std::cout << "Sorted matrix: \n";
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            std::cout << *(*(matrix + i) + j) << " ";
                        }
                        std::cout << "\n";
                    }
            }
            break;
            case 3:
            {
                int rows = 0,
                    columns = 0;
                    std::cout << "Enter number of rows: ";
                    std::cin >> rows;
                    std::cout << "Enter number of columns: ";
                    std::cin >> columns;
                    int** matrix = new int*[rows];
                    for (int i = 0; i < rows; i++)
                    {
                        *(matrix + i) = new int[columns];
                    }
                    fillMatrix(matrix, rows, columns);
                    std::cout << "Filled matrix: \n";
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            std::cout << *(*(matrix + i) + j) << " ";
                        }
                        std::cout << "\n";
                    }
                    int counter = 0;
                    int* arr = new int[rows];
                    int* ptr = arr;
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                            if ( *(*(matrix + i) + j) % 2 != 0)
                            {
                                counter++;
                            }

                        *(ptr + i) = counter;
                        counter = 0;
                    }
                    for (int i = 0; i < rows; i++){
                        std::cout << *(ptr + i) << " ";
                    }
                    std::cout << "\n";
            }
            break;
            case 4:
            {
                int rows = 0,
                    columns = 0;
                    std::cout << "Enter number of rows: ";
                    std::cin >> rows;
                    std::cout << "Enter number of columns: ";
                    std::cin >> columns;
                    int** matrix = new int*[rows];
                    for (int i = 0; i < rows; i++)
                    {
                        *(matrix + i) = new int[columns];
                    }
                    fillMatrix(matrix, rows, columns);
                    std::cout << "Filled matrix: \n";
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            std::cout << *(*(matrix + i) + j) << " ";
                        }
                        std::cout << "\n";
                    }
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                            if ( *(*(matrix + i) + j) < 0)
                            {
                                *(*(matrix + i) + j) = sqrt(*(*(matrix + i) + j) * *(*(matrix + i) + j));
                            }
                    }
                    std::cout << "matrix with absolute values: \n";
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            std::cout << *(*(matrix + i) + j) << " ";
                        }
                        std::cout << "\n";
                    }
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}