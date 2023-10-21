#include <iostream>

using namespace std;


struct BTNode
{
    int value;
    BTNode* left = nullptr;
    BTNode* right = nullptr;
};


class BinaryTree
{
private:
    BTNode* root;
public:
    BinaryTree();
    ~BinaryTree();
    void addNumber(int);
    void printInOrder();
    void printHeight();
    void printLeaves();
};


void makeTreeEmpty(BTNode*);
void addToTree(BTNode*, int);
void printTreeInOrder(BTNode*);
int getTreeHeight(BTNode*);
int getLeavesTree(BTNode*);






int main()
{
    int numNodes, number;
    char space;
    BinaryTree theTree;
    
    cout << "This program allows you to insert some numbers into a binary search tree.\n"
        << "Enter the number of nodes will be inserted into a BST: ";
    cin >> numNodes;
    cout << "Enter the value of " << numNodes << " nodes in one line, press enter key when done.\n"
        << "It displays out the numbers in the tree inorder.\n"
        << "It displays the number of leaves and height of the tree" << endl;
    for(int i = 0; i < numNodes; i++)
    {
        cin >> number;
        cin.get(space);
        theTree.addNumber(number);
    }
    
    cout << "Items in inorder are: " << endl;
    
    theTree.printInOrder();
    cout << endl;
    theTree.printHeight();
    theTree.printLeaves();
    
    return 0;
}






//constucts binary tree
BinaryTree::BinaryTree()
{
    root = nullptr;
}

//destructs binary tree by calling maketreeempty
BinaryTree::~BinaryTree()
{
    makeTreeEmpty(root);
}

//add number to tree
void BinaryTree::addNumber(int num)
{
    if (root == nullptr)
    {
        root = new BTNode;
        root->value = num;
    }
    else
        addToTree(root, num);
}

//prints tree in order
void BinaryTree::printInOrder()
{
    printTreeInOrder(root);
}

//prints height of tree
void BinaryTree::printHeight()
{
    cout << "Height of tree is: " << getTreeHeight(root) << endl;
}

//prints number of leaves in a tree
void BinaryTree::printLeaves()
{
    cout << "Number of leaves are: " << getLeavesTree(root) << endl;
}






//deletes every node in a tree, or subtree
void makeTreeEmpty(BTNode* root)
{
    if (root != nullptr)
    {
        makeTreeEmpty(root->left);
        makeTreeEmpty(root->right);
        delete root;
    }
}

//finds and the correct position and inserts number to tree
void addToTree(BTNode* root, int num)
{
    if(num < root->value)
    {
        if(root->left == nullptr)
        {
            root->left = new BTNode;
            root->left->value = num;
        }
        else
            addToTree(root->left, num);
    }
    else
    {
        if(root->right == nullptr)
        {
            root->right = new BTNode;
            root->right->value = num;
        }
        else
            addToTree(root->right, num);
    }
}

//prints a tree or sub tree in order
void printTreeInOrder(BTNode* root)
{
    if(root != nullptr)
    {
        printTreeInOrder(root->left);
        cout << root->value << " ";
        printTreeInOrder(root->right);
    }
}

//finds and returns tree height
int getTreeHeight(BTNode* root)
{
    int heightLeft, heightRight;
    if (root == nullptr)
        return 0;
    else
    {
        heightLeft = getTreeHeight(root->left);
        heightRight = getTreeHeight(root->right);
        if(heightLeft > heightRight)
            return heightLeft+1;
        else
            return heightRight+1;
    }
}

//finds an returns the number of leaves
int getLeavesTree(BTNode* root)
{
    if(root != nullptr)
    {
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        else
            return getLeavesTree(root->left) + getLeavesTree(root->right);
    }
    else
        return 0;
}
