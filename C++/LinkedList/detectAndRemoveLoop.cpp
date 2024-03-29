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

void insert(node *&head, int data)
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

void detectAndRemoveLoop(node *head)
{

    node *first = head;
    node *second = head;

    while (first != NULL and second != NULL and second->next != NULL)
    {
        first = first->next;
        second = second->next->next;
        if (first == second)
        {
            cout << "true" << endl;
            first = head;

            while (first->next != second->next)
            {
                first = first->next;
                second = second->next;
            }
            second->next = NULL;
            return;
        }
    }
    cout << "false" << endl;
}

void firstElementOfTheLoop(node *head){
    node *first = head;
    node *second = head;
    // node *third = head;

    while(first != NULL and second!= NULL and second->next != NULL){
        first = first->next;
        second = second->next->next;

        if(first==second){

            first = head;

            while(first->next != second->next){
                first =first->next;
                second = second->next;
            }
            cout<<first->next->data<<endl;
            return;
        }
        // third = third->next;
    }
    cout<<"Loop dose not exist"<<endl;
}

void reverse(node *head)
{
    node *previous = NULL;
    node *current = head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    // head->next->next->next->next->next = head;
    head->next->next->next->next->next = head->next;
    // detectAndRemoveLoop(head);
    // detectAndRemoveLoop(head);
    firstElementOfTheLoop(head);
    // reverse(head);
    // printLL(head);
}