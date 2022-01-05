#include<iostream>
using namespace std;
#include<vector>

void maximunMinimum(vector<int> array) {
        int max = array[0], min = array[0];
        for (int i = 0; i < array.size(); i++) {
            if (array[i] > max)
                max = array[i];
            if (array[i] < min)
                min = array[i];
        }
        cout<<"Largest Element "<< max<<endl;
        cout<<"Smallest Element "<< min;
    }


int main(){
    vector<int> array = {1,2,3,4,5};
    maximunMinimum(array);
}