//
// Created by mahidhar.ramesh on 1/1/2018.
//

#include <queue>
#include <iostream>

int main(int argc, char *argv[]) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPq;
    std::vector<int> stream = {8, 5, 2, 3, 1, 9, 40, 23, 61};
    int k = 1;

    for (auto item : stream) {
        minPq.push(item);
        if (minPq.size() > k) {
            minPq.pop();
        }
    }

    while(!minPq.empty()) {
        std::cout << minPq.top() << " ";
        minPq.pop();
    }
}