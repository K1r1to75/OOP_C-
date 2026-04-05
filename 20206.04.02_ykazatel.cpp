#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

class Timer {
private:
    steady_clock::time_point startTime;
    string timerName;

public:
    // Конструктор
    Timer(const string& name = "Timer") : timerName(name) {
        startTime = steady_clock::now();
        cout << "[" << timerName << "] Запущен" << endl;
    }

    // Деструктор 
    ~Timer() {
        auto endTime = steady_clock::now();
        auto duration = duration_cast<milliseconds>(endTime - startTime);
        cout << "[" << timerName << "] Прошло времени: " << duration.count() << " мс" << endl;
    }

    // Метод для получения прошедшего времени
    long long getElapsed() const {
        auto currentTime = steady_clock::now();
        return duration_cast<milliseconds>(currentTime - startTime).count();
    }

    // Метод для сброса таймера
    void reset() {
        startTime = steady_clock::now();
        cout << "[" << timerName << "] Таймер сброшен" << endl;
    }
};

// Функция, которая возвращает unique_ptr<Timer>
unique_ptr<Timer> createTimer(const string& name = "Timer") {
    return make_unique<Timer>(name);
}

int main() {
    setlocale(LC_ALL, "ru");

    {
        cout << "\nВход в область видимости..." << endl;
        unique_ptr<Timer> timer1 = createTimer("Timer1");

        cout << "Выполнение операций..." << endl;
        this_thread::sleep_for(milliseconds(5000)); 
        cout << "Прошло " << timer1->getElapsed() << " мс с момента запуска" << endl;

        cout << "Выход из области видимости..." << endl;
    } 
    return 0;
}