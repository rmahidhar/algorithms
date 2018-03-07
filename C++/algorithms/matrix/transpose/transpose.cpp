//
// Created by mahidhar.ramesh on 2/14/2018.
//

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < row; col++) {
            std::swap(matrix[row][col], matrix[col][row]);
        }
    }

    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[0].size(); col++) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }

    for (int row = 0; row < matrix.size(); row++) {
        std::reverse(matrix[row].begin(), matrix[row].end());
    }

    std::cout << std::endl;

    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[0].size(); col++) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }

}
