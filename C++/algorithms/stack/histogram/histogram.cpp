//
// Created by mahidhar.ramesh on 2/11/2018.
//

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    vector<int> heights = {5,4,4,6,3,2,9,5,4,8,1,0,0,4,7,2};
    stack<int> st;
    int max_area = 0;
    //st.push(-1);
    int i = 0;
    while (i <= heights.size()) {
        int current = (i == heights.size()) ? 0 : heights[i];
        if (st.empty() || current > heights[st.top()]) {
            st.push(i);
            i++;
        } else {
            int top = st.top();
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            int area = heights[top] * w;
            max_area = std::max(max_area, area);
        }
    }

    /*
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        int w = st.empty() ? i : i - st.top() - 1;
        int area = heights[top] * w;
        max_area = std::max(max_area, area);
    }
     */


    cout << "max area:" << max_area << endl;
}