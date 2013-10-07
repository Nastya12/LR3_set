#ifndef TREE_H
#define TREE_H

struct Node
{
    int datum;
    Node *left, *right;
    int count;
};

class Tree
{
    public:
        Node *root;
        Tree();
        Tree(int t); // рандомная матрица
        void copyTree(Node *&rootnew, Node *rootold);
        Tree(const Tree &ob); // копирование
        void deleteTree(Node *top);
        ~Tree();
        void push (Node *&top, int data); //вставка элемента
        void display (Node *top);// вывод дерева на экран
        Node *find (Node *top, int key); //поиск по ключу
        void printLeaves (Node*top); // вывод листьев на экран
        void unite(Tree &A, Tree &B);
        void intersection(Tree &A, Tree &B, Node *top);
};

#endif // TREE_H
