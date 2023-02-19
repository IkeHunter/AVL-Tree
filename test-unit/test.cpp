#include "../main.cpp"
#include "../Tree.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("BST Insert", "[flag]"){
    Tree inputTree;
    inputTree.insert(3);
    inputTree.insert(2);
    inputTree.insert(1);
    std::vector<int> actualOutput = inputTree.inorder();
    std::vector<int> expectedOutput = {1, 2, 3};
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);
}


TEST_CASE("BST Insert Large", "[flag]"){
    Tree inputTree;
    std::vector<int> expectedOutput, actualOutput;

    for(int i = 0; i < 100; i++)
    {
        int randomInput = rand();
        if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
        {
            expectedOutput.push_back(randomInput);
            inputTree.insert(randomInput);
        }
    }

    actualOutput = inputTree.inorder();
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE_FALSE(expectedOutput == actualOutput);    //This assertion can be wrong. Don't use
    std::sort(expectedOutput.begin(), expectedOutput.end());
    REQUIRE(expectedOutput == actualOutput);

}

