#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Cat {
protected:
    string name;
    int age;
    string color;
public:
    Cat(const string& name, int age, const string& color)
        : name(name), age(age), color(color)
    {
        cout << "Конструктор Cat" << endl;
    }

    virtual ~Cat() {
        cout << "Cat " << name << " destroyed" << endl;
    }

    virtual void printInfo() const {
        cout << "Имя: " << name << " Возраст: " << age << " Цвет: " << color << endl;
    }

    virtual void sound() const {
        cout << "Cat makes a sound: Meow!" << endl;
    }
};

class HouseCat : public Cat {
private:
    string ownerName;
public:
    HouseCat(const string& name, int age, const string& color, const string& ownerName)
        : Cat(name, age, color), ownerName(ownerName)
    {
        cout << "Конструктор HouseCat" << endl;
    }

    ~HouseCat() override {
        cout << "HouseCat " << name << " destroyed" << endl;
    }

    void printInfo() const override {
        cout << "Имя: " << name << " Возраст: " << age << " Цвет: " << color
            << " Владелец: " << ownerName << endl;
    }

    void sound() const override {
        cout << name << " purrs: Mrrr-mrrr" << endl;
    }

    void play() const {
        cout << name << " plays with a ball" << endl;
    }
};

class WildCat : public Cat {
private:
    string habitat;
public:
    WildCat(const string& name, int age, const string& color, const string& habitat)
        : Cat(name, age, color), habitat(habitat)
    {
        cout << "Конструктор WildCat" << endl;
    }

    ~WildCat() override {
        cout << "WildCat " << name << " destroyed" << endl;
    }

    void printInfo() const override {
        cout << "Имя: " << name << " Возраст: " << age << " Цвет: " << color
            << " Среда обитания: " << habitat << endl;
    }

    void sound() const override {
        cout << name << " growls: Rrrr!" << endl;
    }
};

class PersianCat : public Cat {
private:
    int woolLength;
public:
    PersianCat(const string& name, int age, const string& color, int woolLength)
        : Cat(name, age, color), woolLength(woolLength)
    {
        cout << "Конструктор PersianCat" << endl;
    }

    ~PersianCat() override {
        cout << "PersianCat " << name << " destroyed" << endl;
    }

    void printInfo() const override {
        cout << "Имя: " << name << " Возраст: " << age << " Цвет: " << color
            << " Длина шерсти: " << woolLength << " см" << endl;
    }

    void sound() const override {
        cout << name << " says softly: Meow" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    cout << "=== Демонстрация полиморфизма ===" << endl << endl;

    // Создание объектов
    HouseCat houseCat("Мурка", 3, "рыжий", "Иван");
    WildCat wildCat("Рысь", 5, "пятнистый", "лес");
    PersianCat persianCat("Снежок", 2, "белый", 15);

    cout << endl;

    // Использование объектов через указатели на базовый класс
    Cat* cats[] = { &houseCat, &wildCat, &persianCat };

    for (int i = 0; i < 3; i++) {
        cats[i]->printInfo();
        cats[i]->sound();
        cout << endl;
    }

    // Специфичные методы
    houseCat.play();

    cout << endl << "=== Уничтожение объектов ===" << endl;

    return 0;
}