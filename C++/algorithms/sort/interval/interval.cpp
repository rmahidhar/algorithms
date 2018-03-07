//
// Created by mahidhar.ramesh on 2/21/2018.
//

#include <vector>
#include <list>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;

    struct IntervalItem {
        int value;
        bool start;
        IntervalItem() : value(0), start(0) {}
        IntervalItem(int v, bool s) : value(v), start(s) {

        }
        bool operator < (IntervalItem& rhs) {
            return value < rhs.value || value == rhs.value && !start;
        }
    };

    vector<IntervalItem> sortIntervals;

    for (auto interval : intervals) {
        sortIntervals.emplace_back(interval.start, true);
        sortIntervals.emplace_back(interval.end, false);
    }

    /*
    sort(sortIntervals.begin(), sortIntervals.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.value < rhs.value || lhs.value == rhs.value && !lhs.start;
    });
     */

    sort(sortIntervals.begin(), sortIntervals.end());

    int start = -1;
    int end = std::numeric_limits<int>::max();
    for (auto item : sortIntervals) {
        if (item.start) {
            if (start == -1) {
                start = item.value;
            } else if (end < item.value) {
                result.emplace_back(start, end);
                start = item.value;
            }
        } else {
            end = item.value;
        }
    }
    result.emplace_back(start, end);

    return result;
}

int main(int argc, char* argv[]) {
    vector<Interval> input = {
            {1,3},{2,6},{8,10},{15,18}
    };

    vector<Interval> result = merge(input);

    for_each(result.begin(), result.end(), [](auto item) {
        cout << "[" << item.start << "," << item.end << "]" << " ";
    });
}