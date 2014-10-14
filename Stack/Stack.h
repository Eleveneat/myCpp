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
