//
// Created by Isaac Hunter on 2/13/23.
//

#ifndef AVL_TREE_TREENODE_H
#define AVL_TREE_TREENODE_H

#include <iostream>

class TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    int height = 0; // height of subtree, 0 based
    int balance = 0; // AVL value

    void calculateHeight() {}; // get height of longest string of nodes
    void calculateBalance() {}; // get balance value -1, 0, 1, based on AVL


public:
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode* rightNode() {return right;};
    TreeNode* leftNode() {return left;};
    int getHeight() {return height;};
    int getBalance() {return balance;};
};

//TreeNode::TreeNode(int x) {
//    std::cout << "tree node works" << std::endl;
//}



#endif //AVL_TREE_TREENODE_H
