#include <iostream>
using namespace std;

#define size 10

class stack
{
public:
    int array[size];
    int top;

    stack()
    {
        top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        array[++top] = data;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }

        return array[top--];
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        return array[top];
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    void print()
    {
        for (int i=top;i>=0;i--)
            cout << array[i] << " ";
        cout<<endl;
    }

    void reverseRecursion(){
        
    }

};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
    s.print();
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    s.print();
}