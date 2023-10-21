#include "AVLTree.h"
#include <iostream>

using namespace std;

void choiceA(AVL*);
void choiceB(AVL*);


int main()
{
    AVL Tree;
    char choice = 'd';
    
    while(choice!='c' && choice!='C')
    {
        cout << "AVL Tree Implementation\n"
            << "A.Insert an integer to tree and show the balanced tree at each insertion\n"
            << "B.Display the balanced tree and show inorder and preorder traversal\n"
            << "C.Exit\n= ";
        
        cin >> choice;
        cin.clear();
        cin.ignore(180, '\n');
        
        switch(choice)
        {
            case 'A':
            case 'a':
                choiceA(&Tree);
                break;
            case 'B':
            case 'b':
                choiceB(&Tree);
                break;
            case 'C':
            case 'c':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Not a valid input please try again. " << endl;
        }
    }
    
    return 0;
}


void choiceA(AVL* Tree)
{
    int num;
    cout << "Enter integer to be added to tree: ";
    cin >> num;
    
    Tree->addNumber(num);
    cout << endl;
    Tree->print();
    cout << endl;
}

void choiceB(AVL* Tree)
{
    cout << endl;
    Tree->print();
    cout << endl;
    Tree->printInOrder();
    Tree->printPreOrder();
    cout << endl;
}
