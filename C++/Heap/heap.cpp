#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &heap,int root){
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    int size = heap.size();

    if(l<size && heap[l]>heap[largest])
        largest = l;
    
    if(r<size && heap[r]>heap[largest])
        largest = r;
    
    if(largest!=root){
        int temp = heap[root];
        heap[root] = heap[largest];
        heap[largest] = temp;

        heapify(heap,largest);
    }
}

void buildHeap(vector<int> &heap){
    int startIndex = (heap.size()/2)-1;

    for(int i=startIndex;i>=0;i--)
        heapify(heap,i);
}

void printHeap(vector<int> &heap){
    for(int i=0;i<heap.size();i++)
        cout<<heap[i]<< " ";
    cout<<endl;
}

void insert(vector<int> &heap, int value)
{
    int size = heap.size();
    heap[size] = value;
    cout<<heap[size]<<endl;
    heapify(heap,heap.size()-1);
}

void deleteRoot(vector<int> &heap){
    int last = heap[heap.size()-1];
    heap[0] = last;
    cout<<last<<endl;
    heapify(heap,0);
}

// void levelOrderTraversal()

int main()
{
    vector<int> heap = {2,3,4,5,10};
    // int array[12]={0};
    // for(int i=0;i<11;i++)
    //     insert(array,12,arr[i]);
    
    // for(int i=0;i<12;i++)
    //     cout<<array[i]<<" ";
    // cout<<endl;

    printHeap(heap);
    buildHeap(heap);
    // printHeap(heap);
    insert(heap,15);
    // printHeap(heap);
    // deleteRoot(heap);
    printHeap(heap);

}