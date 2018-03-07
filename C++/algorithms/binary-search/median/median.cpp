//
// Created by mahidhar.ramesh on 2/1/2018.
//

#include <algorithm>
#include <vector>
#include <iostream>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int low = 0;
    int high = nums1.size();
    int m = nums1.size();
    int n = nums2.size();
    int x = 0;
    int y = 0;
    while(low <= high) {
        x = (low + high)/2;
        y = (m + n + 1)/2 - x;

        int max_left=0, min_right=0;
        if (x < m && nums2[y-1] > nums1[x]) {
            low = x + 1;
        } else if (x > 0 && nums2[y] < nums1[x -1]) {
            high = x - 1;
        } else {
            if (x == 0) {
                max_left = nums2[y-1];
            } else if (y == 0) {
                max_left = nums1[x-1];
            } else {
                max_left = std::max(nums1[x-1], nums2[y-1]);
            }

            if ((m + n) % 2 == 1) {
                return max_left;
            }

            if (x == m) {
                min_right = nums2[y];
            } else if (y == n) {
                min_right = nums1[x];
            } else {
                min_right = std::min(nums1[x], nums2[y]);
            }

            return (max_left + min_right)/2.0;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    std::vector<int> v1 = {1, 2};
    std::vector<int> v2 = {3, 4};
    double med = findMedianSortedArrays(v1, v2);
    std::cout << "median:" << med << std::endl;
}
