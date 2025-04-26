#include <stdexcept>
#include <string>

template <typename T, size_t N>
class MyArray {
private:
    T data[N];
    
public:
    // конструктор по умолчанию
    MyArray() = default;
    
    // конструктор с инициализацией
    explicit MyArray(const T& initValue) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = initValue;
        }
    }
    
    // доступ по индексу
    T& operator[](size_t index) {
        if (index >= N) throw std::out_of_range("Index out of range");
        return data[index];
    }
    
    // размер массива
    constexpr size_t size() const {
        return N;
    }
    
    // заполнение массива значением
    void fill(const T& value) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }
};
