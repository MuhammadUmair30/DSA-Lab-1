#ifndef ABSTRACTSTACK_H
#define ABSTRACTSTACK_H

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void display() const = 0;
    virtual T getMin() const = 0;
    virtual ~AbstractStack() {}
};

#endif