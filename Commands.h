//
// Created by Isaac Hunter on 2/20/23.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>

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

        while (ss >> word) {
            inputList.push_back(word);
        }
//        if (inputList.size() > 3)
//            return completeCommand;

        std::string first = inputList[0];

        if (first == "insert") {
            completeCommand.type = c_insert;
        } else if (first == "remove") {
            completeCommand.type = c_remove;
        } else if (first == "search") {
            if (inputList.size() < 2)
                return commandData(c_invalid);
            try {
                std::stoi(inputList[1]);
                completeCommand.type = c_search_id;
            } catch (...) {
                completeCommand.type = c_search_name;
            }
        } else if (first == "printInorder") {
            completeCommand.type = c_print_in;
        } else if (first == "printPreorder") {
            completeCommand.type = c_print_pre;
        } else if (first == "printPostorder") {
            completeCommand.type = c_print_post;
        } else if (first == "printLevelCount") {
            completeCommand.type = c_print_level;
        } else if (first == "removeInorder") {
            completeCommand.type = c_remove_in;
        } else {
            return commandData(c_invalid);
        }

        std::string name;
        std::string inputId;
        std::regex str_exp("[[:alpha:][:blank:]]+");
        switch (completeCommand.type) {
            case c_insert:
                if (inputList.size() < 3)
                    return commandData(c_invalid);
                name = "";
                for(int i = 1; i < inputList.size() - 1; i++) {
                    std::string temp = inputList[i];

                    if(temp.at(0) == '"') {
                        auto it = temp.begin();
                        temp.erase(it);
                        it = temp.end();
                        it--;
                        temp.erase(it);
                    }
                    name += temp;
                    if(i != inputList.size()-2) {
                        name += " ";
                    }
                }

                if(std::regex_match(name, str_exp)) {
                    completeCommand.name = name;
                    inputId = inputList[inputList.size()-1];
                } else
                    return commandData(c_invalid);

                if(inputId.length() != 8)
                    return commandData(c_invalid);
                try {
                    completeCommand.id = stoi(inputId);
                } catch (...) {
                    return commandData(c_invalid);
                }
                break;
            case c_remove:
            case c_search_id:
                if (inputList.size() != 2)
                    return commandData(c_invalid);
                inputId = inputList[1];
                if(inputId.length() != 8)
                    return commandData(c_invalid);
                try {
                    completeCommand.id = stoi(inputId);
                } catch (...) {
                    return commandData(c_invalid);
                }
                break;
            case c_search_name:
                if (inputList.size() < 2)
                    return commandData(c_invalid);
                name = "";
                for(int i = 1; i < inputList.size(); i++) {
                    std::string temp = inputList[i];

                    if(temp.at(0) == '"') {
                        auto it = temp.begin();
                        temp.erase(it);
                        it = temp.end();
                        it--;
                        temp.erase(it);
                    }
                    name += temp;
                    if(i != inputList.size()-1) {
                        name += " ";
                    }
                }
                if(std::regex_match(name, str_exp)) {
                    completeCommand.name = name;
                } else
                    return commandData(c_invalid);

                break;
            case c_remove_in:
                if(inputList.size() > 2)
                    return commandData(c_invalid);
                inputId = inputList[1];

                try {
                    completeCommand.id = stoi(inputId);
                } catch (...) {
                    return commandData(c_invalid);
                }
                break;
            default:
                break;
        }

        return completeCommand;
    }
};

#endif //AVL_TREE_COMMANDS_H
