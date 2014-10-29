/*
*    Filename: Stack.h
*    Description: None.
*    Last modified: 2014-10-14 10:51
*
*    Created by Eleven on 2014-10-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/
#ifndef _STACK_H_
#define _STACK_H_
template<class T>
class Stack {
    //LIFO对象
public:
    Stack( int MaxStackSize = 10);
    ~Stack() { delete []stack;}
    bool isEmpty() const {return top == -1;}
    bool isFull() const {return top == MaxTop;}
    T Top() const ;
    int Size();
    void Push(const T& x);
    void Pop(T& x);
    void inputStack(Stack<T> otherStack);
    Stack<T> ouputStack();
private:
    int top;  //栈顶
    int MaxTop;  //最大的栈顶
    T *stack;  //堆栈元素数组
};
#endif

template<class T>
Stack<T>::Stack(int MaxStackSize)
{//Stack类构造函数
    MaxTop = MaxStackSize - 1;
    stack = new T [MaxStackSize];
    top = -1;
}
template<class T>
T Stack <T>::Top() const
{//返回栈顶元素
    if (isEmpty())throw OutOfBounds();
    else return stack[top];
}
template<class T>
void Stack<T>::Push(const T& x)
{//添加元素x
    if (isFull())throw NoMem();
    stack[++top] = x;
}
template<class T>
void Stack<T>::Pop(T & x)
{//删除栈顶元素，并将其送入x
    if (isEmpty())throw OutOfBounds();
    x = stack[top--];
}
template<class T>
int Stack<T>::Size()
{//返回堆栈的大小
    return top + 1;
}
template<class T>
void Stack<T>::inputStack(Stack otherStack)
{//输入一个堆栈
    if (MaxTop < top + otherStack.top)throw OutOfBounds();
    int tmpSize = otherStack.Size();
    T *tmpSta = new T[tmpSize];
    for(int i = 0; i < tmpSize; ++i) {
        tmpSta[i] = otherStack.Top();
        otherStack.Pop();
    }
    for(int i = tmpSize - 1; i < 0; --i) {
        this->Push(tmpSta[i]);
    }
    delete []tmpSta;
}
template<class T>
Stack Stack<T>::outputStack() {
    return *this;
}
