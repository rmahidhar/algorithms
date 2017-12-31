//
// Created by mahidhar.ramesh on 10/22/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int main(int argc, char* argv[]) {
    int set[] = {3, 34, 4, 12, 5, 2};
    int num = 6;
    static int rows = sizeof(set)/sizeof(int) + 1;
    static int cols = num + 1;
    bool state[rows][cols];
    auto n_items = sizeof(set)/sizeof(int);

    memset(state, false, sizeof(bool) * rows * cols);

    // zero sum cant be made from any number in the set
    for (int item = 0; item <= n_items; item++) {
        state[item][0] = true;
    }

    // zero sum cant be made from any number in the set
    for (int sum = 1; sum <= num; sum++) {
        state[0][sum] = false;
    }

    for(int item = 1; item <= n_items; item++) {
        auto item_val = set[item-1];
        for(auto sum = 1; sum <= num; sum++) {
            if (sum >= item_val) {
                state[item][sum] =  state[item-1][sum] || state[item-1][sum-item_val];
            } else {
                state[item][sum] = state[item-1][sum];
            }
        }
    }

    std::cout << "Result:" << std::endl;
    for(int i = 0; i <= n_items; i++) {
        for (int j = 0; j <= num; j++)
            std::cout << state[i][j] << " ";
        std::cout << std::endl;
    }
}
