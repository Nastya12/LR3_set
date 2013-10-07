#include "tree.h"
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

Tree::Tree():
    root(0)
{
}

void Tree::push (Node *&top, int data)
{
    if(top==0)
    {
        top=new Node;
        top->datum=data;
        top->count=1;
        top->left=0;
        top->right=0;
    }
    else if (data<top->datum)
    push(top->left, data);
    else if (data>top->datum)
    push(top->right, data);
    else top->count++;
}

Tree::Tree(int t):
    root(0)
{
    for (int i=0;i<t ;i++ )
    	push(root, rand()%10 -5);
}

void Tree::copyTree(Node *&rootnew, Node *rootold)
{
    if (rootold->left!=0)
    {
        push(rootnew, (rootold->left)->datum);
        copyTree(rootnew, rootold->left);
    }
    if (rootold->right!=0)
    {
        push(rootnew, (rootold->right)->datum);
        copyTree(rootnew, rootold->right);
    }
}

Tree::Tree (const Tree &ob)
{
    if (ob.root==0)
    root=0;
    else
    {
        root=new Node;
        root->datum=ob.root->datum;
        root->count=1;
        root->left=0;
        root->right=0;
        copyTree(root, ob.root);
    }
}

void Tree::deleteTree(Node *top)
{
    if (top->left!=0) deleteTree(top->left);
    if (top->right!=0) deleteTree(top->right);
    delete top;
}

Tree::~Tree()
{
    deleteTree(root);
}

void Tree::display(Node *top)
{
    if(top!=0)
    {
        display(top->left);
    cout<<"\n Number: "<<top->datum<<" - "<<top->count<<" kol-vo";
    display(top->right);
    }
}

Node *Tree::find (Node*top, int key)
{
    if(top==0)
    return 0;
    else if (key<top->datum) return find (top->left, key);
    else if (key>top->datum) return find (top->right, key);
    else return top;
}

void Tree::printLeaves( Node * top)
{
    if (top==0)
    return;
    else if ((top->left==0)&&(top->right==0))
    {
        cout<<"\n Number: "<< top->datum<<" - "<<top->count<<" kol-vo ";
    }
    else
    {
        printLeaves(top->left);
        printLeaves(top->right);
    }
}
void Tree::unite(Tree &A, Tree &B)
{
    Tree C;
    copyTree(C.root, A.root);
    if (C.root!=B.root)
    copyTree(C.root, B.root);
    C.display(C.root);
}

void Tree::intersection(Tree &A, Tree &B, Node *top)
{
    Tree C;
    if (B.find(B.root,top->datum)==A.find(A.root,top->datum));
    push(C.root, top->datum);
    C.display(C.root);
}
