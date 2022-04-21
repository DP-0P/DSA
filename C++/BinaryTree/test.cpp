#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main(){
    string s = "deepak is great";
    // s+=' ';
    stack<char> ss;
    string res;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ')
            ss.push(s[i]);
        
        else{
            while(!ss.empty()){
                res+=ss.top();
                ss.pop();
            }
                res+=' ';
        }
    }
    while(!ss.empty()){
        res+=ss.top();
        ss.pop();
    }
    cout<<res;
    cout<<'k';
}