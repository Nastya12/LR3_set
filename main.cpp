#include <iostream>
#include <stdlib.h>
#include "tree.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Tree tr(12), C;
    Node *u;
    int a, a1,a2, a3,A1,B1;
    int data;
    cout<<" \n Set \n";
    cout<<" Create set of A.\n";
    cout<<"enter number of elements of the set A.\n";
    cin>>A1;
    Tree A(A1);
    cout<<"\n Create set of B.\n";
    cout<<"enter number of elements of the set B.\n";
    cin>>B1;
    Tree B(B1);
    do
    {
        cout<<"\n\n Menu: \n";
        cout<<" 1 -> push element. \n";
        cout<<" 2 -> find. \n";
        cout<<" 3 -> unite. \n";
        cout<<" 4 -> intersection. \n";
        //cout<<" 5 -> difference two sets.\n";
        cout<<" 6 -> display set. \n";
        cout<<" 7 -> display leaves. \n";
        //cout<<" 8 -> create two sets.\n ";
        cout<<" 0 -> exit. \n";
        cout<<" action=";
        cin>>a;
        if (a>=0)
            switch(a)
            {
            case 1:
            {
                cout<<"     1 -> push in A:\n";
                cout<<"     2 -> push in B:\n";
                cout<<"action=";
                cin>>a1;
                if (a1>0)
                    switch(a1)
                    {
                    case 1:
                    {
                        cout<<"Enter number= \n";
                        cin>>data;
                        A.push(A.root,data);
                    }
                    break;
                    case 2:
                    {
                        cout<<"Enter number= \n";
                        cin>>data;
                        B.push(B.root,data);
                    }
                    break;
                    }
            }
            break;
            case 2:
            {
                cout<<"     1 -> find in A:\n";
                cout<<"     2 -> find in B:\n";
                cout<<"action=";
                cin>>a2;
                if (a2>0)
                    switch(a2)
                    {
                    case 1:
                    {
                        if (A.root==0)
                            cout<<" Set A is empty.\n";
                        else
                        {
                            int key;
                            cout<<" Enter the required number: ";
                            cin>>key;
                            if ((u=A.find(A.root,key))!=0)
                            {
                                cout<<"Elements: ";
                                cout<<key;
                                cout<<" finded ";
                                cout<<u->count<<" kol-vo \n";
                            }
                            else cout<<" Same elements is not find.\n";
                        }
                    }
                    break;
                    case 2:
                    {
                        if (B.root==0)
                            cout<<" Set B is empty.\n";
                        else
                        {
                            int key;
                            cout<<" Enter the required number: ";
                            cin>>key;
                            if ((u=B.find(B.root,key))!=0)
                            {
                                cout<<"Elements: ";
                                cout<<key;
                                cout<<" finded ";
                                cout<<u->count<<" kol-vo \n";
                            }
                            else cout<<" Same elements is not find.\n";
                        }
                    }
                    break;
                    }
            }
            break;
            case 3:
            {
                Tree C;
                C.unite(A,B);
            }break;
            case 4:
            {
                Tree C;
                C.intersection(A,B, C.root);
            }
            case 6:
            {
                cout<<"     1 -> display A:\n";
                cout<<"     2 -> display B:\n";
                cout<<"action=";
                cin>>a3;
                if (a1>0)
                    switch(a3)
                    {
                    case 1:
                    {
                        if (A.root==0) cout<<"Set A is empty.\n";
                        else
                        {
                            cout<<" Set A \n";
                            A.display(A.root);
                        }
                    }
                    break;
                    case 2:
                    {
                        if (B.root==0) cout<<"Set B is empty.\n";
                        else
                        {
                            cout<<" Set B \n";
                            B.display(B.root);
                        }
                    }
                    break;
                    }
            }
            break;
            case 7:
            {
                if (tr.root==0) cout<<"Tree is empty.\n";
                else
                {
                    cout<<" Leaves \n";
                    tr.printLeaves(tr.root);
                }
            }
            break;
            case 0:
                break;
            default:
                cout<<"error: incorrect action \n";
            }
    }
    while (a);
    return 0;
}
