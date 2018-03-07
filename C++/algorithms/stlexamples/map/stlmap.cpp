//
// Created by mahidhar.ramesh on 1/21/2018.
//

#include <map>
#include <iostream>

int main(int argc, char *argv[]) {
    std::map<std::string, int> map = {{"X" , 24}, {"A", 1}, {"B", 2}, {"E", 5}, {"Y", 25}};
    std::cout << "min:" << map.begin()->first << std::endl;
    std::cout << "max:" << map.rbegin()->first << std::endl;
}