#include <iostream>
using namespace std;

void spell(int n)
{
    
    switch (n)
    {
    case 1:
        cout << "One"
             << " ";
        break;

    case 2:
        cout << "Two"
             << " ";
        break;

        case 3:
        cout<<"Three"<<" ";
        break;

    case 4:
        cout << "Four"
             << " ";
        break;

    case 5:
        cout << "Five"
             << " ";
        break;

    case 6:
        cout << "Six"
             << " ";
        break;

    case 7:
        cout << "Seven"
             << " ";
        break;

    case 8:
        cout << "Eight"
             << " ";
        break;

    case 9:
        cout << "Nine"
             << " ";
        break;

    case 0:
        cout << "Zero"
             << " ";
        break;
    }
}

void rev(int n){
    if(n==0)
        return ;
    
    rev(n/10);
    spell(n%10);

}

int main(){
    rev(12);
}