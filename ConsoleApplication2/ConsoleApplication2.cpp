/*
Создать класс Flat (квартира). Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция "==").
2. Операцию присваивания одного объекта другому (операция "=").
3. Сравнение двух квартир по цене (операция ">").
*/

#include <iostream>
using namespace std;

class Flat {
private:
    double area; 
    double price; 

public:
    Flat() : area(0.0), price(0.0) {}

    Flat(double a, double p) : area(a), price(p) {}

    Flat& operator=(const Flat& right) {
        if (this != &right) {
            area = right.area;
            price = right.price;
        }
        return *this;
    }

    bool operator==(const Flat& right) const {
        return area == right.area;
    }

    bool operator>(const Flat& right) const {
        return price > right.price;
    }

    double getArea() const {
        return area; 
    }
    double getPrice() const 
    {
        return price;
    }
    
    ~Flat() {}
};

int main() {
    Flat flat1(50.5, 120000);
    Flat flat2(50.5, 130000);
    Flat flat3(45.0, 110000);

    flat3 = flat1;
    cout << "Flat3 area: " << flat3.getArea() << ", price: " << flat3.getPrice() << endl;

    cout << "Flat1 and Flat2 are " << (flat1 == flat2 ? "equal" : "not equal") << " by area." << endl;

    cout << "Flat2 is " << (flat2 > flat1 ? "more" : "less") << " expensive than Flat1." << endl;

    return 0;
}
