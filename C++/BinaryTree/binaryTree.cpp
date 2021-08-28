#include <iostream>
#include <stack>
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

// node *root = NULL;

void inorder(node *root) //Left Root Right
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root) // Root Left Right
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) // Left Right Root
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorderIterative(node *root)
{
    stack<node *> tree;
    node *current = root;

    while (current != NULL || tree.size() > 0)
    {
        while (current != NULL)
        {
            tree.push(current);
            current = current->left;
        }
        current = tree.top();
        tree.pop();
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

void preorderIterative(node *root)
{
}

void postorderIterative(node *root)
{
}

int heightOfTree(node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = heightOfTree(root->left);
    int rHeight = heightOfTree(root->right);

    if (lHeight > rHeight)
        return lHeight + 1;
    return rHeight + 1;
}

int diameter(node *root){
    if(root == NULL)
        return 0;

    int lHeight = heightOfTree(root->left);
    int rHeight = heightOfTree(root->right);

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max(lHeight + rHeight + 1, max(lDiameter,rDiameter));
}

int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    // cout << "Tree traversal using recursion - " << endl;
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // cout << "Tree traversal using iteration - " << endl;
    // inorderIterative(root);
    // preorderIterative(root);
    // postorderIterative(root);

    // cout << heightOfTree(root) << endl;
    cout<<diameter(root)<<endl;


}