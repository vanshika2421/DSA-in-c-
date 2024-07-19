#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *NewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return (newNode);
}

// fiing height of tree
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}

void printGivenNodes(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->data;
    }
    else if (level > 1)
    {
        printGivenNodes(root->left, level - 1);
        printGivenNodes(root->right, level - 1);
    }
}

void reverse(Node *root)
{
    int h = height(root);
    // cout << h << endl;
    int i;
    for (i = h; i >= 1; i--)
    {
        cout << endl;
        printGivenNodes(root, i);
    }
}

void buildTree(Node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        cout << endl;
        printGivenNodes(root, i);
    }
}

void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node *root)
{ // NLR
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    //  cout << root -> data << " ";
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}

int diameter(Node *root)
{
    // int max = INT_MIN;
    if (root == NULL)
    {
        return 1;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);
    int ans = max(op1, max(op2, op3));
    return ans;
}

void buildFromLevelOrder(Node *root)
{
    queue<Node *> q;
    cout << " enter data for root" << endl;
    int data;
    cin >> data;
    root = NewNode(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << " enter data for left root : " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = NewNode(leftData);
            q.push(temp->left);
        }

        cout << " enter data for right root" << temp->data << endl;
        ;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = NewNode(rightData);
            q.push(temp->right);
        }
    }
}

pair<bool, int> isBtree(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    else
    {

        pair<bool, int> left = isBtree(root->left);
        pair<bool, int> right = isBtree(root->right);
        bool lefty = left.first;
        bool rigthy = right.first;
        bool x = abs(left.second - right.second) <= 1;
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if (x && lefty && rigthy)
        {
            ans.first = true;
        }
        else
        {
            ans.second = false;
        }
        return ans;
    }
}

bool isBalanced(Node *root)
{
    return isBtree(root).first;
}

int main()
{

    Node *root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right->left = NewNode(6);
    // cout << "building tree: " ;
    // buildTree(root);cout << endl;
    // cout << "-----------------------" << endl;
    // cout << "Reversing tree : " ;
    // reverse(root); cout << endl;
    // cout << "-----------------------" << endl;
    // cout << "Inorder trvaersal tree : ";
    // inorder(root); cout << endl;
    // cout << "preorder trvaersal tree : ";
    // preOrder(root); cout << endl;
    // cout << "postorder trvaersal tree : ";
    // postorder(root); cout << endl;
    // cout << "-----------------------" << endl;
    // // buildFromLevelOrder(root);
    // // printGivenNodes(root,3);
    // cout << "-----------------------" << endl;
    cout << " Longest diameter : " << " ";
    cout << diameter(root) << endl;

    // cout << "-----------------------" << endl;
    cout << " height of tree : " << " ";
    cout << height(root) << endl;
    // cout << "-----------------------" << endl;
    cout << " is a balnced tree : " << " ";
    cout << isBalanced(root) << endl;
}
