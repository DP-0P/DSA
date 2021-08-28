#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &stk, int k, int ex)
{
    if (stk.empty())
    {
        stk.push(k);
        return;
    }
    int exx = stk.top();
    stk.pop();
    insert(stk, k, ex);
    stk.push(exx);
}

void insertBottom(stack<int> &stk, int k)
{
    if (stk.empty())
        return;

    int ex = stk.top();
    stk.pop();
    insert(stk, k, ex);
    stk.push(ex);
}

void printSTK(stack<int> &stk)
{
    while (!stk.empty())
    {
        cout << stk.top() << " -> ";
        stk.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stk;
    // stk.push(5);
    // stk.push(4);
    // stk.push(3);
    // stk.push(2);
    // stk.push(1);

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.emplace(56);

    // insertBottom(stk, 6);
    printSTK(stk);
    // cout<<stk.top()<<endl;
    // insertBottom(stk,6);
    // cout<<stk.top();
}