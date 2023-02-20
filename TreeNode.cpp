//
// Created by Isaac Hunter on 2/16/23.
//
#include "TreeNode.h"

/** Insertion Methods **/
void TreeNode::insertRightNode(TreeNode *node) {
    if(node != nullptr) {
        if(this->right != nullptr) {
            throw AddNodeToExisting();
        } else {
            this->right = node;
            this->children++;
        }
    }

}
void TreeNode::insertLeftNode(TreeNode *node) {
    if(node != nullptr) {
        if(this->left != nullptr) {
            throw AddNodeToExisting();
        } else {
            this->left = node;
            this->children++;
        }
    }
}

TreeNode *TreeNode::rightNode() const {
    if(this->right != nullptr) {
        return right;
    } else {
        return nullptr;
//        throw NodeIsNull();
    }
}

TreeNode *TreeNode::leftNode() const {
    if(this->left != nullptr) {
        return left;
    } else {
        return nullptr;
//        throw NodeIsNull();
    }
}

void TreeNode::removeRightNode() {
    if(this->right != nullptr) {
        this->right = nullptr;
        this->children--;
    }

}

void TreeNode::removeLeftNode() {
    if(this->left != nullptr) {
        this->left = nullptr;
        this->children--;
    }

}

void TreeNode::updateHeight(int value) {
    this->height = value;
}

void TreeNode::updateBalance(int value) {
    this->balance = value;
}
bool TreeNode::isBalanced() const {
        switch(this->balance) {
        case -1:
        case 0:
        case 1:
            return true;
        default:
            return false;
    }
}




