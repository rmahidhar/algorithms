//
// Created by mahidhar.ramesh on 1/2/2018.
//

#include <queue>
#include <iostream>
#include <algorithm>

struct Comparator {
    bool operator () (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
        return lhs.first > rhs.first;
    }
};


std::vector<int> MergeKArrays(const std::vector<std::vector<int>>& arrays) {
    std::vector<int> idx_vector(arrays.size(), 0);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> minPq;

    // 1. Push the first element in the arrays to the priority queue
    // 2. Maintain the arrays index in the idx_vector
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minPq.emplace(arrays[i][0], i);
            idx_vector[i] = 1;
        }
    }

    std::vector<int> result;
    while (!minPq.empty()) {
        std::pair<int, int> item = minPq.top();
        if (idx_vector[item.second] < arrays[item.second].size()) {
            minPq.emplace(arrays[item.second][idx_vector[item.second]], item.second);
            idx_vector[item.second]++;
        }
        result.emplace_back(item.first);
        minPq.pop();
    }
    return result;
}

int main(int argc, char *argv[]) {

    /*
    std::vector<std::vector<int>> arrays = {
            std::vector({1, 3, 5, 7}),
            std::vector({2, 4, 6, 8})
    };
     */

    std::vector<std::vector<int>> arrays = {
            {1, 3, 5, 7},
            {2, 4, 6, 8},
            {9}
    };

    std::vector<int> result = MergeKArrays(arrays);
    std::for_each(result.begin(), result.end(), [](auto item) {
        std::cout << item << " ";
    });
}