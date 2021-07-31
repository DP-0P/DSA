#include<iostream>
using namespace std;

void Union(int arr1[],int l1,int arr2[], int l2){
    
    int arr3[l1+l2];
    int k=l1;
    int c=0;
    
    for(int i=0;i<l1;i++)
        arr3[i] = arr1[i];
    cout<<"done"<<endl;

    // for(int i=0;i<l2;i++){                          //1
    //     for(int j=0;j<l1;j++){                      //7
    //         if(arr1[j]==arr2[i])
    //             c++;
    //         else{
    //             arr3[k] = arr2[i];
    //             k++;
    //         }
    //     }
    // }
    
    // for(int i=0;i<l1;i++){
    //     for(int j=0;j<l2;j++){
    //         if(arr3[j]!=arr1[i]){
    //             arr3[k] = arr2[j];
    //             k++;
    //         }
    //     }
    // }

    int lenck = 0;
    int chk = l1;
    for(int i=0;i<l1;i++){
        int j=0;
        if(arr3[i]!=arr2[j]){
            lenck++;
            j++;
        }
        else
            j++;
    }

    for(int i=0;i<l1+l2;i++)
        cout<<arr3[i]<<endl;
    
    cout<<"k = "<<k;
}



int main(){

    int arr1[7] = {1,2,3,4,5,6,7};
    int arr2[3] = {7,8,9};
    int l1 = sizeof(arr1)/sizeof(arr1[0]);
    int l2 = sizeof(arr2)/sizeof(arr2[0]);
    Union(arr1,l1,arr2,l2);
    // for(int i=0;i<10;i++)
    //     cout<<array[i]<<endl;
    return 0;
}
