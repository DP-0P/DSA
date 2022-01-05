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

void insertFront(node *&head, int data)
{
    node *add = new node(data);

    if (head == NULL)
    {
        head = add;
        head->next = head;
        return;
    }

    node *temp = head;
    add->next = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = add;
    head = add;
}

void insertBack(node *&head, int data)
{
    node *add = new node(data);
    if (head == NULL)
    {
        head = add;
        head->next = head;
        return;
    }

    node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = add;
    temp->next->next = head;
    // temp->next->next = head;
}

bool isCircular(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->next == head)
            return true;
        temp = temp->next;
    }
    return false;
}

void deleteLL(node *head, int data)
{
    node *previous = NULL;
    node *current = head;
    while (current != NULL)
    {
        if(current->data == data){
            if(current->next == NULL){
                previous->next = NULL;
                return;
            }
            else if(current->next != NULL){
                current->data = current->next->data;
                current->next = current->next->next;
                return;
            }
        }
        previous = current;
        current = current->next;
    }
}

void reverse(node *&head){
    node *previous = NULL;
    node *current = head;
    node *next = NULL;

    do{
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }while(current!=head);
    head->next = previous;
    head = previous;
}

void printLL(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void split(node *head, node **head1,node **head2){
    node *first = head;
    node *second = head;

    if(head == NULL)
        return;

    while(second ->next != head and second->next->next != head){
        first = first->next;
        second = second->next->next;
    }

    if(second->next->next == head)
        second = second->next;
    
    *head1 = head;

    if(head->next != head)
        *head2 = first->next;

    second->next = first->next;

    first->next = head;
}

int main()
{
    node *head = NULL;
    insertBack(head, 1);
    insertBack(head, 2);
    insertBack(head, 3);
    insertBack(head, 4);
    insertBack(head, 5);
    printLL(head);
    cout<<isCircular(head)<<endl;
    // reverse(head);
    // printLL(head);
    // cout<<isCircular(head)<<endl;
    node *head1 = NULL;//1 2 3
    node *head2 = NULL;// 4 5

    split(head,&head1,&head2);

    printLL(head1);
    isCircular(head1);

    printLL(head2);
    isCircular(head2);
}