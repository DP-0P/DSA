#include<iostream>
using namespace std;
#include<vector>
#include<queue>

vector<string> res;

class minHeapNode{
    public:
    char data;
    int frequency;
    minHeapNode *left,*right;
    minHeapNode(char data,int frequency){
        left = right = NULL;
        this->data = data;
        this->frequency = frequency;
    }
};

class compare {
    public:
    bool operator()(minHeapNode* left, minHeapNode* right)
 
    {
        return (left->frequency > right->frequency);
    }
};

void print(minHeapNode *root,string s){
    if(!root)
        return;
        
    // printing
    if(root->data != '$')
        res.push_back(root->data+": "+s);
    
    print(root->left,s+"0");
    print(root->right,s+"1");
}

void huffmanCoding(string data,int frequency[],int size){
    minHeapNode *left,*right,*head;
    priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap;
 
    for (int i = 0; i < size; ++i)
        minHeap.push(new minHeapNode(data[i], frequency[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();

        head = new minHeapNode('$', left->frequency + right->frequency);
 
        head->left = left;
        head->right = right;
 
        minHeap.push(head);
    }
    print(minHeap.top(),"");
}

int main()
{
 
    string s = "abcdef";
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    huffmanCoding(s, freq, s.size());
    
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}