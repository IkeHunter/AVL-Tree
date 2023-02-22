#include <iostream>
#include "Commands.h"
#include "Tree.h"
using namespace std;

/** =============================================
 * DONE: create basic tree structure with int
 * DONE: create insert method
 * DONE: create pre-order
 * DONE: create in-order
 * DONE: create post-order
 * DONE: create delete method
 * DONE: create rotate left
 * DONE: create rotate right
 * DONE: create rotate left-right
 * DONE: add recursive count attribute to node
 * DONE: create dynamic AVL methods, including dynamic rotations
 * DONE: change basic int AVL to student AVL
 * DONE: implement input parsing
 * DONE: connect methods and finish rubric
 ============================================= **/

int main(int argc, char *argv[]) {
    Commands commandPallet;

    int commandsCount;
    Tree inputTree;

    cin >> commandsCount;
    cin.ignore();

    for(int i = 0; i < commandsCount; i++) {
        string input;
        getline(cin, input);

        Commands::commandData cc = commandPallet.parseInput(input);
        TreeNode* node;
        std::vector<TreeNode*> nodeVect;
        switch(cc.type) {
            case(Commands::c_insert):
                if(!inputTree.insert(cc.id, cc.name))
                    cout << "unsuccessful" << endl;
                else
                    cout << "successful" << endl;
                break;
            case(Commands::c_remove):
                if(!inputTree.remove(cc.id))
                    cout << "unsuccessful" << endl;
                else
                    cout << "successful" << endl;
                break;
            case(Commands::c_search_id):

                node = inputTree.search(cc.id);
                if(node == nullptr)
                    cout << "unsuccessful" << endl;
                else
                    cout << node->getName() << endl;

                break;
            case(Commands::c_search_name):
                nodeVect = inputTree.searchName(cc.name, nodeVect);
                if(!nodeVect.empty()) {
                    if(nodeVect.size() == 1)
                        cout << nodeVect[0]->getId() << endl;
                    else {
                        for(auto data : nodeVect) {
                            cout << data->getId() << endl;
                        }
                    }
                } else
                    cout << "unsuccessful" << endl;
                break;
            case(Commands::c_print_in):
                inputTree.printTree(Tree::t_inorder);
                break;
            case(Commands::c_print_pre):
                inputTree.printTree(Tree::t_preorder);
                break;
            case(Commands::c_print_post):
                inputTree.printTree(Tree::t_postorder);
                break;
            case(Commands::c_print_level):
                if(inputTree.getHeight() > 0)
                    cout << inputTree.levelCount() << endl;
                else
                    cout << "0" << endl;
                break;
            case(Commands::c_remove_in):
                if(!inputTree.removeInorder(cc.id))
                    cout << "unsuccessful" << endl;
                else
                    cout << "successful" << endl;
                break;
            default:
                cout << "unsuccessful" << endl;
                break;
        }


    }




    return 0;
}
