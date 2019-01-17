#include <iostream>
#include "fibonacci-heap.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    fibonacciheap fibo;
    fibo.insert(14);
    fibo.insert(10);
    fibo.insert(21);
    fibo.insert(3);
    fibo.insert(17);
    fibo.insert(19);
    fibo.insert(18);
    nodo* min = fibo.extractmin();
    std::cout << min->dato << '\n';
    min = fibo.extractmin();
    std::cout << min->dato << '\n';
    min = fibo.extractmin();
    std::cout << min->dato << '\n';
    min = fibo.extractmin();
    std::cout << min->dato << '\n';
    min = fibo.extractmin();
    std::cout << min->dato << '\n';
    min = fibo.extractmin();
    std::cout << min->dato << '\n';
    min = fibo.extractmin();
    std::cout << min->dato << '\n';
    return 0;
}