#include "../main.cpp"
#include "../Tree.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/** =======
 * Testing Key:
 * a_data => actual data
 * e_data => expected data
 * ======== **/

TEST_CASE("BST Insert", "[flag]"){
    Tree inputTree;
    inputTree.insert(3);
    inputTree.insert(2);

    std::vector<int> a_output = inputTree.inorder();
    std::vector<int> e_output = {2,3};
    REQUIRE(e_output.size() == a_output.size());
    REQUIRE(a_output == e_output);
}
//TEST_CASE("BST Insert Large", "[flag]"){
//    Tree inputTree;
//    std::vector<int> expectedOutput, actualOutput;
//
//    for(int i = 0; i < 100; i++)
//    {
//        int randomInput = rand();
//        if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
//        {
//            expectedOutput.push_back(randomInput);
//            inputTree.insert(randomInput);
//        }
//    }
//
//    actualOutput = inputTree.inorder();
//    REQUIRE(expectedOutput.size() == actualOutput.size());
//    REQUIRE_FALSE(expectedOutput == actualOutput);    //This assertion can be wrong. Don't use
//    std::sort(expectedOutput.begin(), expectedOutput.end());
//    REQUIRE(expectedOutput == actualOutput);
//}
TEST_CASE("BST Traversals", "[flag]"){
    std::vector<int> dataList = {5,8,17,2,3,6};
    Tree inputTree;
    inputTree.toggleAutoResolve();
    for(auto data : dataList) {
        inputTree.insert(data);
    }

    std::vector<int> a_preorder = inputTree.preorder();
    std::vector<int> a_inorder = inputTree.inorder();
    std::vector<int> a_postorder = inputTree.postorder();

    std::vector<int> e_preorder = {5,2,3,8,6,17};
    std::vector<int> e_inorder = {2,3,5,6,8,17};
    std::vector<int> e_postorder = {3,2,6,17,8,5};

    REQUIRE(a_preorder == e_preorder);
    REQUIRE(a_inorder == e_inorder);
    REQUIRE(a_postorder == e_postorder);
}
TEST_CASE("BST Height Pre Resolve", "[flag]"){
    std::vector<int> dataList = {20,50,2,10,8,150,35,1,0,16};
    Tree inputTree;
    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }

    REQUIRE(inputTree.getHeight() == 3);
    inputTree.insert(18);
    REQUIRE(inputTree.getHeight() == 4);
}
TEST_CASE("BST Remove", "[flag]"){
    std::vector<int> dataList = {30,25,35,33,36,12,27,5,26,32,34};
    Tree inputTree;
    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }

    inputTree.remove(25); // node with 2 children
    std::vector<int> a_inorder = inputTree.inorder();
    std::vector<int> e_inorder = {5,12,26,27,30,32,33,34,35,36};
    REQUIRE(a_inorder == e_inorder);

    inputTree.remove(12); // node with 1 child
    std::vector<int> a2_inorder = inputTree.inorder();
    std::vector<int> e2_inorder = {5,26,27,30,32,33,34,35,36};
    REQUIRE(a2_inorder == e2_inorder);

    inputTree.remove(5); // node with 0 children
    a_inorder = inputTree.inorder();
    e_inorder = {26,27,30,32,33,34,35,36};
    REQUIRE(a_inorder == e_inorder);

    inputTree.remove(30); // root, successor with 0 children
    a_inorder = inputTree.inorder();
    e_inorder = {26,27,32,33,34,35,36};
    REQUIRE(a_inorder == e_inorder);

    inputTree.remove(32); // root, successor with 1 child
    a_inorder = inputTree.inorder();
    e_inorder = {26,27,33,34,35,36};
    REQUIRE(a_inorder == e_inorder);
}
TEST_CASE("AVL Balance Calculation", "[flag]"){
    std::vector<int> dataList = {30,25,35,33,36,12,27,5,26,32,34};
    Tree inputTree;
    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }

    REQUIRE(inputTree.getBalance() == true);
    inputTree.remove(36);
    REQUIRE(inputTree.getBalance() == false);

}
TEST_CASE("AVL Left Rotation", "[flag]"){
    std::vector<int> dataList = {10,9,15,14,20,19,21};
    Tree inputTree;
    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }


    inputTree.rotateLeft();
    std::vector<int> a_preorder = inputTree.preorder();
    std::vector<int> e_preorder = {15,10,9,14,20,19,21};
    REQUIRE(a_preorder == e_preorder);

    Tree inputTree2;
    inputTree2.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree2.insert(data);
    }

    inputTree2.rotateLeft(15);
    std::vector<int> a2_preorder = inputTree2.preorder();
    std::vector<int> e2_preorder = {10,9,20,15,14,19,21};
    REQUIRE(a2_preorder == e2_preorder);

}
TEST_CASE("AVL Right Rotation", "[flag]"){
    std::vector<int> dataList = {21,19,15,10,16,20,22};
    Tree inputTree;
    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }


    inputTree.rotateRight();
    std::vector<int> a_preorder = inputTree.preorder();
    std::vector<int> e_preorder = {19,15,10,16,21,20,22};
    REQUIRE(a_preorder == e_preorder);

    Tree inputTree2;
    inputTree2.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree2.insert(data);
    }

    inputTree2.rotateRight(19);
    std::vector<int> a2_preorder = inputTree2.preorder();
    std::vector<int> e2_preorder = {21,15,10,19,16,20,22};
    REQUIRE(a2_preorder == e2_preorder);

}
TEST_CASE("AVL RightLeft Rotation", "[flag]"){
    std::vector<int> dataList = {10,13,12};
    Tree inputTree;
    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }


    inputTree.rotateRightLeft(10);
    std::vector<int> a_preorder = inputTree.preorder();
    std::vector<int> e_preorder = {12,10,13};
    REQUIRE(a_preorder == e_preorder);

}
TEST_CASE("AVL LeftRight Rotation", "[flag]"){
    std::vector<int> dataList = {13,10,12};
    Tree inputTree;
    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }


    inputTree.rotateLeftRight(13);
    std::vector<int> a_preorder = inputTree.preorder();
    std::vector<int> e_preorder = {12,10,13};
    REQUIRE(a_preorder == e_preorder);
}
TEST_CASE("AVL Auto Rotation", "[flag]") {
    std::vector<int> dataList = {50,25,24,27,75,70,72,80,85,84,86};
    Tree inputTree;
    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }

    inputTree.toggleAutoResolve();
    inputTree.refreshTree();
    std::vector<int> a_preorder = inputTree.preorder();
    std::vector<int> e_preorder = {75,50,25,24,27,70,72,85,80,84,86};
    REQUIRE(a_preorder == e_preorder);
}

TEST_CASE("AVL Remove Inorder", "[flag]") {
    std::vector<int> dataList = {12,10,13};
    Tree inputTree;
//    inputTree.toggleAutoResolve();

    for(auto data : dataList) {
        inputTree.insert(data);
    }


    inputTree.removeInorder(1);
    std::vector<int> a_preorder = inputTree.preorder();
    std::vector<int> e_preorder = {13,10};
    REQUIRE(a_preorder == e_preorder);
}



