#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(node *&head,int data){
    
    node *add = new node(data);
    if(head == NULL){
        head = add;
        return;
    }

    node *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    
    temp->next = add;
}

void print(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void add1(node *head){
    node *temp = head;
    int sum = 0;
    while(temp!=NULL){
        sum = sum*10 + temp->data;
        temp = temp->next;
    }
    cout<<sum+1<<endl;
}

node* moveBackToFront(node *head){
    node *temp = head;
    while(temp->next!= NULL)
        temp = temp->next;

    node *add = temp;

    temp = head;
    
    while(temp->next->next!=NULL)
        temp = temp->next;
    temp->next = NULL;

    temp = add;
    temp->next = head;
    head = add;
    return head;
}

node *reverseGroup(node *head, int k)
{

    node *previous = NULL;
    node *current = head;
    node *next = NULL;
    int c = 0;

    while (current != NULL and c < k){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        c++;
    }

    if(next!=NULL)
        head->next = reverseGroup(next,k);

    return previous;
}

int size(node *head)
{
    node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

node* greaterThanMid(node *head){
    
    int len = size(head)/2+1;
    int c = 1;

    node *temp = head;
    node *newList;

    while(temp!=NULL){
        
        if(c<=len){
            newList = temp;
            temp = temp->next;
            c++;
        }
        else{
            temp = temp->next;
            c++;
        }
    }
    return newList;
}

int main(){
    node *head = NULL;
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,1);
    insert(head,1);
    // head = greaterThanMid(head);
    // print(head);
    cout<<size(head);
}