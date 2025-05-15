#include <locale>
#include <iostream>
#include <clocale>
#include <list>
#include <cctype>
#include <fstream>
#include <sstream>
std::string caesar(std::string str, int key){
    for (int i = 0; i < str.length(); i++){
            str[i] += key;
    }
    return str;
}
std::string decrypt(std::string str, int key){
    for (int i = 0; i < str.length(); i++){
        str[i] -= key;
    }
    return str;
}

std::string keyEncrypt(std::string str, char* key){
    std::string result = str;
    int keyLength = sizeof(key);
    int index = 0;
    for (int i = 0; i < str.length(); i++){
        if (index >= keyLength){
            index = 0;
        }
        result[i] = str[i] + key[index];
        index++;
    }
    return result;
}

std::string keyDecrypt(std::string str, char* key){
    std::string result = str;
    int index = 0;
    int keyLength = sizeof(key);
    for (int i = 0; i < str.length(); i++){
        if (index >= keyLength){
            index = 0;
        }
        result[i] = str[i] - key[index];
        index++;
    }
    return result;
}
int main() {
    std::string str;
    std::ifstream file("encrypted.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line)) {
        str += line + "\n";
    }
    file.close();
    char key[] = "enjoeknavvshjjjdjdjjd";
    std::cout << "Original string: " << str << std::endl;
    std::string decrypted = keyDecrypt(str, key);
    std::ofstream outFile("decrypted.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }
    outFile <<  decrypted;
    outFile.close();
    
        
    return 0;
}