#include <locale>
#include <iostream>
#include <clocale>

int main() {
    std::setlocale(LC_ALL, "ukrainian");
    std::wcout.imbue(std::locale());
    std::wcout << L"System locale active.\n";

    try {
        std::locale ukLocale("uk-UA.UTF-8");
        std::wcout << L"Locale uk-UA loaded successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "uk-UA failed: " << e.what() << std::endl;
    }

    try {
        std::locale legacy("Ukrainian_Ukraine.1251");
        std::wcout << L"Legacy locale loaded.\n";
    } catch (const std::exception& e) {
        std::cerr << "Legacy failed: " << e.what() << std::endl;
    }

    return 0;
}