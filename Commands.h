//
// Created by Isaac Hunter on 2/20/23.
//
#include <iostream>
#include <sstream>
#include <vector>

#ifndef AVL_TREE_COMMANDS_H
#define AVL_TREE_COMMANDS_H

struct Commands {
    enum command {c_insert, c_remove, c_search_id, c_search_name, c_print_in, c_print_pre, c_print_post, c_print_level, c_remove_in, c_invalid};
    struct commandData{
        command type;
        std::string name = std::string();
        unsigned int id = int();
        commandData() : type(c_invalid) {};
        explicit commandData(command type) : type(type) {};
        commandData(command type, std::string& name) : type(type), name(name) {};
        commandData(command type, std::string& name, int id) : type(type), name(name), id(id) {};
    };

    commandData parseInput(std::string& input) {
        commandData completeCommand;
        std::stringstream ss(input);
        std::vector<std::string> inputList;
        std::string word;

        while(ss >> word) {
            inputList.push_back(word);
        }
        if(inputList.size() > 3)
            return completeCommand;

        std::string first = inputList[0];

        if(first == "insert") {
            completeCommand.type = c_insert;
        } else if(first == "remove"){
            completeCommand.type = c_remove;
        } else if(first == "search"){
            if(inputList.size() < 2)
                return commandData(c_invalid);
            try {
                std::stoi(inputList[1]);
                completeCommand.type = c_search_id;
            } catch(...) {
                completeCommand.type = c_search_name;
            }
        } else if(first == "printInorder"){
            completeCommand.type = c_print_in;
        } else if(first == "printPreorder"){
            completeCommand.type = c_print_pre;
        } else if(first == "printPostorder"){
            completeCommand.type = c_print_post;
        } else if(first == "printLevelCount"){
            completeCommand.type = c_print_level;
        } else if(first == "removeInorder"){
            completeCommand.type = c_remove_in;
        } else {
            return commandData(c_invalid);
        }

        switch(completeCommand.type) {
            case c_insert:
                if(inputList.size() != 3)
                    return commandData(c_invalid);
                completeCommand.name = inputList[1];
                try {
                    completeCommand.id = stoi(inputList[2]);
                } catch(...) {
                    return commandData(c_invalid);
                }
                break;
            case c_remove:
            case c_search_id:
                if(inputList.size() != 2)
                    return commandData(c_invalid);
                try {
                    completeCommand.id = stoi(inputList[1]);
                } catch(...) {
                    return commandData(c_invalid);
                }
                break;
            case c_search_name:
                if(inputList.size() != 2)
                    return commandData(c_invalid);
                completeCommand.name = inputList[1];
                break;
            default:
                break;
        }

        return completeCommand;
//        if(completeCommand.type == c_insert) {
//            if(inputList.size() != 3)
//                return commandData(c_invalid);
//            completeCommand.name = inputList[1];
//            try {
//                completeCommand.id = stoi(inputList[2]);
//            } catch(...) {
//                return commandData(c_invalid);
//            }
//            return completeCommand;
//        } else if(completeCommand.type == c_remove) {
//            try {
//                completeCommand.id = stoi(inputList[1]);
//            } catch(...) {
//                return commandData(c_invalid);
//            }
//        } else if(completeCommand.type == c_search_id) {
//            try {
//                completeCommand.id = stoi(inputList[1]);
//            } catch(...) {
//                return commandData(c_invalid);
//            }
//        }


    }


//    struct insert {
//        command type = c_insert;
//        std::string name;
//        int id;
//    };
//    struct remove {
//        command c_remove;
//        int id;
//    };
//    struct searchId {
//        command type = c_search_id;
//        int id;
//    };
//    struct searchName {
//        command type = c_search_name;
//        std::string name;
//    };
//    struct printIn {
//        command type = c_print_in;
//    };
//    struct printPre {
//        command type = c_print_pre;
//    };
//    struct printPost {
//        command type = c_print_post;
//    };
//    struct printLevel {
//        command type = c_print_level;
//    };
//    struct removeIn {
//        command type = c_remove_in;
//    };
};

#endif //AVL_TREE_COMMANDS_H
