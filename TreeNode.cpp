//
// Created by Isaac Hunter on 2/16/23.
//
#include "TreeNode.h"

/** Insertion Methods **/
void TreeNode::insertRightNode(TreeNode *node) {
    if(this->right != nullptr) {
        throw AddNodeToExisting();
    } else {
        this->right = node;
    }
}
void TreeNode::insertLeftNode(TreeNode *node) {
    if(this->left != nullptr) {
        throw AddNodeToExisting();
    } else {
        this->left = node;
    }
}

int TreeNode::updateHeight() {
    int leftSide = 0;
    int rightSide = 0;

    if(this->left != nullptr)
        leftSide = this->left->updateHeight() + 1;
    if(this->right != nullptr)
        leftSide = this->right->updateHeight() + 1;

    int newHeight = (leftSide >= rightSide) ? leftSide : rightSide;
    this->height = newHeight;

    return newHeight;
}



