#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class ThreadGuard {
private:
    thread m_thread;

public:
    // Конструктор 
    template<typename Callable>
    explicit ThreadGuard(Callable&& func)
        : m_thread(forward<Callable>(func)) {
        cout << "ThreadGuard: поток запущен" << endl;
    }

    // Деструктор 
    ~ThreadGuard() {
        if (m_thread.joinable()) {
            cout << "ThreadGuard: ожидание завершения потока..." << endl;
            m_thread.join();
            cout << "ThreadGuard: поток завершён" << endl;
        }
    }

    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;

    // Разрешаем перемещение
    ThreadGuard(ThreadGuard&& other) noexcept
        : m_thread(move(other.m_thread)) {
    }

    ThreadGuard& operator=(ThreadGuard&& other) noexcept {
        if (this != &other) {
            if (m_thread.joinable()) {
                m_thread.join();
            }
            m_thread = move(other.m_thread);
        }
        return *this;
    }
};

void slowFunction(int id, int delayMs) {
    cout << "Поток " << id << " начал работу" << endl;
    this_thread::sleep_for(chrono::milliseconds(delayMs));
    cout << "Поток " << id << " завершил работу (задержка " << delayMs << " мс)" << endl;
}

void fastFunction(int id) {
    cout << "Поток " << id << " выполнил быструю работу" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "=== Демонстрация работы ThreadGuard ===" << endl;
    cout << "=========================================" << endl;

    {
        cout << "\n[1] Запускаем медленный поток (задержка 2 секунды)..." << endl;
        ThreadGuard slowGuard([]() {
            slowFunction(1, 2000);
            });

        cout << "[2] Запускаем быстрый поток..." << endl;
        ThreadGuard fastGuard([]() {
            fastFunction(2);
            });

        cout << "[3] Запускаем поток со средней задержкой (1 секунда)..." << endl;
        ThreadGuard mediumGuard([]() {
            slowFunction(3, 1000);
            });

        cout << "\nВсе потоки запущены. Выходим из области видимости..." << endl;
    }

    cout << "\nВсе потоки завершены. Программа продолжает работу." << endl;

    return 0;
}