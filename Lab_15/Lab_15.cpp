#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cstdlib>
#include <vector>
std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
template <typename T>
void fillRand(T* &arr, int size){
    std::string check = typeid(T).name();
    // if (check == "c"){
    //     for (int i = 0; i < size; i++){
    //         arr[i] = alphabet[rand() % alphabet.size()];
    //     }
    // }
    std::cout << "Enter start and interval\n";
    int start, interval;
    std::cin >> start >> interval;
    for (int i = 0; i < size; i++){
        arr[i] = rand() % interval + start;
    }
    // else if (check == "f"){
    //     std::cout << "Enter start and interval\n";
    //     int start, interval;
    //     std::cin >> start >> interval;
    //     start = start * 100;
    //     interval = interval * 100;
    //     for (int i = 0; i < size; i++){
    //         arr[i] = float((rand() % (interval + start)) / 100.0);
    //     }
    // }
}

template <typename T>
void fillArray(T* &arr, int size){
    for (int i = 0; i < size; i++){
        std::cout << "Enter element " << i + 1 << ": \n";
        std::cin >> arr[i];
    }
}

template <typename T>
int compare(T* arr, int size){
    int count = 0;
    for (int i = 1; i < size; i++){
        if (arr[i] == arr[0]){
            count++;
        }
    }
    return count;
}

template <typename T>
void swapElements(T* arr, int size, int index1, int index2){
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size){
        std::cout << "invalid index\n";
        return;
    }
    if (index1 == index2){
        std::cout << "indexes are equal\n";
        return;
    }
    if (index1 > index2){
        std::swap(index1, index2);
    }
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return ;
}

template <typename T>
void printArray(const T* arr, int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
T* insertElement(T* arr, int& size, T element, int index){
    if (index < 0 || index > size){
        std::cout << "invalid index\n";
        return arr;
    }
    T* newArr = new T[size + 1];
    for (int i = 0; i < index; i++){
        newArr[i] = arr[i];
    }
    newArr[index] = element;
    for (int i = index + 1; i < size + 1; i++){
        newArr[i] = arr[i - 1];
    }
    delete[] arr;
    size++;
    return newArr;
}

template <typename T>
void longestPart(T* arr, int size){
    int count = 1, startIndex = 0, endIndex = 0, maxCount = 1, tempIndex = 0;
    for (int i = 1; i < size; ++i){
        if (arr[i] == arr[i - 1]){
            count++;
            if (count == 2){
                startIndex = i - 1;
            }
        }
        else{
            if (count > maxCount){
                maxCount = count;
                endIndex = i - 1;
            }
            count = 1;
        }
    }
    if (count > maxCount){
        maxCount = count;
        endIndex = size - 1;
    }
    std::cout << "Longest part is from " << startIndex + 1 << " to " << endIndex + 1 << "(" << maxCount <<" elements) \n";
    
    std::cout << "\n";
}

template <typename T>
void sortBetweenMaxMin(T* arr, int size){
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < size; i++){
        if (arr[i] > arr[maxIndex]){
            maxIndex = i;
        }
        if (arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    std::cout << "Max index: " << maxIndex + 1 << "\n";
    std::cout << "Min index: " << minIndex + 1 << "\n";

    if (maxIndex > minIndex){
        std::sort(arr + minIndex, arr + maxIndex + 1);
    }
    else{
        std::sort(arr + maxIndex, arr + minIndex + 1);
    }
}

template <typename T>
class Vector{
    T* vec;
    int size;
    public: 
    Vector(int size){
        this->size = size;
        vec = new T[size];
    }
    Vector(){
        this->size = 10;
        vec = new T[size];
    }
    ~Vector(){}
    T* getVector(){
        return vec;
    }
    int getSize(){
        return size;
    }
    void fill(){
        for (int i = 0; i < size; i++){
            std::cout << "Enter element " << i + 1 << ": \n";
            std::cin >> vec[i];
        }
    }
    
    void fillRand(){
        std::string check = typeid(T).name();
        if ( check == "c"){
            for (int i = 0; i < size; i++){
                vec[i] = alphabet[rand() % alphabet.size()];
            }
        }
        else if (check == "i"){
            
            std::cout << "Enter start and interval\n";
            int start, interval;
            std::cin >> start >> interval;
            for (int i = 0; i < size; i++){
                vec[i] = rand() % interval + start;
            }
        }
        else if (check == "f"){
        
            std::cout << "Enter start and interval\n";
            int start, interval;
            std::cin >> start >> interval;
            start = start * 100;
            interval = interval * 100;
            for (int i = 0; i < size; i++){
                vec[i] = float((rand() % (interval + start)) / 100.0);
            }
        }
    }

    void print(){
        for (int i = 0; i < size; i++){
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
    }

    void deleteElement(T value){
        int tempSize = size;
        for (int i = 0; i < size; i++){
            if (vec[i] == value){
                for (int j = i; j < size - 1; j++){
                    vec[j] = vec[j + 1];
                }
                tempSize--;
            }
        }
        T* newVec = new T[tempSize];
        for (int i = 0; i < tempSize; i++){
            newVec[i] = vec[i];
        }
        delete[] vec;
        size = tempSize;
        vec = newVec;
        
    }

    void moveElements(){
        int oddSize = 0, evenSize = 0;
        for (int i = 0; i < size; i++){
            if (i % 2 == 0){
                evenSize++;
            }
            else{
                oddSize++;
            }
        }
        T* temp1 = new T[evenSize];
        T* temp2 = new T[oddSize];
        int index1 = 0, index2 = 0;
        for (int i = 0; i < size; i++){
            if (i % 2 == 0){
                temp1[index1++] = vec[i];
            }
            else{
                temp2[index2++] = vec[i];
            }
        }

        for (int k = 0; k < index1; k++){
            vec[k] = temp1[k];
        }
        int index3 = 0;
        for (int r = index1; r < index2 + index1; r++){
            vec[r] = temp2[index3++];
        }
        delete[] temp1;
        delete[] temp2;
    }

    
    void operator++(){
        for (int i = 0; i < size; i++){
            vec[i]+=10;
        }
    }
    T operator[](int index){
        if (index < 0 || index >= size){
            std::cout << "invalid index\n";
            return 0;
        }
        return vec[index];
    }
    void operator+(Vector other){
        if (size != other.getSize()){
            std::cout << "invalid size\n";
            return;
        }
        for (int i = 0; i < size; i++){
            vec[i] += other[i];
        }
    }
    
    bool operator==(Vector& other){
        if (size != other.getSize()){
            return false;
        }
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; i++){
            sum1 += vec[i];
            sum2 += other[i];
        }
        return sum1 == sum2;
    }

    bool operator>(Vector& other){
        if (size != other.getSize()){
            return false;
        }
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; i++){
            sum1 += vec[i];
            sum2 += other[i];
        }
        return sum1 > sum2;
    }

    bool operator<(Vector& other){
        if (size != other.getSize()){
            return false;
        }
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; i++){
            sum1 += vec[i];
            sum2 += other[i];
        }
        return sum1 < sum2;
    }
};


int main(){
    srand(time(0));
    while (1) {
        std::cout << "Enter number of task (1-2, 0 for exit): \n";
        int task;
        std::cin >> task;
        if (task == 0){
            break;
        }
        switch (task){
            case 1:{
                std::cout << "Enter type of array (1 - int, 2 - char, 3 - float): \n";
                int type;
                std::cin >> type;
                if (type != 1 && type != 2 && type != 3){
                    std::cout << "invalid type\n";
                    break;
                }
                if (type == 1){
                    std::cout << "Enter size of int array:\n";
                    int size;
                    std::cin >> size;
                    int* arr = new int[size];
                    fillRand(arr, size);
                    std::cout << "Array:\n";
                    printArray(arr, size);
                    std::cout << "Enter index of element to swap:\n";
                    int index1, index2;
                    std::cin >> index1 >> index2;
                    swapElements(arr, size, index1, index2);
                    std::cout << "Array after swap:\n";
                    printArray(arr, size);
                    std::cout << "Enter index of element to insert:\n";
                    int index;
                    std::cin >> index;
                    std::cout << "Enter element to insert:\n";
                    int element;
                    std::cin >> element;
                    int* arr1 = insertElement(arr, size, element, index);
                    std::cout << "Array after insert:\n";
                    printArray(arr1, size);
                    std::cout << "Longest part:\n";
                    longestPart(arr1, size);
                    std::cout << "Number of elements equal to first:\n";
                    int count = compare(arr1, size);
                    std::cout << count << "\n";
                    std::cout << "Sorted between max and min:\n";
                    sortBetweenMaxMin(arr1, size);
                    printArray(arr1, size);
                    delete[] arr1;
                }
                else if (type == 2){
                    std::cout << "Enter size of char array:\n";
                    int charSize;
                    std::cin >> charSize;
                    char* arrChar = new char[charSize];
                    fillRand(arrChar, charSize);
                    std::cout << "Array:\n";
                    printArray(arrChar, charSize);
                    std::cout << "Enter index of element to swap:\n";
                    int index3, index4;
                    std::cin >> index3 >> index4;
                    swapElements(arrChar, charSize, index3, index4);
                    std::cout << "Array after swap:\n";
                    printArray(arrChar, charSize);
                    std::cout << "Enter index of element to insert:\n";
                    int indexChar;
                    std::cin >> indexChar;
                    std::cout << "Enter element to insert:\n";
                    char elementChar;
                    std::cin >> elementChar;
                    char* arrChar1 = insertElement(arrChar, charSize, elementChar, indexChar);
                    std::cout << "Array after insert:\n";
                    printArray(arrChar1, charSize);
                    std::cout << "Longest part:\n";
                    longestPart(arrChar1, charSize);
                    std::cout << "Number of elements equal to first:\n";
                    int countChar = compare(arrChar1, charSize);
                    std::cout << countChar << "\n";
                    std::cout << "Sorted between max and min:\n";
                    sortBetweenMaxMin(arrChar1, charSize);
                    printArray(arrChar1, charSize);

                    delete[] arrChar1;
                }
                else {
                    std::cout << "Enter size of float array:\n";
                    int floatSize;
                    std::cin >> floatSize;
                    float* arrFloat = new float[floatSize];
                    fillRand(arrFloat, floatSize);
                    std::cout << "Array:\n";
                    printArray(arrFloat, floatSize);
                    std::cout << "Enter index of element to swap:\n";
                    int index5, index6;
                    std::cin >> index5 >> index6;
                    swapElements(arrFloat, floatSize, index5, index6);
                    std::cout << "Array after swap:\n";
                    printArray(arrFloat, floatSize);
                    std::cout << "Enter index of element to insert:\n";
                    int indexFloat;
                    std::cin >> indexFloat;
                    std::cout << "Enter element to insert:\n";
                    float elementFloat;
                    std::cin >> elementFloat;
                    float* arrFloat1 = insertElement(arrFloat, floatSize, elementFloat, indexFloat);
                    std::cout << "Array after insert:\n";
                    printArray(arrFloat1, floatSize);
                    std::cout << "Longest part:\n";
                    longestPart(arrFloat1, floatSize);
                    std::cout << "Number of elements equal to first:\n";
                    int countFloat = compare(arrFloat1, floatSize);
                    std::cout << countFloat << "\n";
                    std::cout << "Sorted between max and min:\n";
                    sortBetweenMaxMin(arrFloat1, floatSize);
                    printArray(arrFloat1, floatSize);
                }
            }
            break;
            case 2:
            {
                std::cout << "Enter type of array (1 - int, 2 - char, 3 - float): \n";
                int type;
                std::cin >> type;
                if (type != 1 && type != 2 && type != 3){
                    std::cout << "invalid type\n";
                    break;
                }
                if (type == 1){
                    std::cout << "Enter size of int vector:\n";
                    int size;
                    std::cin >> size;
                    Vector<int> vec(size);
                    vec.fillRand();
                    vec.print();
                    std::cout << "Enter element to delete:\n";
                    int element;
                    std::cin >> element;
                    vec.deleteElement(element);
                    vec.print();
                    std::cout << "Moved elements:\n";
                    vec.moveElements();
                    vec.print();
                    std::cout << "Enter size of vector to add:\n";
                    int size2;
                    std::cin >> size2;
                    Vector<int> vec2(size2);
                    vec2.fillRand();
                    vec2.print();
                    if (vec == vec2){
                        std::cout << "Vectors are equal\n";
                    }
                    else{
                        std::cout << "Vectors are not equal\n";
                    }
                    if (vec > vec2){
                        std::cout << "First vector is bigger\n";
                    }
                    else if (vec < vec2){
                        std::cout << "Second vector is bigger\n";
                    }
                    std::cout << "Incremented elements:\n";
                    ++vec;
                    vec.print();
                    vec + vec2;
                    std::cout << "Added vector:\n";
                    vec.print();
                }
                else if (type == 2){
                    std::cout << "Enter size of char vector:\n";
                    int size;
                    std::cin >> size;
                    Vector<char> vec(size);
                    vec.fillRand();
                    vec.print();
                    std::cout << "Enter element to delete:\n";
                    char element;
                    std::cin >> element;
                    vec.deleteElement(element);
                    vec.print();
                    std::cout << "Moved elements:\n";
                    vec.moveElements();
                    vec.print();
                    std::cout << "Enter size of vector to add:\n";
                    int size2;
                    std::cin >> size2;
                    Vector<char> vec2(size2);
                    vec2.fillRand();
                    vec2.print();
                    if (vec == vec2){
                        std::cout << "Vectors are equal\n";
                    }
                    else{
                        std::cout << "Vectors are not equal\n";
                    }
                    if (vec > vec2){
                        std::cout << "First vector is bigger\n";
                    }
                    else if (vec < vec2){
                        std::cout << "Second vector is bigger\n";
                    }
                    std::cout << "Incremented elements:\n";
                    ++vec;
                    vec.print();
                    vec + vec2;
                    std::cout << "Added vector:\n";
                    vec.print();
                    
                    
                }
                else {
                    std::cout << "Enter size of float vector:\n";
                    int size;
                    std::cin >> size;
                    Vector<float> vec(size);
                    vec.fillRand();
                    vec.print();
                    std::cout << "Enter element to delete:\n";
                    float element;
                    std::cin >> element;
                    vec.deleteElement(element);
                    vec.print();
                    std::cout << "Moved elements:\n";
                    vec.moveElements();
                    vec.print();
                    std::cout << "Incremented elements:\n";
                    ++vec;
                    vec.print();
                    std::cout << "Enter size of vector to add:\n";
                    int size2;
                    std::cin >> size2;
                    std::cout << "Enter size of vector to add:\n";
                    int size3;
                    std::cin >> size3;
                    Vector<float> vec2(size3);
                    vec2.fillRand();
                    vec2.print();
                    if (vec == vec2){
                        std::cout << "Vectors are equal\n";
                    }
                    else{
                        std::cout << "Vectors are not equal\n";
                    }
                    if (vec > vec2){
                        std::cout << "First vector is bigger\n";
                    }
                    else if (vec < vec2){
                        std::cout << "Second vector is bigger\n";
                    }
                    vec + vec2;
                    std::cout << "Added vector:\n";
                    vec.print();
                    std::cout << "Incremented elements:\n";
                    ++vec;
                    vec.print();
                    
                }
            }
            break;
            default:
                std::cout << "invalid choice\n";
            break;
        }
    }
}