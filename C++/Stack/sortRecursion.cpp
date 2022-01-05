#include<iostream>
using namespace std;
#include<stack>


void insert(stack<int> &s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int curr = s.top();
    if(curr>x){
        s.pop();
        insert(s,x);
        s.push(curr);
    }
    else
        s.push(x);
    return;
}

void sort(stack<int> &st){
    if(st.size()==1)
        return;
    
    int x = st.top();
    st.pop();
    sort(st);
    insert(st,x);
    return;
}

void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;
    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);
    print(st);
    sort(st);
    print(st);
}