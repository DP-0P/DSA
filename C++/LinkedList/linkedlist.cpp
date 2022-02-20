#include <iostream>
#include <limits.h>
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
        if (current->data == data)
        {
            if (current->next == NULL)
            {
                previous->next = NULL;
                return;
            }
            else if (current->next != NULL)
            {
                current->data = current->next->data;
                current->next = current->next->next;
                return;
            }
        }
        previous = current;
        current = current->next;
    }
}

void deleteAll(node *head, int data)
{
    node *previous = NULL;
    node *current = head;
    while (current != NULL)
    {
        while (current->data == data)
        {
            if (current->next == NULL)
            {
                previous->next = NULL;
                return;
            }
            else if (current->next != NULL)
            {
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

void reverse(node *&head)
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

void sort012(node *head)
{

    int count[] = {0, 0, 0};

    node *temp = head;

    while (temp != NULL)
    {
        count[temp->data]++;
        temp = temp->next;
    }

    int i = 0;
    temp = head;

    while (temp != NULL)
    {
        if (count[i] == 0)
            i++;

        else
        {
            temp->data = i;
            count[i]--;
            temp = temp->next;
        }
    }
}

void removeDuplicatesSorted(node *head)
{
    node *current = head;

    while (current != NULL)
    {
        node *temp = current;

        while (temp != NULL && temp->data == current->data)
            temp = temp->next;

        current->next = temp;
        current = current->next;
    }
}

void removeDuplicatesUnsorted(node *head)
{
    node *ptr1 = NULL;
    node *ptr2 = NULL;
    node *dup = NULL;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

node *copyList(node *&head)
{
    node *temp = head;
    node *newList = NULL;
    node *tail = NULL;

    while (temp != NULL)
    {
        if (newList == NULL)
        {
            newList->data = temp->data;
            newList->next = NULL;
            tail = newList;
        }
        else
        {
            tail = tail->next;
            tail->data = temp->data;
            tail->next = NULL;
        }
        temp = temp->next;
    }
    return newList;
}

// node *sortedIntersect(node *head1, node *head2)
// {
//     node dummy = NULL;
//     node *tail = &dummy;
//     dummy.next = NULL;

//     while (head1 != NULL && head2 != NULL)
//     {
//         if (head1->data == head2->data)
//         {
//             insertBack((tail->next), head1->data);
//             tail = tail->next;
//             head1 = head1->next;
//             head2 = head2->next;
//         }
//         else if (head1->data < head2->data)
//             head1 = head1->next;
//         else
//             head2 = head2->next;
//     }
//     return dummy.next;
// }

void compute(node *head)
{
    int previous = INT_MIN;
    node *temp = head;

    while (temp != NULL)
    {
        previous = temp->data; // 1
        temp = temp->next;     // temp = 2
        if (temp->data > previous)
            deleteLL(head, previous);
        else
            previous = temp->data;
    }
}

void nthNodeFromEnd(node *head, int n)
{
    int length = 0;
    node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }

    if (length < n)
        cout << "Length can't be smaller than the searched index." << endl;

    temp = head;

    for (int i = 1; i < length - n + 1; i++)
        temp = temp->next;

    cout << temp->data;
}

//not working
node *reverseReturn(node *head)
{
    node *cur = head;
    node *prev = NULL;
    node *next;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

//not working
bool isPalindrome(node *&head)
{
    if (head == NULL or head->next == NULL)
        return true;

    node *fast = head;
    node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseReturn(slow->next);
    slow = slow->next;

    while (slow != NULL)
    {
        if (head->data != slow->data)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

long long multi(node *l1, node *l2)
{
    if (l1 == NULL or l2 == NULL)
        return NULL;

    long long a, b, mod;
    mod = 1000000007;
    a = 0;
    b = 0;

    while (l1)
    {
        a = (a * 10 + l1->data) % mod;
        l1 = l1->next;
    }

    while (l2)
    {
        b = (b * 10 + l2->data) % mod;
        l2 = l2->next;
    }

    return (a * b) % mod;
}

int main()
{
    node *head = NULL;
    insertBack(head, 1);
    insertBack(head, 2);
    insertBack(head, 3);
    insertBack(head, 3);
    insertBack(head, 4);
    insertBack(head, 4);
    insertBack(head, 5);
    insertBack(head, 5);
    printLL(head);
    removeDuplicatesSorted(head);
    printLL(head);
    // node *head1 = NULL;
    // insertBack(head1, 1);
    // insertBack(head1, 2);
    // insertBack(head1, 3);
    // insertBack(head1, 4);
    // insertBack(head1, 5);
    // printLL(head1);
    // cout<<multi(head,head1);
    // cout << isPalindrome(head);
    // nthNodeFromEnd(head, 2);
    // node *tail = NULL;
    // insertBack(tail,5);
    // insertBack(tail, 6);
    // insertBack(tail, 7);
    // insertBack(tail, 8);
    // insertBack(tail, 9);

    // node *temp = sortedIntersect(head,tail);
    // printLL(head);
    // removeDuplicatesSorted(head);
    // removeDuplicatesUnsorted(head);
    // printLL(head);
    // deleteLast(head);
    // printLL(head);
    // cout<<size(head);
    // insertBack(head, 1);
    // insertBack(head, 2);
    // insertBack(head, 0);
    // insertBack(head, 0);
    // insertBack(head, 2);
    // insertBack(head, 1);
    // insertBack(head, 0);
    // insertBack(head, 2);
    // insertBack(head, 1);

    // sort012(head);
    // printLL(head);
    // compute(head);
    // printLL(head);

    // printLL(temp);
    // node *copy = copyList(head);
    // reverse(copy);
    // printLL(tail);
}