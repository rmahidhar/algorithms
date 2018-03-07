//
// Created by mahidhar.ramesh on 1/11/2018.
//

#include <iostream>

int sqrt(int x) {
    /*
    int l = 1, r = x;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l)/2;
        if (mid <= x/mid) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans;
    */

    int l = 0, r = x;
    while (l < r) {
        int mid = l + (r - l)/2;
        if (mid <= x/mid) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;

}

int main(int argc, char *argv[]) {
    int num = 2;
    std::cout << "sqrt(" << num << "):" << sqrt(num) << std::endl;
}