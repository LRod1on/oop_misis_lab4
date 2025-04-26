
#include "myvector.hpp"
#include "template_f.hpp"
#include "myarray.hpp"
#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <chrono>

void measurePerformance() {
    const size_t largeSize = 100000000;
    
    // Создаем большой вектор
    MyVector original(largeSize);
    for (size_t i = 0; i < largeSize; i++) {
        original[i] = i % 100;
    }
    
    // Измеряем время копирования
    auto start = std::chrono::high_resolution_clock::now();
    MyVector copy = original;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    // Измерение перемещения
    start = std::chrono::high_resolution_clock::now();
    MyVector moved = std::move(original);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
        
}

int main() {
    // Копирование против move
    std::cout << "--- Move semantics demonstration ---" << std::endl;
    measurePerformance();

    // Демонстрация шаблонных функций
    std::cout << "--- Template functions demonstration ---" << std::endl;
    
    // mySwap
    int a = 5, b = 10;
    mySwap(a, b);
    std::cout << "After Swap: a = " << a << ", b = " << b << "\n";
    
    std::string s1 = "sus", s2 = "amogus";
    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    mySwap(s1, s2);
    std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    
    // containerToString
    std::vector<int> vec = {1, 2, 3};
    std::list<double> lst = {1.3, 2.6, 3.9};
    std::set<std::string> st = {"sus", "amogus"};
    
    std::cout << "Vector: " << containerToString(vec) << std::endl;
    std::cout << "List: " << containerToString(lst) << std::endl;
    std::cout << "Set: " << containerToString(st) << std::endl;
        
    // 3. Демонстрация шаблонного класса MyArray
    std::cout << "--- Template class MyArray demonstration ---" << std::endl;
    
    MyArray<int, 5> intArray;
    for (size_t i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    
    std::cout << "Int array: ";
    for (size_t i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    MyArray<std::string, 3> strArray;
    strArray[0] = "Amogus";
    strArray[1] = "Sus";
    strArray[2] = "Imposter";
    
    std::cout << "String array: ";
    for (size_t i = 0; i < strArray.size(); i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
