#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices){
    int min = prices[0];
    int max = 0 ;
    for(int i=1;i<prices.size();i++){
        if(prices[i]<min)
            min=prices[i]; 

        if(max<prices[i]-min)
            max = prices[i]-min;
    }
    return max;
}

int main (){
    vector<int> prices = {3,2,6,5,0,3};
    cout<<maxProfit(prices);
}