#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class StringHolder {
protected:
    char* str;
public:
    StringHolder(const char* input) {
        str = new char[strlen(input) + 1];
        strcpy(str, input);
    }

    virtual void print() const {
        cout << str;
    }

    virtual ~StringHolder() {
        cout << "~StringHolder: " << str << endl;
        delete[] str;
    }
};

class ReverseString : public StringHolder {
public:
    ReverseString(const char* input) : StringHolder(input) {}

    void print() const override {
        int len = strlen(str);
        for (int i = len - 1; i >= 0; i--) {
            cout << str[i];
        }
    }

    ~ReverseString() {
        cout << "~ReverseString" << endl;
    }
};

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() {}
};

class Serializable {
public:
    virtual string serialize() const = 0;
    virtual ~Serializable() {}
};

class Circle : public Drawable, public Serializable {
public:
    int x, y, r;

    Circle(int cx, int cy, int radius) : x(cx), y(cy), r(radius) {}

    void draw() const override {
        cout << "Круг в (" << x << "," << y << ") радиус " << r << endl;
    }

    string serialize() const override {
        return "Круг " + to_string(x) + " " + to_string(y) + " " + to_string(r);
    }
};

class Rectangle : public Drawable, public Serializable {
public:
    int x, y, w, h;

    Rectangle(int rx, int ry, int width, int height) : x(rx), y(ry), w(width), h(height) {}

    void draw() const override {
        cout << "Прямоугольник в (" << x << "," << y << ") " << w << "x" << h << endl;
    }

    string serialize() const override {
        return "Прямоугольник " + to_string(x) + " " + to_string(y) + " " + to_string(w) + " " + to_string(h);
    }
};

int main() {
    setlocale(LC_ALL, "ru");


    StringHolder* a = new StringHolder("Привет");
    StringHolder* b = new ReverseString("Мир");

    a->print();
    cout << endl;
    b->print();
    cout << endl;

    delete a;
    delete b;
