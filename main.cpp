//
//  main.cpp
//  BinaryTree

#include "BinaryTree.hpp"
#include <iostream>
#include <stack>

// this section of code is the data for the binary tree

int main() {
    BiTree tree;

    // adding rando numbers to the tree
    tree.Add(50);
    tree.Add(30);
    tree.Add(70);
    tree.Add(20);
    tree.Add(40);
    tree.Add(60);
    tree.Add(80);

    // printing the tree
    std::cout << "In alphabetical order: ";
    tree.PrintTree(); // alphabetical order
    
    std::cout << "In tree format: " << std::endl;
    tree.TPrint();    // printing in tree
    
    std::cout << "In reverse alphabetical order: ";
    tree.RPrint();    // reverse alphabetical order

    // remove an item from the tree
    tree.Remove(30);

    // printing the tree after remove
    std::cout << "After removing 30, ";
    tree.TPrint(); // Printing in tree format

    return 0;
}


// create a new tree node
TreeNode* NewNode(int item) {
    TreeNode* temp = new TreeNode();
    temp->info = item;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

// add a new item to the tree
void AddItem(TreeNode*& tree, int item) {
    if (tree == nullptr) {
        tree = NewNode(item);
    } else if (item < tree->info) {
        AddItem(tree->left, item);
    } else if (item > tree->info) {
        AddItem(tree->right, item);
    }
}

// InOrder traversal the tree in order and print the items
void InOrderTraversal(TreeNode* tree) {
    if (tree != nullptr) {
        InOrderTraversal(tree->left);
        std::cout << tree->info << " ";
        InOrderTraversal(tree->right);
    }
}

// ReverseOrderTraversal the tree in reverse order and print the items
void ReverseOrderTraversal(TreeNode* tree) {
    if (tree != nullptr) {
        ReverseOrderTraversal(tree->right);
        std::cout << tree->info << " ";
        ReverseOrderTraversal(tree->left);
    }
}

// helper function to find the node with the minimum value in a tree
TreeNode* FindMin(TreeNode* tree) {
    TreeNode* current = tree;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

                //  delete a node from the tree
TreeNode* DeleteNode(TreeNode* tree, int item) {
    if (tree == nullptr) {
        return tree;
    } else if (item < tree->info) {
        tree->left = DeleteNode(tree->left, item);
    } else if (item > tree->info) {
        tree->right = DeleteNode(tree->right, item);
    } else {
        // node:  only one child or no child
        if (tree->left == nullptr) {
            TreeNode* temp = tree->right;
            delete tree;
            return temp;
        } else if (tree->right == nullptr) {
            TreeNode* temp = tree->left;
            delete tree;
            return temp;
        }

        // node:  two children :D
        TreeNode* temp = FindMin(tree->right);

        // copy
        tree->info = temp->info;

        // delete  successor after copy
        tree->right = DeleteNode(tree->right, temp->info);
    }
    return tree;
}

BiTree::BiTree() {
    root = nullptr;
}

BiTree::~BiTree() {
    MakeEmpty();
}

void BiTree::MakeEmpty() {
    while (root != nullptr) {
    Remove(root->info);
    }
}

bool BiTree::IsEmpty() {
    return root == nullptr;
}

void BiTree::Add(int item) {
    AddItem(root, item);
}

void BiTree::Remove(int item) {
    if (!IsEmpty()) {
        root = DeleteNode(root, item);
    }
}
//print
void BiTree::PrintTree() {
    std::cout << "My data in alphabetical order: ";
    InOrderTraversal(root);
    std::cout << std::endl;
}

void BiTree::TPrint() {
    std::cout << "Binary Tree:" << std::endl;
    PrintTree(); // Printing in alphabetical order
}

void BiTree::RPrint() {
    std::cout << "My data in reverse alphabetical order: ";
    ReverseOrderTraversal(root);
    std::cout << std::endl;
}
