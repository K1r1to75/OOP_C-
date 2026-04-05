#include <iostream>
#include <stdexcept>

using namespace std;

// Создаём пространство имён Geometry
namespace Geometry {
    // Константа PI
    const double PI = 3.14159;

    // Функция для вычисления площади круга
    double circleArea(double radius) {
        if (radius < 0) {
            throw invalid_argument("Радиус не может быть отрицательным!");
        }
        return PI * radius * radius;
    }

    // Функция для вычисления площади прямоугольника
    double rectangleArea(double width, double height) {
        if (width < 0 || height < 0) {
            throw invalid_argument("Ширина и высота не могут быть отрицательными!");
        }
        return width * height;
    }

    // Вложенное пространство имён Shapes
    namespace Shapes {
        // Класс Circle
        class Circle {
        private:
            double radius;

        public:
            // Конструктор
            Circle(double r) : radius(r) {
                if (radius < 0) {
                    throw invalid_argument("Радиус не может быть отрицательным!");
                }
            }

            // Метод area() использует Geometry::circleArea
            double area() const {
                return Geometry::circleArea(radius);
            }

            // Геттер для радиуса
            double getRadius() const {
                return radius;
            }
        };
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    double circleArea1 = Geometry::circleArea(5.0);
    double rectangleArea1 = Geometry::rectangleArea(4.0, 6.0);

    cout << "Площадь круга (радиус 5): " << circleArea1 << endl;
    cout << "Площадь прямоугольника (4x6): " << rectangleArea1 << endl;

 
    Geometry::Shapes::Circle circle1(3.0);
    cout << "Площадь круга через класс Circle (радиус 3): " << circle1.area() << endl;

    cout << "\n" << endl;

    try {
        // Попытка создать круг с отрицательным радиусом
        Geometry::Shapes::Circle circle2(-2.0);
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        // Попытка вычислить площадь прямоугольника с отрицательными сторонами
        double invalidRect = Geometry::rectangleArea(-5.0, 10.0);
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}