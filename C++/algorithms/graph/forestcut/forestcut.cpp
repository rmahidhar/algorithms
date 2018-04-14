//
// Created by mahidhar.ramesh on 3/28/2018.
//

#include <vector>
#include <tuple>
#include <queue>
#include <map>

using namespace std;

class Comparator {
public:
    bool operator() (tuple<int, int, int>& lhs, tuple<int, int, int>& rhs) {
        return get<2>(lhs) < get<2>(rhs);
    }
};

void push(queue<pair<int, int>>& q, vector<vector<int>>& forest,
          int row, int col, map<pair<int, int>, bool>& visited) {
    int rows = forest.size();
    int cols = forest[0].size();
    pair<int, int> item = make_pair(row, col);
    if (row < 0 || row > rows || col < 0 || col > cols || visited[item]) {
        return;
    }
    q.push(item);
}

int bfs(vector<vector<int>>& forest, pair<int, int>& src, pair<int, int>& dst) {
    queue<pair<int,int>> q;
    q.push(src);
    int distance = 0;
    map<pair<int, int>, bool> visited;
    while(!q.empty()) {
        auto item = q.front();
        q.pop();
        if (item == dst) {
            return distance;
        }
        distance++;
        visited[item] = true;
        int row = item.first;
        int col = item.second;
        push(q, forest, row+1, col, visited);
        push(q, forest, row-1, col, visited);
        push(q, forest, row, col+1, visited);
        push(q, forest, row, col-1, visited);
    }
    return -1;
}

int cutOffTree(vector<vector<int>>& forest) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Comparator> pq;
    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest[0].size(); j++) {
            if (forest[i][j] > 1) {
                tuple<int, int, int> item = make_tuple(i, j, forest[i][j]);
                pq.push(item);
            }
        }
    }

    pair<int, int> src = make_pair(0,0);
    int steps = 0;
    while(!pq.empty()) {
        auto item = pq.top();
        pq.pop();
        pair<int, int> dst = make_pair(get<0>(item), get<1>(item));
        int len = bfs(forest, src, dst);
        if (len >= 0) {
            steps += len;
            forest[dst.first][dst.second] = 1;
        } else {
            return -1;
        }
        src.first = dst.first;
        src.second = dst.second;
    }
}

int main(int argc, char** argv) {
    return 0;
}

