#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Vehicle {
public:
    virtual void startEngine() const {
        cout << "Двигатель запущен" << endl;
    }

    virtual int getMaxSpeed() const {
        return 0;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void startEngine() const override {
        cout << "Двигатель машины запущен" << endl;
    }

    int getMaxSpeed() const override {
        return 180;
    }
};

class ElectricCar : public Car {
public:
    void startEngine() const override {
        cout << "Электромотор тихо запущен" << endl;
    }

    int getMaxSpeed() const final override {
        return 180;
    }
};

class Bicycle final : public Vehicle {
public:
    void startEngine() const override {
        cout << "Нет двигателя" << endl;
    }

    int getMaxSpeed() const override {
        return 30;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    
    Vehicle* v1 = new Car();
    Vehicle* v2 = new ElectricCar();
    Vehicle* v3 = new Bicycle();

    v1->startEngine();
    cout << "Скорость: " << v1->getMaxSpeed() << endl;

    v2->startEngine();
    cout << "Скорость: " << v2->getMaxSpeed() << endl;

    v3->startEngine();
    cout << "Скорость: " << v3->getMaxSpeed() << endl;

    delete v1;
    delete v2;
    delete v3;

    return 0;
}