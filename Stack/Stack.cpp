
#include "Stack.h"


template<class T>
Stack<T >::Stack(int MaxStackSize)
{//Stack类构造函数
    MaxTop = MaxStackSize - 1;
    stack = new T [MaxStackSize];
    top = -1;
    size = 0;
}
template<class T>
T Stack <T>::Top() const
{//返回栈顶元素
    if (isEmpty())throw OutOfBounds();
    else return stack[top];
}
template<class T>
Stack<T >& Stack< T>::Add(const T& x)
{//添加元素x
    if (isFull())throw NoMem();
    stack[++top] = x;
    return *this ;
}
template<class T>
Stack<T >& Stack< T>::Delete(T & x)
{//删除栈顶元素，并将其送入x
    if (isEmpty())throw OutOfBounds();
    x = stack[top--];
    return *this ;
}
template<class T>
int Stack <T>::Size()
{//返回堆栈的大小
    size = top + 1;
    return size;
}
template<class T>
Stack<T >& Stack< T>::inputStack(Stack <T>& otherStack)
{
    if (MaxTop < otherStack .Size() - 1)throw OutOfBounds();
    ｝
    
    
