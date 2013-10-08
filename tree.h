#ifndef TREE_H
#define TREE_H

struct Node
{
    int datum;
    Node *left, *right;
    int count;
};

class Set
{
    void copySet(Node *&rootnew, Node *rootold);
    void deleteSet(Node *top);
public:
    Node *root;
    Set();
    Set(int t);
    Set (const Set &ob);
    ~Set();
    void push (Node *&top, int data);
    void display (Node *top);
    Node *find (Node *top, int key);
    void printLeaves (Node*top);
    void unite(Set &A, Set &B);
    void unite(Node *top, Set &C);
    void intersection(Set &A, Set &B);
    void intersection(Node *top, Set &B,Set &C, Set &A);
    void Set::intersection(Node*top,Set &C,Node*root);
    Set&operator = (const Set &t);
    void insert(int data);
    void unite(Node* root1, Node* root2);
    // bool operator == (const Set &leftt, int rightt);
};

#endif // TREE_H
