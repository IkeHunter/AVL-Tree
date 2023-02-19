//
// Created by Isaac Hunter on 2/15/23.
//

#ifndef AVL_TREE_EXCEPTIONS_H
#define AVL_TREE_EXCEPTIONS_H

#include <exception>

/** AddNodeToExisting: thrown when trying to add node in place of existing node without de-allocation **/
class AddNodeToExisting: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Invalid operation: Cannot replace existing node with a new node";
    }
};

#endif //AVL_TREE_EXCEPTIONS_H
