#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
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

void inorderIterative(node *root){
    if(root==NULL)
        cout<<"NULL"<<endl;

    stack<node *> st;
    node *current = root;

    while (true){
        if(current){
            st.push(current);
            current = current->left;
        }
        else{
            if(st.empty())
                break;
            current = st.top();
            st.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
    cout << endl;
}

void preorderIterative(node *root){
    if(root==NULL)
        cout<<"NULL"<<endl;

    stack<node *> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        cout<<root->data<<" ";
        if(root->right)
            st.push(root->right);
        
        if(root->left)
            st.push(root->left);
    }
}

void postorderIterativeTwoStack(node *root){
    if(root==NULL)
        cout<<"NULL"<<endl;
    
    stack<node *> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left)
            st1.push(root->left);
        if(root->right)
            st1.push(root->right);
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

void postorderIterativeOneStack(node *root){
    if(root==NULL)
        cout<<"NULL"<<endl;
    
    node *pre = NULL;
    stack<node *> st;
    while(root or !st.empty()){
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            root = st.top();
            if(root->right==NULL or root->right==pre){
                cout<<root->data<<" ";
                st.pop();
                pre = root;
                root = NULL;
            }
            else
                root = root->right;
        }
    }
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int heightOfTree(node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = heightOfTree(root->left);
    int rHeight = heightOfTree(root->right);

    return 1 + max(lHeight,rHeight);
}

int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = heightOfTree(root->left);
    int rHeight = heightOfTree(root->right);

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

void leftView(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    leftView(root->left);
}

void rightView(node *root)
{
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    rightView(root->right);
}

node* mirrorOfTree(node *root){
    if(root == NULL)
        return root;
    
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    if(root->left != NULL)
        mirrorOfTree(root->left);
    if(root->right != NULL)
        mirrorOfTree(root->right);
    
    return root;
}

int convertToSumTree(node *root){
    if(root == NULL)
        return 0;

    int old = root->data;

    root->data = convertToSumTree(root->left) + convertToSumTree(root->right);

    return root->data + old;
}

bool isBalanced(node *root,int *height){
    int lh=0;
    int rh=0;
    int l=0;
    int r=0;

    if(root == NULL){
        *height = 0;
        return 1;
    }

    l = isBalanced(root->left,&lh);
    r = isBalanced(root->right,&rh);

    *height = (lh>rh ? lh:rh) + 1;

    if(abs(lh-rh)>=2)
        return 0;
    
    else
        return l and r;
}

node *lca(node *root,int n1,int n2){
    if(root == NULL)
        return NULL;
    
    if(root->data == n1 || root->data == n2)
            return root;
        
    node *left = lca(root->left,n1,n2);
    node *right = lca(root->right,n1,n2);
        
    if(left and right)
        return root;
        
    return (left != NULL) ? left : right;
}

bool sameLevel(node *root,int level,int *leaf){
    if(root == NULL)
        return true;
    
    if(root->left == NULL and root->right == NULL){
        if(*leaf == 0){
            *leaf = level;
            return true;
        }
        return (level == *leaf);
    }
    return sameLevel(root->left, level + 1, leaf) and sameLevel(root->right, level + 1, leaf);
}

int maxPathDown(node *nodee,int &maxim){
    if(nodee == NULL)
        return 0;
    
    int left = max(0,maxPathDown(nodee->left,maxim));
    int right = max(0,maxPathDown(nodee->right,maxim));
    maxim = max(maxim,left+right+nodee->data);
    return max(left,right)+nodee->data;
}

int maxPathSum(node *root){
    int maxim = INT_MIN;
    maxPathDown(root,maxim);
    return maxim;
}

bool isIdentical(node *root1,node *root2){
    if(root1 == NULL or root2 == NULL)
        return root1==root2;
    
    return root1->data == root2->data and isIdentical(root1->left,root2->left) and isIdentical(root1->right,root2->right);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    //cout<<maxPathSum(root);
    // node *root1 = new node(1);
    // root1->left = new node(2);
    // root1->right = new node(3);
    // root1->left->left = new node(4);
    // root1->left->right = new node(5);
    // root1->right->left = new node(6);
    // cout << isIdentical(root,root1);
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
    // postorderIterativeOneStack(root);
    // cout<<endl;
    // postorderIterativeTwoStack(root);
    // cout << heightOfTree(root) << endl;
    // cout<<diameter(root)<<endl;
    // levelOrderTraversal(root);
    // rightView(root);
    // inorder(root);
    // cout<<endl;
    // mirrorOfTree(root);
    // convertToSumTree(root);
    // inorder(root);
    // int h=0;
    // cout<<isBalanced(root,&h);
    // node *lcaa = lca(root,2,3);
    // cout<<lcaa->data;
    // int level = 0;
    // int leaf = 0;
    // cout<<sameLevel(root,level,&leaf);
}