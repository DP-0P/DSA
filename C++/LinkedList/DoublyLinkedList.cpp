#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *previous;

    node(int val)
    {
        data = val;
        next = NULL;
        previous = NULL;
    }
};

node *tail;

void insertBack(node *&head, int data)
{
    node *add = new node(data);

    if(head==NULL){
        head = add;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = add;
    add->previous = temp;
    tail = add;
}

void insertFront(node *&head, int data){
    node *add = new node(data);
    add->next = head;
    if(head!=NULL)  
        head->previous = add;
    head = add;
}

void printLL(node *&head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* lastNode(node *&head){
    node *temp = head;
    while(temp->next!=NULL) 
        temp = temp->next;
    // node *Last = temp->previous;
    return temp;
}

void printReverse(node *&tail){
    node *temp = tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->previous;
    }
    cout<<endl;
}

void sumPair(node *head, int sum){
    node *first = head;
    int pair = 0;

    while(first!=NULL){
        node *second = first->next;
        while(second != NULL){
            if(first->data+second->data == sum){
                pair++;
                cout<<first->data<<" and "<<second->data<<endl;
            }
            second = second->next;
        }
        first = first->next;
    }
    if(!pair)
        cout<<"No such pairs found"<<endl;
}

void rotateAntiClockWiseByN(node *&head,int pos){
    if(pos == 0)
        return;
    
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = head;
    head->previous = temp;

    int count = 0;
    while(count<pos){
        head = head->next;
        temp = temp->next;
        count++;
    }
    temp->next = NULL;
    head->previous = NULL;
}

int main(){
    node *head = NULL;
    insertBack(head,1);
    insertBack(head,2);
    insertBack(head,3);
    insertBack(head,4);
    insertBack(head,5);
    // printLL(head);
    // printReverse(tail);
    // sumPair(head,5);
    printLL(head);
    rotateAntiClockWiseByN(head,2);
    printLL(head);
}