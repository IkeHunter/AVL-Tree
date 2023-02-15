//
// Created by Isaac Hunter on 2/13/23.
//

#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H

#include <iostream>
#include "TreeNode.h"

class Tree {
    TreeNode* root = nullptr;
    int size;
    int height;

    /** AVL Calculations **/
    void calculateHeight(){};

    int nodeBalanceRatio(TreeNode* node){return 0;};
    int nodeSubtreeHeight(TreeNode* node){return 0;};

    bool isBalanced(){return true;};


    /** Rotations **/
    void rotateRight(){};
    void rotateLeft(){};
    void rotateRightLeft(){};
    void rotateLeftRight(){};


public:
    Tree();
    /** Accessors **/
    int getSize(){return size;};
    int getHeight(){return height;};

    /** Required Methods **/
    void insertNode(){};
    void removeNode(){};
    void search(int val){};
    void printPreorder(){};
    void printInorder(){};
    void printPostorder(){};
    void printLevelCount(){};
    void removeInorder(){};

};


#endif //AVL_TREE_TREE_H
