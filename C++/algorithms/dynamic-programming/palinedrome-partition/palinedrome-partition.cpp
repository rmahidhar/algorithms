//
// Created by mahidhar.ramesh on 1/30/2018.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getPalinedromePartitions(std::string& str) {
    vector<vector<bool>> dp(str.length(), vector<bool>(str.length(), false));
    vector<int> cuts(str.length(), 0);
    for (int l = 0; l < str.length(); l++) {
        cuts[l] = l;
        for (int i = 0; i <= l; i++) {
            if (str[i] == str[l] && (l-i <= 1 || dp[i+1][l-1])) {
                dp[i][l] = true;
                if (i > 0) {
                    cuts[l] = std::min(cuts[l], cuts[i-1] + 1);
                } else {
                    cuts[l] = 0;
                }
            }
        }
    }
    return cuts[str.length()-1];
}

int main(int argc, char** argv) {
    string str = "ababccba";
    int partitions = getPalinedromePartitions(str);
    /*
    for_each(partitions.begin(), partitions.end(), [] (auto item) {
        cout << item << " ";
    });
     */
    cout << "min cuts:" << partitions << endl;
}