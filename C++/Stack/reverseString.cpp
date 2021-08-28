#include<iostream>
#include<stack>
using namespace std;

string reverse(string s){
    stack<char> nn;
    for(int i=0;i<s.length();i++)
        nn.push(s[i]);

    string ss;
    while(nn.size()>0){
        ss+= nn.top();
        nn.pop();
    }
    return ss;
}

int main(){
    cout<<reverse("hey wassup");
}