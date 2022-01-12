#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 4;
    int k = 17;
    int fact = 1;
    vector<int> num;
    for(auto i=1;i<n;i++){
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);
    string res = "";
    k = k-1;
    while(true){
        res = res + to_string(num[k/fact]);
        num.erase(num.begin() + k/fact);
        if(num.size()==0)
            break;
        k %=fact;
        fact = fact / num.size();
    }
    cout<<res;
}