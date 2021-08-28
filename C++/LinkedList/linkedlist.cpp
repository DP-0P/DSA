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
        return;
    }
    node *temp = add;
    temp->next = head;
    head = add;
}

void insertBack(node *&head, int data)
{
    node *add = new node(data);
    if (head == NULL)
    {
        head = add;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = add;
}

void insertAt(node *head, int data, int index)
{
    node *add = new node(data);
    if (head == NULL)
    {
        head = add;
        return;
    }
    node *temp = head;
    index--;
    if (temp != NULL)
        for (int i = 0; i < index && temp->next != NULL; i++)
            temp = temp->next;
    add->next = temp->next;
    temp->next = add;
}

void printLL(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

void deleteAll(node *head,int data){
    node *previous = NULL;
    node *current = head;
    while(current != NULL){
        while (current->data == data)
        {
            if(current->next == NULL){
                previous->next = NULL;
                return;
            }
            else if(current->next != NULL){
                current->data = current->next->data;
                current->next = current->next->next;
            }
        }
        previous = current;
        current = current->next;
    }
}

void search(node *head, int data)
{
    node *temp = head;
    int search = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            cout << search << endl;
            return;
        }
        else
            search++;
        temp = temp->next;
    }
}

void get(node *head, int index)
{
    node *temp = head;
    int search = 0;
    while (temp != NULL)
    {
        if (search == index)
        {
            cout << temp->data << endl;
            return;
        }
        else
            search++;
        temp = temp->next;
    }
}

void contains(node *head, int data)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            cout << "true" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "false" << endl;
}

void clear(node *head)
{
    node *temp = head;
    while (temp != NULL)
        head = NULL;
    temp->next = NULL;
    temp = temp->next;
}

void reverse(node *&head){
    node *previous = NULL;
    node *current = head;
    node *next = NULL;

    while(current!=NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
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

void deleteLast(node *&head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
        return;
    node *second = head;
    while (second->next->next != NULL)
        second = second->next;
    second->next = NULL;
}

void lastIndexOf(node *head, int data)
{
    node *current = head;
    int lastindex = 0;
    int count = 0;
    while (current != NULL)
    {
        if (current->data == data)
            lastindex = count;
        count++;
        current = current->next;
    }
    cout << lastindex << endl;
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
    deleteLast(head);
    printLL(head);
    cout<<size(head);
}