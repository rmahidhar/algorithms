//
// Created by mahidhar.ramesh on 12/10/2017.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> schedules = {
            std::pair<int, int>(1,4),
            std::pair<int, int>(6,7),
            std::pair<int, int>(8,9),
            std::pair<int, int>(4,6)
    };
    std::vector<std::pair<int, bool>> sorted_times;

    for_each(schedules.begin(),schedules.end(), [&](auto item) {
        sorted_times.push_back(std::pair<int, bool>(item.first, false));
        sorted_times.push_back(std::pair<int, bool>(item.second, true));
    });

    std::sort(sorted_times.begin(), sorted_times.end(), [](auto lhs, auto rhs) {
        // end time precedes start time.
        return lhs.first < rhs.first || lhs.first == rhs.first && lhs.second;
    });

    int num_rooms = 0;
    int max_rooms = 0;
    for(auto t: sorted_times) {
        // if start time, increment num_rooms
        if (!t.second) {
            num_rooms++;
            max_rooms = std::max(max_rooms, num_rooms);
        } else {
            num_rooms--;
        }
    }

    std::cout << "number of meeting rooms required " << max_rooms << std::endl;

}