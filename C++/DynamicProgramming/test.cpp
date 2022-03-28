#include <bits/stdc++.h>
using namespace std;
 
int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int tab[n + 1][sum + 1];
  // Initializing the first value of matrix
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;
     
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }
 
 
    return tab[n][sum];
}

int digSum(int n){
    int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
}

void summ(int n,int k){
    int sum = 0;
    int i=0,j=1;
    while(i!=n){
        if(digSum(j)<=k){
            sum += j;
            i++;
            j++;
        }
        else
            j++;
    }
    cout<<sum;
}
 
int main()
{
    summ(7,5);
}