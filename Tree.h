//
// Created by Isaac Hunter on 2/13/23.
//



#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H

#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
#include "Exceptions.h"

/**
 * Resolve:
 *  update heights
 *  update balance
 *  rotate if necessary
 *  print tree if tests enabled
 * **/

class Tree {
    TreeNode* root = nullptr;
    int size;
    int height;
    bool verbose;
    bool autoResolve = true;

    enum rotation {r_right, r_left, r_right_left, r_left_right, r_none};
    enum traversal {t_preorder, t_inorder, t_postorder, t_levelorder};

    /** AVL Calculations **/
    int calculateHeight(TreeNode* node=nullptr);

    int nodeBalanceRatio(TreeNode* node){return 0;};
    int nodeSubtreeHeight(TreeNode* node){return 0;};

    rotation checkBalanced(){return rotation::r_right;};

    /** Traversals **/
//    int preorderIterator(TreeNode* node);
//    int inorderIterator(TreeNode* node);
//    int postorderIterator(TreeNode* node);

    /** Rotations **/
    void rotateRight(){};
    void rotateLeft(){};
    void rotateRightLeft(){};
    void rotateLeftRight(){};

    /** Utility Methods **/
    void clearTree(TreeNode* node);
    void treeResolver();
    static std::vector<int> concatVectors(std::vector<int> &vect1, std::vector<int> &vect2);

public:
    /** Constructor/Destructor **/
    Tree() : verbose(false), size(0), height(0){};
    explicit Tree(bool verbose) : verbose(verbose), size(0), height(0){};
    ~Tree();

    /** Accessors **/
    int getSize() const {return size;};
    int getHeight() const {return height;};

    /** Printing Methods **/
    void printTree(traversal method=traversal::t_preorder);

    /** Required Methods **/
    void insert(int value, TreeNode *base= nullptr);
    void remove(int value){};
    void search(int val){};
    std::vector<int> preorder(TreeNode *node=nullptr);
    std::vector<int> inorder(TreeNode *node=nullptr);
    std::vector<int> postorder(TreeNode *node=nullptr);
    std::vector<int> levelorder(TreeNode *node=nullptr);
    void levelCount(){};
    void removeInorder(){};

    /** Testing Helpers **/
    bool toggleVerbose() {
        this->verbose = !this->verbose;
        return this->verbose;
    };
    bool toggleAutoResolve() {
        this->autoResolve = !this->autoResolve;
        return this->autoResolve;
    }

};


#endif //AVL_TREE_TREE_H
