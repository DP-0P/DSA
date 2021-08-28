#include <iostream>
using namespace std;

#define size 100

class stack
{
public:
    char array[size];
    int top;

    stack()
    {
        top = -1;
    }

    void push(char data)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        array[++top] = data;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return '-';
        }

        return array[top--];
    }

    char peek()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return '-';
        }

        return array[top];
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    void print()
    {
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
        cout << endl;
    }
};

bool checkBalancedBrackets(string str)
{
    stack s;
    char x;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
            // continue;
        }

        if (s.isEmpty())
            return false;

        switch (str[i])
        {
        case ')':
            x = s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':
            x = s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':
            x = s.pop();
            if (x == '{' || x == '(')
                return false;
            break;
        }
    }

    return s.isEmpty();
}

void reverse(string ss)
{
    stack s;
    for (int i = 0; i < ss.length(); i++)
        s.push(ss[i]);
    for (int i = 0; i < ss.length(); i++)
        cout << s.pop();
}

int main()
{
    // stack s;
    // string ss = "{()}[]";
    // if(checkBalancedBrackets(ss))
    //     cout<<"true"<<endl;
    reverse("deepak is sexy");
    //     for (int i = 0; i < ss.length(); i++)
    //         s.push(ss[i]);
    //     cout << s.peek() << endl;
    //     cout << s.isEmpty() << endl;
    //     s.print();
    //     cout << s.pop() << endl;
    //     cout << s.pop() << endl;
    //     cout << s.peek() << endl;
    //     s.print();
}