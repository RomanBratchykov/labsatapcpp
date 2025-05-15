#include <iostream>
#include <functional>

class Base {
    std::string header;
    std::string mainPart;
    public:
    Base(std::string header, std::string mainPart) : header(header), mainPart(mainPart) {}
    virtual void print() {
        std::cout << header << "\n" << mainPart << "\n";
    }
};

class Newspaper : public Base{
    int levelOfImportance;
    public:
    Newspaper(std::string header, std::string mainPart, int levelOfImportance) : Base(header, mainPart), levelOfImportance(levelOfImportance) {}
    void print() override {
        Base::print();
        std::cout << "Level of importance: " << levelOfImportance << "\n";
    }
    void highImportance(std::function<void()> func) {
        if (levelOfImportance > 5) {
            func();
        }
    }
};
class Goods{
    protected:
    std::string name;
    int price;
    public:
    Goods(std::string name, int price) : name(name), price(price) {}
    virtual int getPrice() {
        return price;
    }
};
class DiscountGoods : public Goods{
    int discount;
    public:
    DiscountGoods(std::string name, int price) : Goods(name, price) {}
    int getPrice() override {
        return price - discount;
    }
    int getRawPrice() {
        return price;
    }
    void getDiscount(std::function<int(int, int)> func, int percentage = 10) {
        discount = func(price, percentage);
    }
};

int main() {
    Newspaper newspaper1("Header", "Main part", 6);
    newspaper1.print();
    newspaper1.highImportance([]() {
        std::cout << "This is a high importance news, need confirmation!\n";
    });
    Newspaper newspaper2("Header2", "Main part2", 3);
    newspaper2.print();
    newspaper2.highImportance([]() {
        std::cout << "This is a high importance news!\n";
    });
    DiscountGoods goods("Goods", 100);
    goods.getDiscount([](int price, int percentage) {
        return price * percentage / 100;
    }); // в цьому випадку знижка 10% бо за замовчуванням
    std::cout << "Discounted price: " << goods.getPrice() << "\n";
    std::cout << "Raw price: " << goods.getRawPrice() << "\n";
    DiscountGoods goods2("Goods2", 200);
    int percentage;
    std::cout << "Enter discount percentage: ";
    std::cin >> percentage;
    goods2.getDiscount([](int price, int percentage) {
        return price * percentage / 100;
    }, percentage); // тут передається параметр знижки який вводить користувач
    
    std::cout << "Discounted price: " << goods2.getPrice() << "\n"; //зі знижкою
    std::cout << "Raw price: " << goods2.getRawPrice() << "\n"; //  без знижки
    return 0;
}