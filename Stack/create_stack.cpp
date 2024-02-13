#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top; // To access top element
    int size;
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1; // As 0 is valid index and -1 is not valid and will help in empty stack
    }

    // Functions
    void push(int data)
    {
        if (size - top > 1)
        {
            // space available
            // insert
            top++;
            arr[top] = data;
        }
        else
        {
            // space not available
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            // stack is empty
            cout << "Stack underflow, cant delete element" << endl;
        }
        else
        {
            // stack is not empty
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "There is not element in Stack " << endl;
        }
        else
        {
            return arr[top];
        }
    }

    // return number of valid elements present in stack
    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(10);
    // Insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // Printing stack
    while (!s.isEmpty())
    {
        cout << s.getTop() << endl;
        s.pop();
    }
    // Checking size
    cout << "Size of stack = " << s.getSize() << endl;
    // Checking empty or not
    if (s.isEmpty())
    {
        cout << "Stack empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    return 0;
}