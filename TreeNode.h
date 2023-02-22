//
// Created by Isaac Hunter on 2/13/23.
//


#ifndef AVL_TREE_TREENODE_H
#define AVL_TREE_TREENODE_H
#include <iostream>

#include "Exceptions.h"


class TreeNode {
    unsigned int id;
    std::string name;

    TreeNode* left;
    TreeNode* right;

    int height = 0; // height of subtree, 0 based
    int balance = 0; // AVL value
    int children = 0;

    void calculateHeight() {}; // get height of longest string of nodes
    void calculateBalance() {}; // get balance value -1, 0, 1, based on AVL

public:
    TreeNode(int x, std::string &name) : id(x), name(name), left(nullptr), right(nullptr) {}
    TreeNode* rightNode() const;
    TreeNode* leftNode() const;

    /** Accessors **/
    int getHeight() const {return height;};
    int getBalance() const {return balance;};
    unsigned int getId() const {return id;};
    int getChildren() const {return children;};
    std::string getName() {return name;};

    /** Mutators **/
    void insertRightNode(TreeNode* node);
    void insertLeftNode(TreeNode* node);
    void removeRightNode();
    void removeLeftNode();

    /** Utility **/
    void updateHeight(int value);
    void updateBalance(int value);
    bool isBalanced() const;


};



#endif //AVL_TREE_TREENODE_H
