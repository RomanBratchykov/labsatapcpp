#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

char arrayOfLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
                           'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
                           'u', 'v', 'w', 'x', 'y', 'z'}; 

char arrayOfVowels[5] = {'a', 'e', 'i', 'o', 'u'};

char arrayOfCapitalLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                                  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
                                  'U', 'V', 'W', 'X', 'Y', 'Z'};

char arrayOfPunctuationMarks[6] = {' ', '.', ',', '!', '?', ';'};

void showArray(char* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }
    std::cout << " ";
}

void fillArrayRandom(char** arr, int size)
{
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (i == j) 
                arr[i][j] = arrayOfVowels[rand() % 5];
            else if (i + j == size - 1)
                arr[i][j] = arrayOfVowels[rand() % 5];
            else
                arr[i][j] = arrayOfLetters[rand() % 26];
        }
    }
    
}

bool isLength(char* array, int length)
{
    if (array == nullptr)
        return false;
    char *ptr = array;
    int counter = 0;
    while (*ptr != '\0'){
        for (int i = 0; i < 6; i++){
            if (*ptr == arrayOfPunctuationMarks[i])
                return false;   
        }
        counter++;
        ptr++;
    }
    return counter == length;
}

bool isCapital(char* array, char letter)
{
    if (array == nullptr)
        return false;
    char *ptr = array;
    while (*ptr != '\0'){
        if (*ptr >= 'A' && *ptr <= 'Z' && *ptr == letter)
            return true;
        ptr++;
    }
    return false;
}
int main() {
    srand(time(0));
    while(1) {
        int num;
        std::cout << "\nEnter number of task(1-2, 0 for exit): \n";
        std::cin >> num;
         switch(num)
           {
            case 0:
            return 0;
            case 1:
            {
                std::ifstream fileToRead("words.txt");
                if (fileToRead.fail()){
                    std::cout << "Error while opening file\n";
                    return 1;
                }
                char* char1 = new char[20];
                int threeCounter = 0;
                int lengthsCounter = 0;
                while (fileToRead >> char1){
                    if (!isCapital(arrayOfCapitalLetters, char1[0]))
                        lengthsCounter++;
                    if (isLength(char1, 3))
                        threeCounter++;
                }
                
                int i = 0;
                fileToRead.clear();
                fileToRead.seekg(0);
                
                int* lengths = new int[lengthsCounter];
                while (fileToRead >> char1){
                    if (!isCapital(arrayOfCapitalLetters, char1[0]))
                        for (int j = 0; j < 100; j++){
                            if (char1[j] == '\0'){
                                lengths[i] = j;
                                i++;
                                break;
                            }
                        }
                }

                char** arrayOfWords = new char*[lengthsCounter];
                for (int i = 0; i < lengthsCounter; i++){
                    arrayOfWords[i] = new char[lengths[i] + 1];
                }

                char** arrayOfWordsWith3 = new char*[threeCounter];
                for (int i = 0; i < threeCounter; i++){
                    arrayOfWordsWith3[i] = new char[4];
                }

                i = 0;
                fileToRead.clear();
                fileToRead.seekg(0);

                while (fileToRead >> char1){
                    if (!isCapital(arrayOfCapitalLetters, char1[0])){
                        for (int j = 0; j < lengths[i]; j++){
                            arrayOfWords[i][j] = char1[j];
                        }
                        i++;
                    }
                }
                std::cout << "Array of words that dont start with capital letter: \n";
                for (int i = 0; i < lengthsCounter; i++){
                    showArray(arrayOfWords[i], lengths[i]);
                }
                i = 0;
                fileToRead.clear();
                fileToRead.seekg(0);
                while (fileToRead >> char1){
                    if (isLength(char1, 3)){
                        for (int j = 0; j < 3; j++){
                            arrayOfWordsWith3[i][j] = char1[j];
                        }
                    i++;
                    }
                }
                fileToRead.clear();
                fileToRead.seekg(0);
                std::cout << "\nArray of words that have only 3 letters: \n";
                for (int i = 0; i < threeCounter; i++){
                    showArray(arrayOfWordsWith3[i], 3);
                }
                std::cout << "\nEnter word you want to find in file and to output how much times it appears: \n";
                std::string word;
                std::cin >> word;
                int wordLength = word.length();
                int counter = 0;
                while (fileToRead >> char1){ 
                    for (int i = 0; char1[i] != '\0'; i++)
                        if (char1[i] >= 65 && char1[i] <= 90)
                            char1[i] += 32;
                    std::string word1 = char1;
                    if (word1 == word)
                        counter++;
                }
                if (counter == 0)
                    std::cout << "Word " << word << " doesnt appear in file\n";
                else
                std::cout << "Word " << word << " appears " << counter << " times in file\n";
                for (int i = 0; i < lengthsCounter; i++)
                    delete[] arrayOfWords[i];
                delete[] arrayOfWords;
                for (int i = 0; i < threeCounter; i++)
                    delete[] arrayOfWordsWith3[i];
                delete[] arrayOfWordsWith3;
                delete[] char1;
                fileToRead.close();
                delete[] lengths;
            }
            break;
            case 2:
            {
                std::cout << "Enter size of array: \n";
                int size;
                std::cin >> size;
                char** matrixOfChars = new char*[size];
                for (int i = 0; i < size; i++){
                    matrixOfChars[i] = new char[size];
                }
                fillArrayRandom(matrixOfChars, size);
                std::cout << "Filled matrix: \n";
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        std::cout << std::setw(3) << matrixOfChars[i][j] << " ";
                    }
                    std::cout << "\n";
                }
                std::cout << "Enter word you want to find in matrix: \n";
                std::string word;
                std::cin >> word;
                int wordLength = word.length();
                int counterForRows = 0, counterForColumns = 0;
                std::cout << "Rows: \n";
                bool isFoundRows = false;
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        if (matrixOfChars[i][j] == word[0] && j + wordLength <= size){
                            int coorX = i, coorYStart = j, coorYEnd = j;
                            int counter = 0;
                            for (int k = 0; k < wordLength; k++){
                                if (matrixOfChars[coorX][coorYEnd] == word[k]){
                                    counter++;
                                    coorYEnd++;
                                }
                                else
                                    break;
                                
                                }

                                if (counter == wordLength){
                                    isFoundRows = true;
                                    std::cout << "Word " << word << "\n" << coorX + 1 << "," << coorYStart + 1 << " - " << coorX + 1 << "," << coorYEnd << "\n";                                }
                            }
                        }
                    }
                    if (!isFoundRows)
                        std::cout << "Word " << word << " doesnt appear in rows\n";
                    std::cout << "Columns: \n";
                    bool isFoundColumns = false;
                    for (int i = 0; i < size; i++){
                        for (int j = 0; j < size; j++){
                            if (matrixOfChars[i][j] == word[0]){
                                int coorXStart = i, coorY = j, coorXEnd = i;
                                int counter = 0;
                                for (int k = 0; k < wordLength; k++){
                                if (matrixOfChars[coorXEnd][coorY] == word[k] && i + wordLength <= size){
                                    counter++;
                                    coorXEnd++;
                                }
                                else
                                    break;
                                if (counter == wordLength){
                                    isFoundColumns = true;
                                    std::cout << "Word " << word << "\n" << coorXStart + 1 << "," << coorY + 1 << " - " << coorXEnd + 1 << "," << coorY + 1 << "\n";
                                }
                            }
                                
                        }
                    }
                }
                if (!isFoundColumns)
                        std::cout << "Word " << word << " doesnt appear in columns\n";
                for (int i = 0; i < size; i++){
                    delete[] matrixOfChars[i];
                }
                delete[] matrixOfChars;
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}
