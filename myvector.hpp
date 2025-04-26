#include <iostream>
#include <algorithm>
#include <utility>

class MyVector {
private:
    int* data;
    size_t size;
    
public:
    // конструктор по умолчанию
    explicit MyVector(size_t size = 0) : size(size), data(size ? new int[size] : nullptr) {}
    
    // деструктор
    ~MyVector() {
        delete[] data;
    }
    
    // конструктор копирования (новый объект)
    MyVector(const MyVector& other) : size(other.size), data(size ? new int[other.size] : nullptr) {
        if (data){
            std::copy(other.data, other.data + size, data);
        }
    }
    
    // присваивание копированием
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = size ? new int[size] : nullptr;
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
    
    // move конструктор
    MyVector(MyVector&& other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
    }
    
    // move присваивание
    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = other.data;
            
            other.size = 0;
            other.data = nullptr;
        }
        return *this;
    }
    
    // функция получения размера
    size_t getSize() const { return size; }
    
    // оператор доступа к элементам по индексу
    int& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }
};
