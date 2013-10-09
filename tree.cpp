#include "tree.h"
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

Set::Set():
    root(0)
{
}

void Set::push (Node *&top, int data)
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

void Set::push (int data)
{
    push(root, data);
}

Set::Set(int t):
    root(0)
{
    for (int i=0; i<t ; i++ )
        push(root, rand()%10 -5);
}

void Set::copySet(Node *&rootnew, Node *rootold)
{
    if (rootold->left!=0)
    {
        push(rootnew, (rootold->left)->datum);
        copySet(rootnew, rootold->left);
    }
    if (rootold->right!=0)
    {
        push(rootnew, (rootold->right)->datum);
        copySet(rootnew, rootold->right);
    }
}

Set::Set (const Set &ob)
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
        copySet(root, ob.root);
    }
}

void Set::deleteSet(Node *top)
{
    if (top->left!=0) deleteSet(top->left);
    if (top->right!=0) deleteSet(top->right);
    delete top;
}

Set::~Set()
{
    deleteSet(root);
}

void Set::display(Node *top)
{
    if(top!=0)
    {
        display(top->left);
        cout<<"\n Number: "<<top->datum<<" - "<<top->count<<" kol-vo";
        display(top->right);
    }
}

void Set::display()
{
    display(root);
}

Node *Set::find (Node*top, int key)
{
    if(top==0)
        return 0;
    else if (key<top->datum) return find (top->left, key);
    else if (key>top->datum) return find (top->right, key);
    else return top;
}

int Set::find (int key)
{
    Node *top=find(root,key);
    if (top) return top->count;
    else return 0;
}
bool Set::isEmpty() const
{
    return root==0;
}

Set Set::unite(Set A)
{
    Set C;
    C.root=C.copyNode(root);
    C.unite(A.root);
    return C;
}

void Set::unite(Node *top)
{
    if (!top)
        return;
    push(root, top->datum);
    unite(top->right);
    unite(top->left);
}
void Set::intersection(Set &A, Set &B)
{
    Set C;
    intersection(root,C,B, A);
    intersection(B.root,C,root);
}

void Set::intersection(Node *top, Set &C, Set &B, Set &A)
{
    if (!top)
    return;
        intersection(top->right,C,B, A);
        if (B.find(root,top->datum)==A.find(root,top->datum))
            push(C.root, top->datum);
        intersection(top->left,C, root);

}

void Set::intersection(Node*top,Set &C,Node*root)
{
    if(top!=0)
    {
        intersection(top->left,C,root);
        if(find(root,top->datum)!=0)
            push(C.root,top->datum);
        intersection(top->right,C,root);
    }
}
Set& Set::operator= (const Set &t)
{
    if(this==&t) return *this;
    deleteSet(root);
    copySet(root,t.root);
    return *this;
}

Node* Set::copyNode(Node *nd)
{
    if (!nd)
        return NULL;
    Node *Nd=new Node;
    Nd->datum=Nd->datum;
    Nd->count=Nd->count;
    Nd->left=copyNode(Nd->left);
    Nd->right=copyNode(Nd->right);
    return Nd;
}

