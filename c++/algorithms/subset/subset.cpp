//
// Created by Mahidhar Rajala on 5/2/17.
//

#include <string>
#include <iostream>

void subset(const std::string& str, std::string substr, int i, int len) {

    if (i == len) {
        std::cout << substr << std::endl;
        return;
    }

    subset(str, substr, i+1, len);
    subset(str, substr + str[i], i+1, len);
}

void subset(const std::string& str) {
    subset(str, "", 0, str.length());
}

int main(int argc, char *argv[]) {
    std::string str("abcd");
    subset(str);
}