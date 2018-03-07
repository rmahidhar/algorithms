//
// Created by mahidhar.ramesh on 1/2/2018.
//

#include <queue>
#include <iostream>
#include <algorithm>

struct Comparator {
    bool operator () (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
        return lhs.first < rhs.first;
    }
};


int main(int argc, char *argv[]) {
    std::priority_queue<int> maxPq;
    std::vector<int> stream = {8, 5, 2, 3, 1, 9, 40, 23, 61};
    int k = 6;

    for (auto item : stream) {
        maxPq.emplace(item);
    }

    std::vector<int> maxHeapVector;
    while(!maxPq.empty()) {
        maxHeapVector.emplace_back(maxPq.top());
        maxPq.pop();
    }

    std::vector<int> result;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> maxPq1;
    maxPq1.emplace(maxHeapVector[0], 0);
    for (int i = 0; i < k; i++) {
        auto item = maxPq1.top();
        result.emplace_back(item.first);
        maxPq1.pop();
        if (maxHeapVector.size() > 2 * item.second + 1) {
            maxPq1.emplace(maxHeapVector[item.second * 2 + 1], item.second * 2 + 1);
        }
        if (maxHeapVector.size() > 2 * item.second + 2) {
            maxPq1.emplace(maxHeapVector[item.second * 2 + 2], item.second * 2 + 2);
        }
    }

    std::for_each(result.begin(),result.end(), [](auto item) {
        std::cout << item << " ";
    });
}