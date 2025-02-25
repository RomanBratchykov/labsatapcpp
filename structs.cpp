#include <iostream>
#include <stdio.h>

struct Item {
    std::string name;
    std::string type;
    std::string color;
    float price;
};
int main() {
    Item items[10];
    int n;
    std::cout<< "enter number of items(below 10)\n";
    std::cin >> n;
    for (int i = 0; i < n; i++){
        std::cout << "enter name, type, color, price\n";
        std::cin >> items[i].name >> items[i].type >> items[i].color >> items[i].price;
    }
    for (int i = 0; i < n; i++){
        std::cout << items[i].name <<" "<< items[i].type <<" "<< items[i].color <<" "<< items[i].price<<"\n";
    }
    return 0;
}