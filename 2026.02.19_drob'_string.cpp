#include <iostream>
using namespace std;
class Fraction {
private:
    int num;
    int den;

public:
    // Ввод дроби
    void input() {
        cout << "Введите числитель: ";
        cin >> num;
        cout << "Введите знаменатель: ";
        cin >> den;
        if (den == 0) {
            cout << "Знаменатель не может быть 0! Установлен 1.\n";
            den = 1;
        }
    }

    // Вывод дроби
    void show() {
        cout << num << "/" << den;
    }

    // Сложение
    Fraction add(Fraction f2) {
        Fraction res;
        res.num = num * f2.den + f2.num * den;
        res.den = den * f2.den;
        return res;
    }

    // Вычитание
    Fraction sub(Fraction f2) {
        Fraction res;
        res.num = num * f2.den - f2.num * den;
        res.den = den * f2.den;
        return res;
    }

    // Умножение
    Fraction mul(Fraction f2) {
        Fraction res;
        res.num = num * f2.num;
        res.den = den * f2.den;
        return res;
    }

    // Деление
    Fraction div(Fraction f2) {
        Fraction res;
        res.num = num * f2.den;
        res.den = den * f2.num;
        if (res.den == 0) {
            cout << "Деление на 0! Установлен знаменатель 1.\n";
            res.den = 1;
        }
        return res;
    }
};

class String {
private:
    char* str;
    int len;
    static int objCount;

public:
    String() {
        len = 80;
        str = new char[len + 1];
        str[0] = '\0';
        objCount++;
    }

    String(int size) {
        len = size;
        str = new char[len + 1];
        str[0] = '\0';
        objCount++;
    }

    String(const char* s) {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        objCount++;
    }

    // Ввод строки
    void input() {
        cout << "Введите строку (до " << len << " символов): ";
        cin.getline(str, len + 1);
    }

    // Вывод строки
    void print() {
        cout << str;
    }

    static int getCount() {
        return objCount;
    }
};

// Инициализация статической переменной
int String::objCount = 0;






int main() {
    setlocale(LC_ALL, "ru");

    String s1; // 80 символов
    String s2(50); // 50 символов
    String s3("Привет"); // инициализация строкой

    cout << "Объектов создано: " << String::getCount() << endl;

    cout << "s3: ";
    s3.print();
    cout << endl;

    cout << "Введите строку для s1:\n";
    s1.input();
    cout << "s1: ";
    s1.print();
    cout << endl;

    cout << "Объектов сейчас: " << String::getCount() << endl;

    Fraction a, b, c;

    cout << "Дробь 1:\n";
    a.input();
    cout << "Дробь 2:\n";
    b.input();

    cout << "\nСумма: ";
    c = a.add(b);
    c.show();

    cout << "\nРазность: ";
    c = a.sub(b);
    c.show();

    cout << "\nПроизведение: ";
    c = a.mul(b);
    c.show();

    cout << "\nЧастное: ";
    c = a.div(b);
    c.show();
    cout << endl;

    return 0;
}



