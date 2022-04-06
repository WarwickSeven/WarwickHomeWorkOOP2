//Lesson B task 1

#include <iostream>

class Person {
protected:
    std::string name;
    int age;
    std::string sex;
    int weight;

public:
    Person (std::string name, int age, const std::string sex, float weight) {
        this->name = name;
        this->age = age;
        this->sex = sex;
        this->weight = weight;
    }
    void setName(std::string n) {
        name = n;
    }
    std::string getName() const {
        return name;
    }
    void setAge(int sA) {
        age = sA;
    }
    int getAge() const {
        return age;
    }
    void setWeight(int weight) {
        this->weight = weight;
    }
    int getWeight() const {
        return weight;
    }
};

class Student : public Person {
private:
    int yearsOfStudy;
    static int& Count() { static int c=0; return c; }
public:
    Student(std::string name, int age, std::string sex, float weight, int yearsOfStudy) : Person (name, age, sex, weight) {
    this->yearsOfStudy = yearsOfStudy;
        ++Count();
    }
    ~Student() {
        --Count();
    }
   
    void setStudy(int sW) {
        yearsOfStudy = sW;
    }
    int getStudy() const {
        return yearsOfStudy;
    }
    void info() {
         printf("%s is a %d years old and %d kg of flesh %s. Start study: %d.\n"
               , getName().c_str(), getAge(), getWeight(), sex.c_str(), getStudy());
    }
    static int getCount() {
        return Count();
    }
};

int main()
{
    Student s1 ("Vasya", 19, "male", 69, 2005);
    Student s2 ("Masha", 18, "female", 47, 2006);
    Student s3 ("Vova", 19, "male", 80, 2007);
    
    s3.setName("Petya");
    s3.setAge(35);
    s3.setWeight(120);
    s3.setStudy(1997);
    
    s1.info();
    s2.info();
    s3.info();
    
    std::cout << "overall students: " << Student::getCount() << std::endl;
    return 0;
}
