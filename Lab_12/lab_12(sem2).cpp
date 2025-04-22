#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <list>
#include <filesystem>

std::wstring checkLetters = L"ауеоиіяюїєАІУЕОИЯЮЇЄ";
std::wstring punctuationString = L";:!?,.'\"()[]{}<>-_";
std::wstring endPunctuation = L".?!;";
std::wstring alphabetUkr = L"абвгґдеєжзийіїйклмнопрстуфхцчшщьюяАБВГҐДЕЄЖЗИІЙЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
bool haveMoreThan2Vowels(std::wstring word){
    int count = 0;
    for (wchar_t c : word){
        if (checkLetters.find(c) != std::wstring::npos){
            count++;
        }
    }
    return count > 2;
}
bool havePunctuation(std::wstring word){
    for (wchar_t c : word){
        if (endPunctuation.find(c) != std::wstring::npos){
            return true;
        }
    }
    return false;
}
struct Word{
    int length;
    std::wstring word;
    bool operator>(Word& other){
        return length > other.length;
    }
    bool operator<(Word& other){
        return length < other.length;
    }
};
void cleanWord(std::wstring& word, wchar_t& punctuation){
    if (word.size() == 0) return;
    punctuation = word[word.size() - 1];
    if (punctuationString.find(punctuation) != std::wstring::npos){
        word.erase(word.size() - 1, 1);
    }
}
int getCharIndex(wchar_t char1){
    int index = alphabetUkr.find(char1);
    if (index == std::wstring::npos)
        return -1;
    if (index >= 35){
        index -= 35;
    }

    return index;
}

bool isEarlier(const std::wstring& s1, const std::wstring& s2) {
    int idx1 = getCharIndex(s1[0]);
    int idx2 = getCharIndex(s2[0]);
    return idx1 < idx2;
}



void sortAlphabetical(std::vector<std::wstring>& wordsVector){
    for (size_t i = 0; i < wordsVector.size(); i++){
        for (size_t j = 0; j < wordsVector.size() - 1 - i; j++){
            if (!isEarlier(wordsVector[j], wordsVector[j + 1])){
                std::swap(wordsVector[j], wordsVector[j + 1]);
            }
        }
    }
}
std::string converterToStr(std::wstring str){
    std::string result;
    for (int i = 0; i < str.size(); i++){
        result += (char)str[i];
    }
    return result;
}

int main(){
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U8TEXT);
    std::wcout << L"Enter directory in which you want to save files:\n";
    std::wstring directory;
    std::getline(std::wcin, directory);
    std::wstring path = directory + L"\\z2.txt";
    std::string newPath = converterToStr(path);
    if (!std::filesystem::exists(path)){
        std::wcerr << L"Path does not exist. Enter existing path.\n";
    }
    std::wcout << L"Directory: " << directory << "\n";
    std::wcout << L"Path: " << path << "\n";
    while(1){
        std::wcout << L"Enter task number (1-5) or 0 to exit: ";
        int num;
        std::cin >> num;
        if (num == 0) break;
        switch (num){
            case 1:{
                std::wifstream fileToRead("C:z1.txt");
                if (!fileToRead.is_open()){
                     std::wcerr << L"Error opening file" << "\n";
                     return 1;
                }
                fileToRead.imbue(std::locale(fileToRead.getloc(), new std::codecvt_utf8<wchar_t>));
                std::wstring line;
                std::wstring finalLine;
                while (std::getline(fileToRead, line)){
                    std::wstringstream ss(line);
                    std::wstring word;
                    while (ss >> word){
                        wchar_t punctuation = 0;
                        if (!haveMoreThan2Vowels(word)){   
                        }
                        else
                            cleanWord(word, punctuation);
                        finalLine += word + L" ";
                        if (haveMoreThan2Vowels(word) ){
                            if (punctuationString.find(punctuation) != std::wstring::npos){
                                finalLine += word + L"" + punctuation +  L" ";
                            }
                            else
                                finalLine += word + L" ";
                        }
                    }
                    finalLine += L"\n";
                }
                fileToRead.close();
            
                std::wofstream fileToWrite(newPath, std::ios::app);
                if (!fileToWrite.is_open()){
                     std::wcerr << L"Error opening file" << "\n";
                     return 1;
                }
                    fileToWrite.imbue(std::locale(fileToWrite.getloc(), new std::codecvt_utf8<wchar_t>));
                fileToWrite << L"\uFEFF";
                fileToWrite << finalLine;
                fileToWrite.close();
            }
            break;
            case 2:{
                std::list<Word> wordsList;
                std::wifstream fileToRead("C:z1.txt");
                    if (!fileToRead.is_open()){
                         std::cerr << L"Error opening file" << "\n";
                         return 1;
                    }
                fileToRead.imbue(std::locale(fileToRead.getloc(), new std::codecvt_utf8<wchar_t>));
                std::wstring line;
                std::wstring finalLine;
                    while (std::getline(fileToRead, line)){
                        std::wstringstream ss(line);
                        std::wstring word;
                        while (ss >> word){
                            wchar_t punctuation = 0;
                            cleanWord(word, punctuation);
                            Word element;
                            element.length = word.length();
                            element.word = word;    
                            wordsList.push_back(element);
                    }
                }
                wordsList.sort();
                std::wstring maxLengthWord = wordsList.back().word;
                wordsList.pop_back();
                int maxWordCounter = 1;
                if (wordsList.back().word == maxLengthWord){
                    while (wordsList.back().word == maxLengthWord){
                        maxWordCounter++;
                        wordsList.pop_back();
                    }
                }
                std::wstring secondMaxLengthWord = wordsList.back().word;
                wordsList.pop_back();
                int secondMaxWordCounter = 1;
                if (wordsList.back().word == secondMaxLengthWord){
                    while (wordsList.back().word == secondMaxLengthWord){
                        secondMaxWordCounter++;
                        wordsList.pop_back();
                    }
                }
                std::wstring thirdMaxLengthWord = wordsList.back().word;
                wordsList.pop_back();
                int thirdMaxWordCounter = 1;
                if (wordsList.back().word == thirdMaxLengthWord){
                    while (wordsList.back().word == thirdMaxLengthWord){
                        thirdMaxWordCounter++;
                        wordsList.pop_back();
                    }
                }
                std::wofstream fileTowrite(newPath, std::ios::app);
                if (!fileTowrite.is_open()){
                     std::wcerr << L"Error opening file" << "\n";
                     return 1;
                }
                fileTowrite.imbue(std::locale(fileTowrite.getloc(), new std::codecvt_utf8<wchar_t>));
                fileTowrite << L"\n" << L"Найдовше слово: " << maxLengthWord << L" " << maxWordCounter << L" разів\n";
                fileTowrite << L"Друге найдовше слово: " << secondMaxLengthWord << L" " << secondMaxWordCounter << L" разів\n";
                fileTowrite << L"Третє найдовше слово: " << thirdMaxLengthWord << L" " << thirdMaxWordCounter << L" разів\n";
                fileTowrite << L"----------------------------------\n";
                fileToRead.close();
            }
            break;
            case 3:
            {
                std::vector<std::wstring> sentenceVector;
                std::vector<std::wstring> sentenceVector2;
                std::wstring lineClean, lineRaw;
                std::wifstream fileToRead("C:z1.txt");
                std::wifstream fileToRead2("C:z1.txt");
                    if (!fileToRead.is_open()){
                         std::wcerr << L"Error opening file" << "\n";
                         return 1;
                    }
                fileToRead.imbue(std::locale(fileToRead.getloc(), new std::codecvt_utf8<wchar_t>));
                std::wstring line;
                int counter = 0;
                    while (std::getline(fileToRead, line)){
                        lineClean += line;
                    }
                    line.clear();
                    while (std::getline(fileToRead2, line)){
                        lineRaw += line;
                    }
                    std::wstring sentence;
                    std::wstringstream ss (lineClean);
                    std::wstring word;
                    while (ss >> word){
                        sentence += word + L" ";
                        if (havePunctuation(word)){
                            sentenceVector.push_back(sentence);
                            sentence.clear();
                        }
                    }
                    std::wstringstream ss2 (lineRaw);
                    std::wstring wordRaw;
                    while (ss2 >> wordRaw){
                        sentence += wordRaw + L" ";
                        if (havePunctuation(wordRaw)){
                            sentenceVector2.push_back(sentence);
                            sentence.clear();
                        }
                    }
                std::wcout << L"Enter word to search: \n";
                std::wstring wordToSearch;
                std::wcin.ignore();
                std::getline(std::wcin, wordToSearch);
                std::wcout << L"Lines containing the word: \n";
                std::wcout << L"----------------------------------\n";
                std::vector<int> indexes;
                int count = 0;
                int index = 0;
                for (auto line : sentenceVector2){
                    std::wstringstream ss(line);
                    std::wstring word;
                    while (ss >> word){
                        wchar_t punctuation = 0;
                        cleanWord(word, punctuation);
                        if (word == wordToSearch){
                            indexes.push_back(index);
                            count++;
                            break;
                        }
                    }
                    index++;
                }
                std::wofstream fileTowrite3(newPath, std::ios::app);
                if (!fileTowrite3.is_open()){
                     std::wcerr << L"Error opening file" << "\n";
                     return 1;
                }
                fileTowrite3.imbue(std::locale(fileTowrite3.getloc(), new std::codecvt_utf8<wchar_t>));
                fileTowrite3 << L"\n" << L"Рядки які містять слово: \n";
                for (int i = 0; i < indexes.size(); i++){
                    std::wcout << sentenceVector[indexes[i]] << "\n";
                    fileTowrite3 << sentenceVector[indexes[i]] << "\n";
                }
                if (count == 0){
                    std::wcout << L"Word not found in any line.\n";
                }
            }
            break;
            case 4:
            {
                std::wstring wordToFind = L"хто";
                std::wifstream fileToRead("z1.txt");
                    if (!fileToRead.is_open()){
                         std::wcerr << L"Error opening file" << "\n";
                         return 1;
                    }

                fileToRead.imbue(std::locale(fileToRead.getloc(), new std::codecvt_utf8<wchar_t>));

                std::wstring line;
                std::wstring finalLine;
                while (std::getline(fileToRead, line)){
                    finalLine += line;
                }

                std::wstringstream ss(finalLine);
                std::wstring word;
                int counter = 0;
                while (ss >> word){
                    wchar_t char1 = 0;
                    cleanWord(word, char1);
                    if (wordToFind == word){
                        counter++;
                    }
                }

                if (counter <= 1){
                    std::wcout << "Word is not exist or only one time\n";
                    break;
                }
                std::wstringstream ss2(finalLine);
                std::wstring word2;
                bool isBetween = false;
                std::wstring result;
                while (ss2 >> word2){
                    if (!isBetween){
                        result += word2 + L" ";
                    }
                    if (word2 == wordToFind){
                        isBetween = true;
                        counter--;
                    }
                    if (counter == 0){
                        isBetween = false;
                    }
                }
                std::wcout << result << "\n";
                std::wofstream fileToWrite("z3.txt", std::ios::app);
                if (!fileToWrite.is_open()){
                     std::wcerr << L"Error opening file" << "\n";
                     return 1;
                }
                fileToWrite.imbue(std::locale(fileToWrite.getloc(), new std::codecvt_utf8<wchar_t>));
                fileToWrite << L"\n Слово: " << wordToFind << L" ";
                fileToWrite << result << L"\n";
            }
            break;
            case 5:
            {
                std::wifstream fileToRead1("z1.txt");
                if (!fileToRead1.is_open()){
                    std::wcerr << L"Error opening file" << "\n";
                    return 1;
               }
                fileToRead1.imbue(std::locale(fileToRead1.getloc(), new std::codecvt_utf8<wchar_t>));
                std::wifstream fileToRead2("C:t.txt");
                if (!fileToRead2.is_open()){
                    std::wcerr << L"Error opening file" << "\n";
                    return 1;
                }
                fileToRead2.imbue(std::locale(fileToRead2.getloc(), new std::codecvt_utf8<wchar_t>));
                int count = 0;
                std::wstring line;
                std::wstring s1, s2, s3;
                while (std::getline(fileToRead1, line)){
                    std::wstringstream ss1(line);
                    std::wstring word;
                    while (ss1 >> word){
                        wchar_t punctuation = 0;
                        cleanWord(word, punctuation);
                        s2 += word + L" ";
                        count++;
                    }
                }
                line.clear();
                while (std::getline(fileToRead2, line)){
                    if (count == 0){
                        break;
                    }
                    s1 += line + L" ";
                    count--;
                }
                s3 = s1 + s2;
                std::wcout << s3 << "str3\n";
                std::wstringstream ss2(s3);
                std::wstring word;
                std::vector<std::wstring> wordsVector;
                while (ss2 >> word){
                    wordsVector.push_back(word);
                }
                sortAlphabetical(wordsVector);
                s3.clear();
                for (auto word : wordsVector){
                    s3 += word + L" ";
                }
                std::wcout << "Result:\n";
                std::wcout << s3 << "\n";
                std::wofstream fileToWrite("z4.txt", std::ios::app);
                fileToWrite.imbue(std::locale(fileToWrite.getloc(), new std::codecvt_utf8<wchar_t>));
                fileToWrite << s3;
            }
            break;
            default:
                std::cout << "Invalid task number. Please enter a number between 1 and 6.\n";
            break;
        }
    }
    return 0;
}