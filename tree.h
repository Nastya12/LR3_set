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
    Node *root;
    void copySet(Node *&rootnew, Node *rootold);
    void deleteSet(Node *top);
    void unite(Node *top);
    void intersection(Node *top, Set &B,Set &C, Set &A);
    void intersection(Node*top,Set &C,Node*root);
    void push (Node *&top, int data);
    void display (Node *top);
    Node *find (Node *top, int key);
    Node* copyNode(Node *nd);
public:
    Set();
    Set(int t);
    Set (const Set &ob);
    ~Set();
    bool isEmpty()const;
    void push (int data);
    void display();
    int find (int key);
    Set unite(Set A);
    void intersection(Set &A, Set &B);
    Set&operator = (const Set &t);
};

#endif // TREE_H
