#include "AVLTree.h"
#include <iostream>

using namespace std;

void clearTree(AVLNode*);
AVLNode* AVLAddToTree(AVLNode*, int);
AVLNode* reBalance(AVLNode*);
int getBalance(AVLNode*);
int getHeight(AVLNode*);
void reHeight(AVLNode*);
AVLNode* rightShift(AVLNode*);
AVLNode* leftShift(AVLNode*);
void printTree(AVLNode*, int);
void printTreeInOrder(AVLNode*);
void printTreePreOrder(AVLNode*);


AVL::AVL()
{
    root = nullptr;
}

AVL::~AVL()
{
    clearTree(root);
}

void AVL::addNumber(int num)
{
    if(root == nullptr)
    {
        root = new AVLNode;
        root->value = num;
        root->height = 0;
    }
    else
    {
        root = AVLAddToTree(root, num);
    }
}

void AVL::print()
{
    printTree(root, 0);
}

void AVL::printInOrder()
{
    cout << "Inorder: {";
    printTreeInOrder(root);
    cout << "}" << endl;
}

void AVL::printPreOrder()
{
    cout << "PreOrder: {";
    printTreePreOrder(root);
    cout << "}" << endl;
}


void clearTree(AVLNode* node)
{
    if(node != nullptr)
    {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

AVLNode* AVLAddToTree(AVLNode* node, int num)
{
    if(num < node->value)
    {
        if(node->left == nullptr)
        {
            node->left = new AVLNode;
            node->left->value = num;
            node->left->parent = node;
            node->left->height = 0;
            node->left->isRightChild = false;
        }
        else
            node = AVLAddToTree(node->left, num);
    }
    else
    {
        if(node->right == nullptr)
        {
            node->right = new AVLNode;
            node->right->value = num;
            node->right->parent = node;
            node->right->height = 0;
            node->right->isRightChild = true;
        }
        else
            node = AVLAddToTree(node->right, num);
    }
    
    node = reBalance(node);
    
    return node;
}

AVLNode* reBalance(AVLNode* node)
{
    int balance = getBalance(node);
    if(balance == 2)
    {
        if(getBalance(node->left) == -1)
        {
            leftShift(node->left);
        }
        node = rightShift(node);
    }
    else if (balance == -2)
    {
        if(getBalance(node->right) == 1)
        {
            rightShift(node->right);
        }
        node = leftShift(node);
    }
    else
        reHeight(node);
    
    if(node->parent != nullptr)
        node = reBalance(node->parent);
        
    
    return node;
}

int getBalance(AVLNode* node)
{
    return getHeight(node->left) - getHeight(node->right);
}

int getHeight(AVLNode* node)
{
    if(node == nullptr)
        return -1;
    else
        return node->height;
}

void reHeight(AVLNode* node)
{
    int leftHeight, rightHeight;
    
    leftHeight = getHeight(node->left);
    rightHeight = getHeight(node->right);
    
    if(leftHeight > rightHeight)
        node->height = leftHeight+1;
    else
        node->height = rightHeight+1;
}

AVLNode* rightShift(AVLNode* node)
{
    AVLNode *newNode = node->left, *tempNode = newNode->right, *tempParent = node->parent;
    
    newNode->right = node;
    node->left = tempNode;
    node->parent = newNode;
    newNode->parent = tempParent;
    newNode->isRightChild = node->isRightChild;
    node->isRightChild = true;
    
    if(newNode->parent != nullptr)
    {
        if(newNode->isRightChild)
            newNode->parent->right = newNode;
        else
            newNode->parent->left = newNode;
    }
    
    reHeight(node);
    reHeight(newNode);
    return newNode;
}

AVLNode* leftShift(AVLNode* node)
{
    AVLNode *newNode = node->right, *tempNode = newNode->left, *tempParent = node->parent;
    
    newNode->left = node;
    node->right = tempNode;
    node->parent = newNode;
    newNode->parent = tempParent;
    newNode->isRightChild = node->isRightChild;
    node->isRightChild = false;
    
    if(newNode->parent != nullptr)
    {
        if(newNode->isRightChild)
            newNode->parent->right = newNode;
        else
            newNode->parent->left = newNode;
    }
    
    reHeight(node);
    reHeight(newNode);
    return newNode;
}

void printTree(AVLNode* node, int i)
{
    if(node != nullptr)
    {
        printTree(node->right, i+3);
        
        for(int j = 0; j<i;j++)
            cout << "\t";
        if(node->parent == nullptr)
            cout << "Root ";
        cout << node->value << "<" << endl;
        
        printTree(node->left, i+3);
    }
}

void printTreeInOrder(AVLNode* node)
{
    if(node != nullptr)
    {
        printTreeInOrder(node->left);
        cout << node->value << ", ";
        printTreeInOrder(node->right);
    }
}

void printTreePreOrder(AVLNode* node)
{
    if(node != nullptr)
    {
        cout << node->value << ", ";
        printTreePreOrder(node->left);
        printTreePreOrder(node->right);
    }
}
