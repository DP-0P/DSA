#include <iostream>
#include <vector>
using namespace std;

//max done min pending
void heapify(vector<int> &heap, int root)
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    int size = heap.size();

    if (l < size && heap[l] > heap[largest])
        largest = l;

    if (r < size && heap[r] > heap[largest])
        largest = r;

    if (largest != root)
    {
        int temp = heap[root];
        heap[root] = heap[largest];
        heap[largest] = temp;

        heapify(heap, largest);
    }
}

void minHeapify(vector<int> &heap, int root)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int smallest = root;
    int size = heap.size();

    if (left < size and heap[left] < heap[smallest])
        smallest = left;

    if (right < size and heap[right] < heap[smallest])
        smallest = right;

    if (smallest != root)
    {
        swap(heap[root], heap[smallest]);
        minHeapify(heap, smallest);
    }
}

void buildMinHeap(vector<int> &heap)
{
    int start = heap.size() / 2 - 1;

    for (int i = start;i>=0;i--)
        minHeapify(heap,i);
}

void buildHeap(vector<int> &heap)
{
    int startIndex = (heap.size() / 2) - 1;

    for (int i = startIndex; i >= 0; i--)
        heapify(heap, i);
}

void printHeap(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); i++)
        cout << heap[i] << " ";
    cout << endl;
}

void kthMaximum(vector<int> heap, int k)
{
    int i = 0;
    for (int i = 0; i < k; i++)
        if (i <= k)
            cout << heap.at(i) << " ";
    cout << endl;
}

void insert(vector<int> &heap, int value)
{
    int size = heap.size();
    heap[size] = value;
    cout << heap[size] << endl;
    heapify(heap, heap.size() - 1);
}

void deleteRoot(vector<int> &heap)
{
    int last = heap[heap.size() - 1];
    heap[0] = last;
    cout << last << endl;
    heapify(heap, 0);
}

void heapifySort(vector<int> &heap, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapifySort(heap, size, largest);
    }
}

void heapSort(vector<int> &heap)
{
    for (int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapifySort(heap, i, 0);
    }
}

void mergeHeap(vector<int> &merged,vector<int> &heap1,vector<int> &heap2){
    for(int i=0;i<heap1.size();i++)
        merged[i] = heap1[i];
    
    for(int i=0;i<heap2.size();i++)
        merged[heap1.size()+i] = heap2[i];
    
    buildHeap(merged);
}

// void levelOrderTraversal()

int main()
{
    vector<int> heap = {1, 23, 12, 9, 30, 2, 50};
    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {12, 7, 9};
    vector<int> merged(heap1.size()+heap2.size());
    // int array[12]={0};
    // for(int i=0;i<11;i++)
    //     insert(array,12,arr[i]);
    // for(int i=0;i<12;i++)
    //     cout<<array[i]<<" ";
    // cout<<endl;
    mergeHeap(merged,heap1,heap2);
    printHeap(merged);
    // buildHeap(heap);
    // printHeap(heap);
    // buildMinHeap(heap);
    // printHeap(heap);
    // printHeap(heap);
    // insert(heap,15);
    // heapSort(heap);
    // printHeap(heap);
    // deleteRoot(heap);
    // printHeap(heap);
    // kthMaximum(heap, 4);
}