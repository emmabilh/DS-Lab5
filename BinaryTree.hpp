// Emma Bilhimer
// BUSCH SP24
// Lab Name: Binary Tree Lab
// Due April 1, 2024
/* Description: Create a binary tree class which will take strings of website names and sort
 them in alphabetical order. Your class should also be able to sort them in reverse
 alphabetical order as well.
 o Class Name: BiTree
 ▪ Methods:
 • Add: Add a new item to the tree
 • Remove: Remove an item from the tree
 • Print: Print the contents of the tree in alphabetical order
 • TPrint: Print the contents of the tree in a tree format
 • RPrint: Print the contents of the tree in reverse alphabetical
 order.
 • Add other methods as needed.
*/

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

struct TreeNode
{
    int info;
    TreeNode* left;
    TreeNode* right;
};

class BiTree
{
public:
    BiTree();
    ~BiTree();

    void MakeEmpty(); 
    bool IsEmpty();
    void Add(int item);
    void Remove(int item);
    void PrintTree();
    void TPrint();
    void RPrint();

private:
    TreeNode* root;

    void FindLoc(TreeNode* tree, int item, bool& found);
    TreeNode* DeleteNode(TreeNode* tree, int item);
    TreeNode* FindMin(TreeNode* tree);
    void AddItem(TreeNode*& tree, int item);
    void InOrderTraversal(TreeNode* tree);
    void ReverseOrderTraversal(TreeNode* tree);
};

#endif 


