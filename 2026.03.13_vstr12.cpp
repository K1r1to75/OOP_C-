#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int count;
    int grow;

public:
    Array() : data(nullptr), size(0), count(0), grow(1) {}

    ~Array() {
        delete[] data;
    }

    Array(const Array& other) : data(nullptr), size(0), count(0), grow(1) {
        *this = other;
    }

    int GetSize() const { return size; }
    void SetSize(int newSize, int newGrow = 1) {
        grow = newGrow;
        if (newSize == size) return;

        T* newData = new T[newSize];
        int copyCount = (newSize < count) ? newSize : count;
        for (int i = 0; i < copyCount; i++) newData[i] = data[i];

        delete[] data;
        data = newData;
        size = newSize;
        count = copyCount;
    }

    int GetUpperBound() const { return (count > 0) ? count - 1 : -1; }
    bool IsEmpty() const { return count == 0; }

    void FreeExtra() {
        if (count < size) SetSize(count, grow);
    }

    void RemoveAll() {
        delete[] data;
        data = nullptr;
        size = 0;
        count = 0;
    }

    T& GetAt(int index) {
        if (index < 0 || index >= count) {
            cout << "Ошибка: индекс вне диапазона!" << endl;
            static T dummy{};
            return dummy;
        }
        return data[index];
    }

    void SetAt(int index, const T& value) {
        if (index >= 0 && index < count) data[index] = value;
        else cout << "Ошибка: индекс вне диапазона!" << endl;
    }

    T& operator[](int index) { return GetAt(index); }
    const T& operator[](int index) const { return GetAt(index); }

    void Add(const T& value) {
        if (count >= size) SetSize(size + grow, grow);
        data[count++] = value;
    }

    void Append(const Array& other) {
        for (int i = 0; i < other.count; i++) Add(other.data[i]);
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            count = other.count;
            grow = other.grow;
            data = new T[size];
            for (int i = 0; i < count; i++) data[i] = other.data[i];
        }
        return *this;
    }

    T* GetData() { return data; }
    const T* GetData() const { return data; }

    void InsertAt(int index, const T& value) {
        if (index < 0 || index > count) {
            cout << "Ошибка: индекс вне диапазона!" << endl;
            return;
        }

        if (count >= size) SetSize(size + grow, grow);

        for (int i = count; i > index; i--) data[i] = data[i - 1];
        data[index] = value;
        count++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= count) {
            cout << "Ошибка: индекс вне диапазона!" << endl;
            return;
        }

        for (int i = index; i < count - 1; i++) data[i] = data[i + 1];
        count--;
    }

    void Print() const {
        cout << "[";
        for (int i = 0; i < count; i++) {
            cout << data[i];
            if (i < count - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    cout << "\nМассив int\n";
    Array<int> arr;

    arr.SetSize(3, 2);
    cout << "Размер: " << arr.GetSize() << endl;

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Add(40);

    cout << "Элементы: ";
    arr.Print();
    cout << "Всего элементов: " << arr.GetUpperBound() + 1 << endl;
    cout << "Элемент [2]: " << arr[2] << endl;

    arr.InsertAt(1, 15);
    cout << "После вставки 15 в [1]: ";
    arr.Print();

    arr.RemoveAt(2);
    cout << "После удаления [2]: ";
    arr.Print();

    cout << "\ndouble\n";
    Array<double> darr;
    darr.Add(1.1);
    darr.Add(2.2);
    darr.Add(3.3);
    cout << "double массив: ";
    darr.Print();

    Array<double> copy = darr;
    cout << "Копия: ";
    copy.Print();

    Array<double> darr2;
    darr2.Add(4.4);
    darr2.Add(5.5);
    darr.Append(darr2);
    cout << "После сложения: ";
    darr.Print();

    return 0;
}