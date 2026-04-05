#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;

public:
    // Конструктор
    BankAccount(const string& name, double initialBalance)
        : ownerName(name), balance(initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Ошибка: начальный баланс не может быть отрицательным!");
        }
    }

    // Метод для пополнения счета
    void deposit(double amount) {
        if (amount < 0) {
            throw invalid_argument("Ошибка: сумма пополнения не может быть отрицательной!");
        }
        balance += amount;
        cout << "Счет пополнен на " << amount << ". Новый баланс: " << balance << endl;
    }

    // Метод для снятия средств
    void withdraw(double amount) {
        if (amount < 0) {
            throw invalid_argument("Ошибка: сумма снятия не может быть отрицательной!");
        }
        if (amount > balance) {
            throw runtime_error("Ошибка: недостаточно средств на счете!");
        }
        balance -= amount;
        cout << "Снято " << amount << ". Остаток на счете: " << balance << endl;
    }

    // Метод для получения текущего баланса
    double getBalance() const {
        return balance;
    }

    // Метод для получения имени владельца
    string getOwnerName() const {
        return ownerName;
    }

    // Метод для отображения информации о счете
    void displayInfo() const {
        cout << "Владелец: " << ownerName << ", Баланс: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // создание счета

    try {
        BankAccount account2("Мария Сидорова", 1000);
        account2.displayInfo();

        // снятие средств

        try {
            account2.withdraw(300);
            account2.displayInfo();
        }
        catch (const exception& e) {
            cout << "Исключение: " <<  endl;
        }

        // пополнение счета

        try {
            account2.deposit(500);
            account2.displayInfo();
        }
        catch (const exception& e) {
            cout << "Исключение: " <<  endl;
        }

    }
    catch (const exception& e) {
        cout << "Неожиданное исключение: " << endl;
    }


    return 0;
}