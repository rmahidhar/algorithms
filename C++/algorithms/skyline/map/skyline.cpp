//
// Created by mahidhar.ramesh on 1/21/2018.
//

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main(int argc, char *argv[]) {

    struct Data {
        int x1;
        int x2;
        int y;
    };

    struct Point {
        int x;
        int y;
        bool isStart;
    };

    //std::vector<Data> input = { {1, 3, 3}, {2, 4, 4}, {5, 8, 2}, {6, 7, 4}, {8, 9, 4}};
    std::vector<Data> input = { {1, 3, 4}, {3, 4, 4}, {2, 6, 2}, {8, 11, 4}, {7, 9, 3}, {10, 11, 2} };

    std::vector<Point> points;
    std::for_each(input.begin(), input.end(), [&](auto item) {
        points.push_back({item.x1, item.y, true});
        points.push_back({item.x2, item.y, false});
    });

    std::sort(points.begin(), points.end(), [](auto lhs, auto rhs) {
        if (lhs.x != rhs.x) {
            return lhs.x < rhs.x;
        } else {
            if (lhs.isStart && rhs.isStart) {
                // for start points higher height comes first
                return lhs.y > rhs.y;
            } else if (!lhs.isStart && !rhs.isStart){
                // for end points lower height comes first
                return lhs.y < rhs.y;
            } else {
                // start end point comes first
                return lhs.isStart;
            }
        }
    });

    std::vector<std::pair<int, int>> result;
    std::map<int, int> pq;
    int max_height = 0;
    pq.emplace(0, 1);
    std::for_each(points.begin(), points.end(), [&](auto item) {
        // start point, add to the pq, if already exist increment the count
       if (item.isStart) {
           auto it = pq.find(item.y);
           if (it != pq.end()) {
               it->second++;
           } else {
               pq.emplace(item.y, 1);
           }
       } else {
           // end point, decrement or remove it from the pq
           auto it = pq.find(item.y);
           if (it != pq.end() && --it->second == 0) {
               pq.erase(it);
           }
       }
       if (max_height != pq.rbegin()->first) {
           max_height = pq.rbegin()->first;
           result.push_back({item.x, max_height});
       }
       //std::cout << "(" << item.x << "," << item.y << "," << (item.isStart ? "S" : "E") << ") ";
    });

    std::for_each(result.begin(), result.end(), [](auto item) {
       std::cout << "(" << item.first << "," << item.second << ") ";
    });
    std::cout << std::endl;
}