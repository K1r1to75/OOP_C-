#include <iostream>
#include <fstream>
#include <string>  
#include <cmath>
using namespace std;

class StudentBasic {
private:
    string fullName;
    string birthDate;
    string phone;
    string city;
    string country;
    string university;
    string uniCity;
    string uniCountry;
    string groupNumber;

public:
    void inputData() {
        cin.ignore();  
        cout << "Введите ФИО: "; getline(cin, fullName);
        cout << "Введите дату рождения: "; getline(cin, birthDate);
        cout << "Введите телефон: "; getline(cin, phone);
        cout << "Введите город: "; getline(cin, city);
        cout << "Введите страну: "; getline(cin, country);
        cout << "Введите название учебного заведения: "; getline(cin, university);
        cout << "Введите город учебного заведения: "; getline(cin, uniCity);
        cout << "Введите страну учебного заведения: "; getline(cin, uniCountry);
        cout << "Введите номер группы: "; getline(cin, groupNumber);
    }

    void displayData() const {
        cout << "ФИО: " << fullName << endl;
        cout << "Дата рождения: " << birthDate << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Город: " << city << endl;
        cout << "Страна: " << country << endl;
        cout << "Учебное заведение: " << university << endl;
        cout << "Город (уч. заведения): " << uniCity << endl;
        cout << "Страна (уч. заведения): " << uniCountry << endl;
        cout << "Группа: " << groupNumber << endl;
    }
};

class Point {
private:
    double x, y, z;

public:
    Point() : x(0), y(0), z(0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    Point(const Point& other) : x(other.x), y(other.y), z(other.z) {}

    void inputData() {
        cout << "Введите x, y, z: ";
        cin >> x >> y >> z;
    }

    void displayData() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Ошибка открытия файла " << filename << " для записи!" << endl;
            return;
        }
        file << x << " " << y << " " << z;
        file.close();
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Ошибка открытия файла " << filename << " для чтения!" << endl;
            return;
        }
        file >> x >> y >> z;
        file.close();
    }
};