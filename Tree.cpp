//
// Created by Isaac Hunter on 2/13/23.
//


#include "Tree.h"

/**== Static Utility Methods ==**/
std::vector<int> Tree::concatVectors(std::vector<int> &vect1, std::vector<int> &vect2) {
    vect1.insert(vect1.end(), vect2.begin(), vect2.end());
    return vect1;
}
std::vector<std::string> Tree::concatVectors(std::vector<std::string> &vect1, std::vector<std::string> &vect2) {
    vect1.insert(vect1.end(), vect2.begin(), vect2.end());
    return vect1;
}

/**== Base and Internal Methods ==**/
Tree::~Tree() {
    clearTree(root);
}

// Recursively deletes subtree starting at node
void Tree::clearTree(TreeNode *node) {
    if(node != nullptr) {
        clearTree(node->rightNode());
        clearTree(node->leftNode());
        delete node;
    }
}
// Runs after operations are performed on the tree
void Tree::treeResolver() {
    this->calculateHeight();
    this->calculateBalance();
    if(autoResolve) {
        this->balanceTree();
    }
    if(verbose) {
        std::cout << "Preorder:" << std::endl;
        this->printTree(traversal::t_preorder);
        std::cout << "Inorder:" << std::endl;
        this->printTree(traversal::t_inorder);
        std::cout << "Postorder:" << std::endl;
        this->printTree(traversal::t_postorder);
        std::cout << "Levelorder:" << std::endl;
        this->printTree(traversal::t_postorder);
        std::cout << std::endl;
    }
}

/** Manipulator Methods **/
// Inserts node into tree at given value
bool Tree::insert(unsigned int value, std::string name, TreeNode *base) {
    auto node = new TreeNode(value, name);

    if(this->root == nullptr) {
        this->root = node;
        this->size++;
        return true;
    }
    if(base == nullptr)
        base = this->root;

    if(value < base->getId()) {
        try {
            base->insertLeftNode(node);
        } catch (AddNodeToExisting& _){
            insert(value, name, base->leftNode());
        }
    } else {
        try {
            base->insertRightNode(node);
        } catch (AddNodeToExisting& _){
            insert(value, name, base->rightNode());
        }
    }

    this->size++;
    this->treeResolver();
    return true;
}

/**== Tree Int Traversals ==**/
std::vector<int> Tree::preorderInt(TreeNode *node) {
    std::vector<int> nodeVector;

    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nodeVector;
    }
//    if(!Tree::verifyNode(node))
//        return nodeVector;

    nodeVector.push_back(node->getId()); // Node
    if(node->leftNode() != nullptr) { // Left Subtree
        std::vector<int> leftVector = this->preorderInt(node->leftNode());
        concatVectors(nodeVector, leftVector);
    }
    if(node->rightNode() != nullptr) { // Right Subtree
        std::vector<int> rightVector = this->preorderInt(node->rightNode());
        concatVectors(nodeVector, rightVector);
    }

    return nodeVector;
}

std::vector<int> Tree::inorderInt(TreeNode *node) {
    std::vector<int> nodeVector;

    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nodeVector;
    }

    if(node->leftNode() != nullptr) { // Left Subtree
        std::vector<int> leftVector = this->inorderInt(node->leftNode());
        concatVectors(nodeVector, leftVector);
    }
    nodeVector.push_back(node->getId()); // Node
    if(node->rightNode() != nullptr) { // Right Subtree
        std::vector<int> rightVector = this->inorderInt(node->rightNode());
        concatVectors(nodeVector, rightVector);
    }

    return nodeVector;
}

std::vector<int> Tree::postorderInt(TreeNode *node) {
    std::vector<int> nodeVector;

    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nodeVector;
    }

    if(node->leftNode() != nullptr) { // Left Subtree
        std::vector<int> leftVector = this->postorderInt(node->leftNode());
        concatVectors(nodeVector, leftVector);
    }
    if(node->rightNode() != nullptr) { // Right Subtree
        std::vector<int> rightVector = this->postorderInt(node->rightNode());
        concatVectors(nodeVector, rightVector);
    }
    nodeVector.push_back(node->getId()); // Node

    return nodeVector;
}

std::vector<int> Tree::levelorderInt(TreeNode *node) {

    std::queue<TreeNode*> currentLevel; // Tracks parents
    std::queue<TreeNode*> children; // Tracks children of parents
    std::vector<int> nodeVector;

    auto addChild = [&](TreeNode* node) {
        children.push(node);
        nodeVector.push_back(node->getId());
    };

    if(this->root == nullptr)
        return nodeVector;
    else if(node == nullptr)
        node = this->root;

    currentLevel.push(node);
    nodeVector.push_back(node->getId());

    for (int i = 0; i < this->height; i++) {

        // Go through each current node and store children
        while(!currentLevel.empty()) {
            TreeNode* currentNode = currentLevel.front();
            if(currentNode->leftNode() != nullptr)
                addChild(currentNode->leftNode());
            if(currentNode->rightNode() != nullptr)
                addChild(currentNode->rightNode());
            currentLevel.pop();
        }

        // Makes the children the current level and empties the children. Enables downward movement
        currentLevel.swap(children);

    }
    return nodeVector;
}

/**== Tree Traversals ==**/
std::vector<std::string> Tree::preorder(TreeNode *node) {
    std::vector<std::string> nodeVector;

    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nodeVector;
    }

    nodeVector.push_back(node->getName()); // Node
    if(node->leftNode() != nullptr) { // Left Subtree
        std::vector<std::string> leftVector = this->preorder(node->leftNode());
        concatVectors(nodeVector, leftVector);
    }
    if(node->rightNode() != nullptr) { // Right Subtree
        std::vector<std::string> rightVector = this->preorder(node->rightNode());
        concatVectors(nodeVector, rightVector);
    }

    return nodeVector;
};
std::vector<std::string> Tree::inorder(TreeNode *node) {
    std::vector<std::string> nodeVector;

    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nodeVector;
    }

    if(node->leftNode() != nullptr) { // Left Subtree
        std::vector<std::string> leftVector = this->inorder(node->leftNode());
        concatVectors(nodeVector, leftVector);
    }
    nodeVector.push_back(node->getName()); // Node
    if(node->rightNode() != nullptr) { // Right Subtree
        std::vector<std::string> rightVector = this->inorder(node->rightNode());
        concatVectors(nodeVector, rightVector);
    }

    return nodeVector;
};
std::vector<std::string> Tree::postorder(TreeNode *node) {
    std::vector<std::string> nodeVector;

    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nodeVector;
    }

    if(node->leftNode() != nullptr) { // Left Subtree
        std::vector<std::string> leftVector = this->postorder(node->leftNode());
        concatVectors(nodeVector, leftVector);
    }
    if(node->rightNode() != nullptr) { // Right Subtree
        std::vector<std::string> rightVector = this->postorder(node->rightNode());
        concatVectors(nodeVector, rightVector);
    }
    nodeVector.push_back(node->getName()); // Node

    return nodeVector;
};



/**== Print Traversal ==**/
void Tree::printTree(Tree::traversal method) {
    std::vector<std::string> selectedVector;

    switch(method) {
        case(t_preorder):
            selectedVector = preorder();
            break;
        case(t_inorder):
            selectedVector = inorder();
            break;
        case(t_postorder):
            selectedVector = postorder();
            break;
        default:
            selectedVector = preorder();
            break;
    }

    auto treeIter = selectedVector.begin();

    for(;treeIter != selectedVector.end() - 1; treeIter++) {
        std::cout << *treeIter;
        if(treeIter != selectedVector.end() -1) {
            std::cout << ", ";
        }
    }
    std::cout << *treeIter;
    std::cout << std::endl;
}

/**== BST Calculations ==**/
int Tree::calculateHeight(TreeNode *node) {
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return 0;
    }

    int leftHeight = 0;
    int rightHeight = 0;

    if(node->leftNode() != nullptr)
        leftHeight = 1+calculateHeight(node->leftNode());
    if(node->rightNode() != nullptr)
        rightHeight = 1+calculateHeight(node->rightNode());

    int treeHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    if(node == this->root)
        this->height = treeHeight;

    node->updateHeight(treeHeight);
    return treeHeight;
}

TreeNode *Tree::search(int val, TreeNode* node, relationship member) {
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nullptr;
    }
    if(val == node->getId())
        return node;



    if(node->getHeight() == 0)
        return nullptr;
    else if(val < node->getId())
        node = search(val, node->leftNode());
    else if(val > node->getId())
        node = search(val, node->rightNode());

    return node;
}

std::vector<TreeNode*> Tree::searchName(std::string& name, std::vector<TreeNode*>& nodes, TreeNode *base) {

    if(base == nullptr) {
        if (this->root != nullptr)
            base = this->root;
        else
            return nodes;
    }

    if(base->getName() == name)
        nodes.push_back(base);

    if(base->leftNode() != nullptr)
        searchName(name, nodes,base->leftNode());

    if(base->rightNode() != nullptr)
        searchName(name, nodes, base->rightNode());

    return nodes;
}

/**== Remove node if node is root, node as 0,1,2 children, using successor method ==**/
bool Tree::remove(int value) {
    TreeNode* node = search(value);
    if(node == nullptr)
        return false;
    TreeNode* parent = searchParent(value);

    if(node == this->root) { // node is root
        if(node->getChildren() == 2) {
            TreeNode* successor = node->rightNode();
            TreeNode* successorParent = node;
            TreeNode* successorChild = nullptr;

            TreeNode* leftChild = node->leftNode();
            TreeNode* rightChild = node->rightNode();

            if(successor->leftNode() != nullptr) {
                while(successor->leftNode() != nullptr) {
                    successorParent = successor;
                    successor = successor->leftNode();
                }
            } else {
                successorParent = nullptr;
            }

            if(successor->getChildren() == 1) {
                successorChild = successor->rightNode();
                successor->removeRightNode();
            }

            node->removeRightNode();
            node->removeLeftNode();
            if(successorParent != nullptr) {
                successorParent->removeLeftNode();
                if(successorChild != nullptr)
                    successorParent->insertLeftNode(successorChild);
            }

            if(successor != leftChild)
                successor->insertLeftNode(leftChild);
            if(successor != rightChild)
                successor->insertRightNode(rightChild);
            else
                successor->insertRightNode(successorChild);

            delete node;
            this->root = successor;
        } else if(node->getChildren() == 1)  {
            this->root = (node->leftNode() != nullptr) ? node->leftNode() : node->rightNode();
            delete node;
        } else if(node->getChildren() == 0) {
            this->root = nullptr;
            delete node;
        }

    } else if(node->getChildren() == 0) { // root has no children
        if(parent->leftNode() == node)
            parent->removeLeftNode();
        else
            parent->removeRightNode();
        delete node;

    } else if(node->getChildren() == 1) { // root has 1 child
        TreeNode* grandchild = (node->leftNode() != nullptr) ? node->leftNode() : node->rightNode();

        if(parent->leftNode() == node) {
            parent->removeLeftNode();
            parent->insertLeftNode(grandchild);
        } else {
            parent->removeRightNode();
            parent->insertRightNode(grandchild);
        }

        delete node;

    } else if(node->getChildren() == 2) { // root has 2 children
        TreeNode* selectedNode = node->rightNode();
        TreeNode* selectedParent = node;
        TreeNode* leftChild = node->leftNode();
        TreeNode* rightChild = node->rightNode();
        node->removeLeftNode();
        node->removeRightNode();

        while(selectedNode->leftNode() != nullptr) { // successor
            selectedParent = selectedNode;
            selectedNode = selectedNode->leftNode();
        }

        TreeNode* selectedChild = selectedNode->leftNode();
        if(parent->leftNode() == node) {
            parent->removeLeftNode();
            parent->insertLeftNode(selectedNode);
        } else {
            parent->removeRightNode();
            parent->insertRightNode(selectedNode);
        }
        selectedNode->insertLeftNode(leftChild);
        selectedNode->insertRightNode(rightChild);

        selectedParent->removeLeftNode();
        selectedParent->insertLeftNode(selectedChild);

        delete node;
    }

    this->size--;
    treeResolver();
    return true;
}

TreeNode *Tree::searchParent(int value, TreeNode *node) {
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nullptr;
    }
    if(value == node->getId() || node->getHeight() == 0)
        return nullptr;

    if(value < node->getId()) {
        if(value == node->leftNode()->getId())
            return node;
        else
            node = searchParent(value, node->leftNode());
    } else {
        if(value == node->rightNode()->getId())
            return node;
        else
            node = searchParent(value, node->rightNode());
    }


    return node;
}

/***====== AVL Calculations =======***/
int Tree::calculateBalance(TreeNode *node) {
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return 0;
    }

    int nodeBalance = 0;
    int leftHeight = 0;
    int rightHeight = 0;

    if(node->leftNode() != nullptr) {
        calculateBalance(node->leftNode());
        leftHeight = 1+node->leftNode()->getHeight();
    }
    if(node->rightNode() != nullptr) {
        calculateBalance(node->rightNode());
        rightHeight = 1+node->rightNode()->getHeight();
    }

    nodeBalance = leftHeight - rightHeight;
    node->updateBalance(nodeBalance);

//    std::cout << "balance: " << nodeBalance << std::endl;
    if((nodeBalance < -1) || (nodeBalance > 1))
        this->balanced = false;
//        std::cout << "balance: " << nodeBalance << std::endl;


    return 0;
}

//Tree::rotation Tree::checkBalanced() {
//    return Tree::r_left_right;
//}

/**== Rotations ==**/
void Tree::rotateLeft(int value) {
    TreeNode* node = search(value);
    if(node != nullptr)
        rotateLeft(node);
    else
        std::cout << "node was null" << std::endl;
}

void Tree::rotateRight(int value) {
    TreeNode* node = search(value);
    if(node != nullptr)
        rotateRight(node);
    else
        std::cout << "node was null" << std::endl;
}
void Tree::rotateRightLeft(int value) {
    TreeNode* node = search(value);
    if(node != nullptr)
        rotateRightLeft(node);
    else
        std::cout << "node was null" << std::endl;
}
void Tree::rotateLeftRight(int value) {
    TreeNode* node = search(value);
    if(node != nullptr)
        rotateLeftRight(node);
    else
        std::cout << "node was null" << std::endl;
}
void Tree::rotateLeft(TreeNode* node) {
    TreeNode* nodeParent = nullptr;
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return;
    } else {
        nodeParent = searchParent(node->getId());
    }
    if(node->rightNode()) {
        TreeNode* newNode = node->rightNode();
        node->removeRightNode(); // removes newNode

        if(newNode->leftNode() != nullptr) { // remove grandchild if it exists
            TreeNode* grandchild = newNode->leftNode();
            newNode->removeLeftNode(); // removes grandchild
            node->insertRightNode(grandchild);
        }

        newNode->insertLeftNode(node); // inserts node as child to newNode

        if(nodeParent != nullptr) {
            if (nodeParent->leftNode() == node) {
                nodeParent->removeLeftNode();
                nodeParent->insertLeftNode(newNode);
            } else {
                nodeParent->removeRightNode();
                nodeParent->insertRightNode(newNode);
            }

        } else
            this->root = newNode;
    }


    treeResolver();

}




void Tree::rotateRight(TreeNode* node) {
    TreeNode* nodeParent = nullptr;
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return;
    } else {
        nodeParent = searchParent(node->getId());
    }

    if(node->leftNode() != nullptr) {
        TreeNode* newNode = node->leftNode();
        node->removeLeftNode();

        if(newNode->rightNode() != nullptr) { // move grandchild if it exists
            TreeNode* grandchild = newNode->rightNode();
            newNode->removeRightNode();
            node->insertLeftNode(grandchild);
        }

        newNode->insertRightNode(node);

        if(nodeParent != nullptr) {
            if (nodeParent->rightNode() == node) {
                nodeParent->removeRightNode();
                nodeParent->insertRightNode(newNode);
            } else {
                nodeParent->removeLeftNode();
                nodeParent->insertLeftNode(newNode);
            }

        } else
            this->root = newNode;

    }


    treeResolver();

}

void Tree::rotateRightLeft(TreeNode *node) {
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return;
    }
    this->rotateRight(node->rightNode());
    this->rotateLeft(node);
}



void Tree::rotateLeftRight(TreeNode *node) {
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return;
    }
    this->rotateLeft(node->leftNode());
    this->rotateRight(node);
}

void Tree::performRotation(TreeNode *node) {
    Tree::rotation method = r_right;

    if(!node->isBalanced()) {
        int nodeBalance = node->getBalance();
        int childBalance = 0;

        if(nodeBalance > 1) { // parent: +2
            childBalance = node->leftNode()->getBalance();
            if(node->leftNode()->isBalanced()) {
                switch(childBalance) {
                    case 1: // child: +1
                    case 0: // child: 0
                        method = r_right;
                        break;
                    case -1: // child: -1
                        method = r_left_right;
                        break;
                    default:
                        break;
                }
            }

        } else { // parent: -2
            childBalance = node->rightNode()->getBalance();
            if(node->rightNode()->isBalanced()) {
                switch(childBalance) {
                    case -1: // child: -1
                    case 0: // child: 0
                        method = r_left;
                        break;
                    case 1: // child: +1
                        method = r_right_left;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    switch(method) {
        case r_left:
            this->rotateLeft(node);
            break;
        case r_right:
            this->rotateRight(node);
            break;
        case r_left_right:
            this->rotateLeftRight(node);
            break;
        case r_right_left:
            this->rotateRightLeft(node);
            break;
        default:
            break;
    }
}

void Tree::balanceTree(TreeNode *node) {
    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return;
    }

    if(node->leftNode() != nullptr)
        balanceTree(node->leftNode());
    if(node->rightNode() != nullptr)
        balanceTree(node->rightNode());

    if(!node->isBalanced())
        performRotation(node);
}

bool Tree::removeInorder(int value, std::stack<TreeNode*>* stack) {

    if(value >= this->size)
        return false;

    std::vector<int> nodeIds = getNodeInOrder(value);

    return this->remove(nodeIds[nodeIds.size()-1]);

// Old Code
//    std::vector<int> dataList = this->inorderInt();
//    if(value >= dataList.size()) {
//        return false;
//    }
//    int selectedInt = dataList.at(value);
//    this->remove(selectedInt);
//    return true;
}

std::vector<int> Tree::getNodeInOrder(int value, TreeNode *node) {
    std::vector<int> nodeVector;

    if(node == nullptr) {
        if (this->root != nullptr)
            node = this->root;
        else
            return nodeVector;
    }
    if(nodeVector.size()-1 == value)
        return nodeVector;

    if(node->leftNode() != nullptr) { // Left Subtree
        std::vector<int> leftVector = this->getNodeInOrder(value, node->leftNode());
        concatVectors(nodeVector, leftVector);
        if(nodeVector.size()-1 == value)
            return nodeVector;
    }
    nodeVector.push_back(node->getId()); // Node
    if(nodeVector.size()-1 == value)
        return nodeVector;
    if(node->rightNode() != nullptr) { // Right Subtree
        std::vector<int> rightVector = this->getNodeInOrder(value, node->rightNode());
        concatVectors(nodeVector, rightVector);
        if(nodeVector.size()-1 == value)
            return nodeVector;
    }

    return nodeVector;
};
































