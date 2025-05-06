#include <locale>
#include <iostream>
#include <clocale>
#include <list>
int main() {
    srand(time(0));
    std::list<int> vec;
    int n, l;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        vec.push_back(rand() % 1000);
    }
    vec.sort();
    std::cin >> l;
    int start = 0, end = n, ind_x;
    bool isFound = false;
    while (!isFound){
        ind_x = (end - start + 1) / 2;
        if ()
    }
    return 0;
}