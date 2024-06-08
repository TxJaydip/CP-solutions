#include "bits/stdc++.h"
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *head)
{
    if (head == NULL)
    {
        return;
    }
    inorder(head->left);
    cout << head->val << " ";
    inorder(head->right);
    return;
}

void preorder(node *head)
{
    if (head == NULL)
    {
        // cout << endl;
        return;
    }
    cout << head->val << " ";
    preorder(head->left);
    preorder(head->right);

    return;
}

void postOrder(node *head)
{
    if (head == NULL)
    {
        // cout<<endl;
        return;
    }
    postOrder(head->left);
    postOrder(head->right);
    cout << head->val << " ";
    return;
}

int main()
{
    node *head = new node(5);
    head->left = new node(3);
    head->right = new node(7);

    head->left->left = new node(8);
    head->left->right = new node(9);

    head->right->left = new node(11);
    head->right->right = new node(4);

    /*

             5
           /   \
          3     7
         / \   / \
        8  9  11  4
    */
    cout << "Inorder: ";
    inorder(head);

    cout << "\nPreorder: ";
    preorder(head);

    cout << "\nPostOrder: ";
    postOrder(head);

    return 0;
}