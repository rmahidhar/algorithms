//
// Created by mahidhar.ramesh on 10/21/2017.
//

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    std::vector<int> denominations = {1, 5, 7, 11};
    std::vector<int> min_coins(100);
    std::vector<int> values(100);
    int num = 49;
    for (int i = 0; i < 100; i++) {
        min_coins[i] = i;
    }
    for(int value = 1; value <= num; value++) {
        std::for_each(denominations.begin(), denominations.end(), [&] (auto denomination) {
            if (value >= denomination) {
                min_coins[value] = std::min(1 + min_coins[value - denomination], min_coins[value]);
            }
        });
    }
    std::for_each(min_coins.begin(), min_coins.end(), [](auto value) {std::cout << value << " ";});
}