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
        T *list;
};
#endif