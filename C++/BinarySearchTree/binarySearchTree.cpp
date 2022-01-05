#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int val)
{

    if (root == NULL)
    {
        root = new node(val);
        return root;
    }

    if (val < root->data)
        root->left = insert(root->left, val);

    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

bool search(node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        search(root->left, key);

    else if (key > root->data)
        search(root->right, key);
}

void deleteNode(node *root,int key){
    if(root==NULL)
        return;
    
    node* current = root;
    node* previous = NULL;

    if(key<root->data)
        deleteNode(root->left,key);
    
    else if(key>root->data)
        deleteNode(root->right,key);

    
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int min(node *root)
{
    if (root == NULL)
        return -1;
    
    node *current = root;
    while (current->left!=NULL)
        current = current->left;
    
    return current->data;
}

int max(node *root)
{
    if (root == NULL)
        return -1;
    
    node *current = root;
    while (current->right!=NULL)
        current = current->right;
    
    return current->data;
}

bool bstCheck(node *root,node *left,node *right){
    if(root == NULL)
        return true;
    
    if(left!=NULL && root->data<=left->data)
        return false;

    if(right!=NULL && root->data>=right->data)
        return false;
    
    return bstCheck(root->left,left,root) && bstCheck(root->right,root,right);
}

int main()
{
    node *root = new node(71);
    // node *root = NULL;
    root = insert(root, 65);
    root = insert(root, 84);
    root = insert(root, 69);
    root = insert(root, 67);
    root = insert(root, 83);
    // root = insert(root, 80);

    // node *root = new node(3);
    // root->left = new node(2);
    // root->right = new node(5);
    // root->left->left = new node(1);
    // root->left->right = new node(4);

    inorder(root);

    // cout << search(root, 80);

    // cout << max(root);

    // cout<<min(root);

    // cout<<bstCheck(root,NULL,NULL);
}





                            
