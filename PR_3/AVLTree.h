#ifndef AVLTree_h
#define AVLTree_h

struct AVLNode
{
    int value, height;
    bool isRightChild;
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    AVLNode* parent = nullptr;
    
};

class AVL
{
private:
    AVLNode* root;
public:
    AVL();
    ~AVL();
    void addNumber(int);
    void print();
    void printInOrder();
    void printPreOrder();
};

#endif
