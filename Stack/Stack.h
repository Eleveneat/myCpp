
#ifndef _STACK_H_
#define _STACK_H_
template<class T>
class Stack {
    //LIFO对象
public:
    Stack( int MaxStackSize = 10);
    ~Stack() { delete []stack;}
    bool isEmpty() const {return top == -1;}
    bool isFull() const {return tip == MaxTop;}
    T Top() const ;
    int Size();
    Stack<T >& Add(const T& x);
    Stack<T >& Delete(T& x);
    Stack<T >& inputStack(Stack< T>& otherStack);
    Stack<T >& ouputStack(Stack< T>& otherStack);
private:
    int top;  //栈顶
    int MaxTop;  //最大的栈顶
    int size;  //堆栈中元素的数目
    T *stack;  //堆栈元素数组
    
};
#endif