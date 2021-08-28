#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &stk, int in)
{
    if (stk.empty())
    {
        stk.push(in);
        return;
    }

        int ex = stk.top();
        stk.pop();
        insert(stk, in);
        stk.push(ex);
    
}

void reverse(stack<int> &stk)
{
    if(stk.empty())
        return;
        
        int ex = stk.top();
        stk.pop();
        reverse(stk);
        insert(stk, ex);
    
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    cout<<stk.top()<<endl;
    reverse(stk);
    cout<<stk.top()<<endl;
}