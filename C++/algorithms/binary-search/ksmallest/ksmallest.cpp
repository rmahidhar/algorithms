//
// Created by mahidhar.ramesh on 2/3/2018.
//


#include <vector>
#include <iostream>

int ksmallest(int k, std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return ksmallest(k, nums2, nums1);
    }
    int low = std::max(0, k - (int)nums2.size());
    int high = std::min((int)nums1.size(), k);
    int m = nums1.size();
    int n = nums2.size();
    int x = 0;
    int k_x = 0;
    while(low <= high) {
        x = low + (high - low)/2;
        k_x = k - x;
        int max_left=0;
        if (x < k && nums2[k_x - 1] > nums1[x]) {
            low = x + 1;
        } else if (x > 0 && nums2[k_x] < nums1[x-1]) {
            high = x - 1;
        } else {
            if (x == 0) {
                max_left = nums2[k_x-1];
            } else if (k - x == 0) {
                max_left = nums1[x-1];
            } else {
                max_left = std::max(nums1[x-1], nums2[k_x-1]);
            }
            return max_left;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    std::vector<int> v1 = {10, 20};
    std::vector<int> v2 = {30, 40};
    int k = 5;
    int ksmall = ksmallest(k, v1, v2);
    std::cout << "ksmallest:" << ksmall << std::endl;
}
