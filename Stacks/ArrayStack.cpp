#include <iostream>
#include <string>
using namespace std;

template <class T>
class ArrayStack
{
    public:
    /* Data members */
    int size;
    int top;
    T *stack;
    /* Constructor */
    ArrayStack(int n)
    {
        size = n;
        top = -1;
        stack = new T[n];
    }
    /* Methods */
    void push(T item);
    T pop();
    T peek(int index);
    T get_top();
    bool empty();
    bool full();
};

template <class T>
void ArrayStack<T>::push(T item)
{
    if (!full())
    {
        stack[++top] = item;
    }
}
template <class T>
T ArrayStack<T>::pop()
{
    if (!empty())
    {
        T data = stack[top--];
        return data;
    }
    return 0;
}

template <class T>
T ArrayStack<T>::peek(int index)
{
    if (!empty())
        if (index >= 0 && index <= top) return stack[index];
    return 0;
}

template <class T>
T ArrayStack<T>::get_top()
{
    if (!empty()) return stack[top];
    return 0;
}

template <class T>
bool ArrayStack<T>::empty()
{
    return top == -1 ? true : false;
}

template <class T>
bool ArrayStack<T>::full()
{
    return top == size-1 ? true : false;
}

int main()
{
    string strs[] = {"Reverse", "This", "String"}; 
    ArrayStack<string> *st = new ArrayStack<string>(3);
    for (int i = 0; i < 3; i++)
    {
        cout << strs[i] << " ";
        st->push(strs[i]);
    }
    cout << endl;
    cout << "Top: " << st->get_top() << endl;
    cout << "Item at index 1: " << st->peek(1) << endl;
    cout << "Is stack empty: ";
    st->empty() ? cout << "True" << endl : cout << "False" << endl;
    for (int i = 0; i < 3; i++)
        cout << st->pop() << " ";
    cout << endl;
    cout << "Is stack empty: ";
    st->empty() ? cout << "True" << endl : cout << "False" << endl;
}