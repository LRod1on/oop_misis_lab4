#include <sstream>
#include <typeinfo>
#include <vector>
#include <list>
#include <set>

// Шаблонная функция для обмена значений
template <typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

// Шаблонная функция контейнер в строку
template <typename Container>
std::string containerToString(const Container& c) {
    std::ostringstream oss;
    oss << "\"";
    for (auto it = c.begin(); it != c.end(); ++it) {
        if (it != c.begin()) oss << ", ";
        oss << *it;
    }
    oss << "\"";
    return oss.str();
}