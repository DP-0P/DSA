#include<iostream>
using namespace std;

void reverse(string s){
    int start = 0;
    int end = s.length()-1;
    while (start<end)
    {
        char temp = s.at(start);
        s.at(start) = s.at(end);
        s.at(end) = temp;
        start++;
        end--;
    }
    cout<<s;
}

int main(){
    reverse("yo yo yo");
}