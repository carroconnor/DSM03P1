#ifndef STACK_H
#define STACK_H
#include "stackADT.h"
#include <stdexcept>

template<typename T>
class stack {
    public:
        const static int DEFAULT_STACK_SIZE = 100;

	    stack(int max = DEFAULT_STACK_SIZE);
	    stack(const stack<T> &other);
	    ~stack();

	    bool isEmptyStack() const;
        bool isFullStack() const;
        void initializeStack();
        void push(const T&);

        T pop();
        T top() const;

        stack<T>& operator=(const stack<T> &);
    private:
        int count;
        int maxStackSize;
        void copyStack(const stack<T>&);
        //T *list = new T[DEFAULT_STACK_SIZE];
        std::vector<T> list;
};

//tempalte class definition and implementations need to be in the same file for compiler
template<typename T>
stack<T>::stack(int max):maxStackSize(max){
    initializeStack();
}

template<typename T>
stack<T>::stack(const stack<T> &other){
    //list = nullptr; // Initialize list to nullptr to avoid double deletion
    copyStack(other);
}

template<typename T>
stack<T>::~stack(){
    //delete[] list;
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
    //delete[] list; // Free existing memory if any
    list.clear(); //= new std::vector<T>();//T[maxStackSize];
}

template<typename T>
void stack<T>::push(const T &item){
    if(isFullStack()){
        throw std::out_of_range("Stack is full");
    }
    list.push_back(item);
    count++;
}

template<typename T>
T stack<T>::pop(){
    if(isEmptyStack()){
        throw std::out_of_range("Stack is empty");
    }
    list.pop_back();
    
    return list[--count];
}

template<typename T>
T stack<T>::top() const{
    if(isEmptyStack()){
        throw std::out_of_range("Stack is empty");
    }
    return list[count - 1];
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T> &other){
    //delete[] list;
    maxStackSize = other.maxStackSize;
    count = other.count;
    list = other.list; //= new vector<T>();//new T[other.maxStackSize];
    // for(int i = 0; i < count; i++){
    //     list[i] = other.list[i];
    // }

    return *this;
}

template<typename T>
void stack<T>::copyStack(const stack<T> &other){
    *this = other;
}
#endif