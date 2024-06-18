#include "stack.h"

template<typename T>
stack<T>::stack(int max):maxStackSize(max){
    initializeStack();
}

template<typename T>
stack<T>::stack(const stack<T> &other){
    copyStack(other);
}

template<typename T>
stack<T>::~stack(){
    delete[] list;
}

template<typename T>
bool stack<T>::isEmptyStack() const{
    return count == 0;
}

template<typename T>
bool stack<T>::isFullStack() const{
    return count == maxStackSize;
}

template<typename T>
void stack<T>::initializeStack(){
    count = 0;
    list = new T[maxStackSize];
}

template<typename T>
void stack<T>::push(const T &item){
    if(isFullStack()){
        throw std::out_of_range("Stack is full");
    }
    list[count++] = item;
}

template<typename T>
T stack<T>::pop(){
    if(isEmptyStack()){
        throw std::out_of_range("Stack is empty");
    }
    return list[--count];
}

template<typename T>
T stack<T>::top() const{
    if(isEmptyStack()){
        throw std::out_of_range("Stack is empty");
    }
    return list[count - 1]
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T> &other){
    if(this != other){
        delete list[];
        maxStackSize = other.maxStackSize;
        count = other.count;
        list = new T[maxStackSize];
        for(int i = 0; i < count; i++){
            list[i] = other.list[i];
        }
    }
    return *this;
}

template<typename T>
void stack<T>::copyStack(const stack<T> &other){
    this = other;
}