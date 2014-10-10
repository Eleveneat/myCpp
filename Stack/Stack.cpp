#include "Stack.h"

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
