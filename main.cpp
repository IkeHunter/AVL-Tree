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
 * TODO: change basic int AVL to student AVL
 * TODO: implement input parsing
 * TODO: connect methods and finish rubric
 ============================================= **/

/**
 * Next steps:
 * I just "finished" the print method, but you should probably look over it bc my
 * brain has been dead for hours lol.
 * Next up, look over tree and nodes class to make sure it can run and do simple methods,
 * configure main.
 * **/


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
        switch(cc.type) {
            case(Commands::c_insert):
                cout << "insert" << endl;
                inputTree.insert(cc.id, cc.name);
                break;
            case(Commands::c_remove):
                cout << "remove" << endl;
                inputTree.remove(cc.id);
                break;
            case(Commands::c_search_id):
                cout << "searchId" << endl;
                inputTree.search(cc.id);
                break;
            case(Commands::c_search_name):
                cout << "searchName" << endl;
                break;
            case(Commands::c_print_in):
                cout << "printInorder" << endl;
                inputTree.printTree(Tree::t_inorder);
                break;
            case(Commands::c_print_pre):
                cout << "printPreorder" << endl;
                inputTree.printTree(Tree::t_preorder);
                break;
            case(Commands::c_print_post):
                cout << "printPostorder" << endl;
                inputTree.printTree(Tree::t_postorder);
                break;
            case(Commands::c_print_level):
                cout << "printLevelCount" << endl;
                cout << inputTree.getHeight() << endl;
                break;
            case(Commands::c_remove_in):
                cout << "removeInorder" << endl;
                inputTree.removeInorder(cc.id);
                break;
            default:
                cout << "invalid" << endl;
                break;
        }


    }




    return 0;
}
