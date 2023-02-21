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
    bool balanced = true;

public:
    enum rotation {r_right, r_left, r_right_left, r_left_right, r_none};
    enum traversal {t_preorder, t_inorder, t_postorder, t_levelorder};
    enum relationship {f_node, f_parent, f_grandparent};
private:
    /** AVL Calculations **/
    int calculateHeight(TreeNode* node=nullptr);
    int calculateBalance(TreeNode* node= nullptr);

    int nodeBalanceRatio(TreeNode* node){return 0;};
    int nodeSubtreeHeight(TreeNode* node){return 0;};

//    rotation checkBalanced();
    void performRotation(TreeNode* node);
    void balanceTree(TreeNode* node= nullptr);


    /** Utility Methods **/
    void clearTree(TreeNode* node);
    void treeResolver();
    static std::vector<int> concatVectors(std::vector<int> &vect1, std::vector<int> &vect2);
    TreeNode* searchParent(int value, TreeNode* node= nullptr);

public:
    /** Constructor/Destructor/Operators **/
    Tree() : verbose(false), size(0), height(0){};
    explicit Tree(bool verbose) : verbose(verbose), size(0), height(0){};
    ~Tree();

    /** Accessors **/
    int getSize() const {return size;};
    int getHeight() const {return height;};
    bool getBalance() const {return balanced;};

    /** Printing Methods **/
    void printTree(traversal method=traversal::t_preorder);

    /** Required Methods **/
    void insert(unsigned int value, std::string name, TreeNode *base = nullptr);
    TreeNode* search(int val, TreeNode* node= nullptr, relationship member=f_node);
    bool remove(int value);
    std::vector<int> preorder(TreeNode *node=nullptr);
    std::vector<int> inorder(TreeNode *node=nullptr);
    std::vector<int> postorder(TreeNode *node=nullptr);
    std::vector<int> levelorder(TreeNode *node=nullptr);
    int levelCount() const { return height + 1; };
    bool removeInorder(int value);

    /** Rotations **/
    void rotateLeft(TreeNode* node= nullptr);
    void rotateLeft(int value);
    void rotateRight(TreeNode* node= nullptr);
    void rotateRight(int value);
    void rotateRightLeft(TreeNode* node= nullptr);
    void rotateRightLeft(int value);
    void rotateLeftRight(TreeNode* node= nullptr);
    void rotateLeftRight(int value);



    /** Testing Helpers **/
    bool toggleVerbose() {
        this->verbose = !this->verbose;
        return this->verbose;
    };
    bool toggleAutoResolve() {
        this->autoResolve = !this->autoResolve;
        return this->autoResolve;
    }
    void refreshTree() {this->treeResolver();};

};


#endif //AVL_TREE_TREE_H
