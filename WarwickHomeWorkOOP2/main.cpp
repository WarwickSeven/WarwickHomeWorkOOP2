//Lesson B Task 2
#include <iostream>

class Fruit {
protected:
    std::string name;
    std::string color;
public:
    Fruit(std::string name, std::string color) {
        this->name = name;
        this->color = color;
    }
    std::string getName() const {
        return name;
    }
    std::string getColor() const {
        return color;
    }
};

class Apple : public Fruit {
public:
    Apple(std::string color = "Default", std::string name = "Apple") : Fruit(name, color) {
    }
};

class Banana : public Fruit {
public:
    Banana(std::string name = "Banana", std::string color = "Yellow") : Fruit(name, color) {
    }
};

class GrannySmith : public Apple {
public:
    GrannySmith(std::string name = "GrannySmith", std::string color = "Green") : Apple(color, name) {
    }
};

int main()
{
    Apple a("Red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

return 0;
}
