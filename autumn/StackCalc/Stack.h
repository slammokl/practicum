// File "Stack.h"
#ifndef STACK_H
#define STACK_H 1

#include <vector>
#include <stdexcept>

template <class T>
class Stack: public std::vector<T> {
public:
    Stack(int initialCapacity = 0):
        std::vector<T>()
    {
        std::vector<T>::reserve(initialCapacity);
    }

    void push(const T& x) {
        std::vector<T>::push_back(x);
    }

    void pop() {
        if (std::vector<T>::size() == 0)
            throw std::underflow_error("Stack is empty");
        std::vector<T>::pop_back();
    }

    T& top() {
        if (std::vector<T>::size() == 0)
            throw std::underflow_error("Stack is empty");
        return std::vector<T>::back();
    }

    const T& top() const {
        if (std::vector<T>::size() == 0)
            throw std::underflow_error("Stack is empty");
        return std::vector<T>::back();
    }    

    T& operator[](size_t i) {
        if (i >= std::vector<T>::size())
            throw std::range_error("Index out of bounds");
        return std::vector<T>::operator[](std::vector<T>::size() - i - 1);
    }

    const T& operator[](size_t i) const {
        if (i >= std::vector<T>::size())
            throw std::range_error("Index out of bounds");
        return std::vector<T>::operator[](std::vector<T>::size() - i - 1);
    }
};

#endif
