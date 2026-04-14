#ifndef MYSTACK_H
#define MYSTACK_H

#include "AbstractStack.h"
#include <iostream>
#include <stack>

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* stackArray;
    std::stack<T> minStack;
    int maxSize;
    int topIndex;

public:
    myStack(int size);
    ~myStack();
    void push(T value);
    T pop();
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
    T getMin() const;
};

template <typename T>
myStack<T>::myStack(int size) : maxSize(size), topIndex(-1) {
    stackArray = new T[maxSize];
}

template <typename T>
myStack<T>::~myStack() {
    delete[] stackArray;
}

template <typename T>
void myStack<T>::push(T value) {
    if (isFull()) {
        std::cout << "Stack is full! Cannot push " << value << std::endl;
    }
    else {
        stackArray[++topIndex] = value;
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
        else {
            minStack.push(minStack.top());
        }
    }
}

template <typename T>
T myStack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty! Cannot pop!" << std::endl;
        return T();
    }
    else {
        T poppedValue = stackArray[topIndex--];
        minStack.pop();
        return poppedValue;
    }
}

template <typename T>
T myStack<T>::top() const {
    if (isEmpty()) {
        std::cout << "Stack is empty! No top element." << std::endl;
        return T();
    }
    else {
        return stackArray[topIndex];
    }
}

template <typename T>
bool myStack<T>::isEmpty() const {
    return topIndex == -1;
}

template <typename T>
bool myStack<T>::isFull() const {
    return topIndex == maxSize - 1;
}

template <typename T>
void myStack<T>::display() const {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    }
    else {
        std::cout << "Stack elements from top to bottom:" << std::endl;
        for (int i = topIndex; i >= 0; --i) {
            std::cout << stackArray[i] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
T myStack<T>::getMin() const {
    if (isEmpty()) {
        std::cout << "Stack is empty! No minimum element." << std::endl;
        return T();
    }
    else {
        return minStack.top();
    }
}

template class myStack<int>;
template class myStack<float>;
template class myStack<std::string>;

#endif