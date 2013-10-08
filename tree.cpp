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

Node *Set::find (Node*top, int key)
{
    if(top==0)
        return 0;
    else if (key<top->datum) return find (top->left, key);
    else if (key>top->datum) return find (top->right, key);
    else return top;
}


void Set::printLeaves( Node * top)
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
void Set::unite(Set &A,Set &B)
{
    Set C;
    unite(root,C);
    unite(B.root,C);
}

void Set::unite(Node *top, Set &C)
{
    if (top!=0)
    {
        unite(top->right,C);
        push(C.root, top->datum);
        unite(top->left,C);
    }
}
void Set::intersection(Set &A, Set &B)
{
    Set C;
    intersection(root,C,B, A);
    intersection(B.root,C,root);
}

void Set::intersection(Node *top, Set &C, Set &B, Set &A)
{
    if (top!=0)
    {
        intersection(top->right,C,B, A);
        if (B.find(root,top->datum)==A.find(root,top->datum))
            push(C.root, top->datum);
        intersection(top->left,C, root);
    }
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


/*void Set::unite(Node* root1, Node* root2)
{
    if(root1->left!=NULL) unite(root1->left, root2);
    insert(root1->datum);
    if(root1->right!=NULL) unite(root1->right, root2);

    //delete root1;
    //root1=NULL;
}*/

/*void Set::insert(int data)
{
    if (root==0)
    {
        root=new Node;
        return;
    }
    else
    {
        int result;
        Node *p,*n=root;
        while (n)
        {
            p=n;
            result=(data, p->datum);
            if(result<0)
                n=p->left;
            else if(result>0)
                n=p->right;
            else return;
        }
        if (result<0)
            p->left=new Node;
        else
            p->right=new Node;

    }
}*/

