#include<iostream>
using namespace std;

void palindrome(string s){
    string rev;
    for(int i=s.length()-1;i>=0;--i)
        rev+=s.at(i);
    
    if(s != rev)
        cout<<"Entered string is not palindrome";
    else
        cout<<"Entered string is palindrome";

//     int res = s.compare(rev);
//     if(res)
//         cout<<"Entered string is not palindrome";
//     else
//         cout<<"Entered string is plalindrome";
// }

int main(){
    palindrome("madam");
}