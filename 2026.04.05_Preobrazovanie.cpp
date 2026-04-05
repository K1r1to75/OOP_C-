#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shape {
public:
    virtual void draw() const {
        cout << "Drawing generic Shape" << endl;
    }

    virtual ~Shape() {}
    virtual string getType() const { return "Shape"; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        cout << "Drawing Circle with radius " << radius << endl;
    }

    string getType() const override { return "Circle"; }
    double getRadius() const { return radius; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        cout << "Drawing Rectangle " << width << "x" << height << endl;
    }

    string getType() const override { return "Rectangle"; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

void identifyAndDraw(Shape* s) {
    cout << "\n--- Обработка фигуры ---" << endl;

    Circle* circle = dynamic_cast<Circle*>(s);
    if (circle) {
        cout << "Тип: Circle" << endl;
        circle->draw();
        cout << "Радиус: " << circle->getRadius() << endl;
        return;
    }

    Rectangle* rect = dynamic_cast<Rectangle*>(s);
    if (rect) {
        cout << "Тип: Rectangle" << endl;
        rect->draw();
        cout << "Размеры: " << rect->getWidth() << "x" << rect->getHeight() << endl;
        return;
    }

    cout << "Тип: Unknown Shape" << endl;
    s->draw();
}

int main() {
    setlocale(LC_ALL, "ru");



    vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(3.5));
    shapes.push_back(new Rectangle(10.0, 2.0));
    shapes.push_back(new Shape());

    for (size_t i = 0; i < shapes.size(); i++) {
        identifyAndDraw(shapes[i]);
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}