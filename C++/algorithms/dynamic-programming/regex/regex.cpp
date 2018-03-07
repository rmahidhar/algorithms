//
// Created by mahidhar.ramesh on 2/3/2018.
//

#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, false));

    dp[0][0] = true;

    for(int col = 1; col <= p.length(); col++) {
        if (col >= 2 && p[col-1] == '*') {
            dp[0][col] = dp[0][col-2];
        } else {
            dp[0][col] = false;
        }
    }

    if (p.length() == 1 && p[0] == '*') {
        dp[0][1] = true;
    }

    for(int row = 1; row <= s.length(); row++) {
        dp[row][0] = false;
    }

    for(int row = 1; row <= s.length(); row++) {
        for(int col = 1; col <= p.length(); col++) {
            if (s[row-1] == p[col-1] || p[col-1] == '.') {
                dp[row][col] = dp[row-1][col-1];
            } else if (p[col-1] == '*') {
                dp[row][col] = dp[row][col-2] || (dp[row-1][col] && (s[row-1] == p[col-2] || p[col-2] == '.'));
            } else {
                dp[row][col] = false;
            }
        }
    }

    /*
    cout << endl;
    for (int i = 0; i <= s.length(); i++) {
        for (int j = 0; j <= p.length(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */

    return dp[s.length()][p.length()];
}

int main(int argc, char** argv) {


    std::cout << "match(" << "aa, a):" << isMatch("aa", "a") << std::endl;
    std::cout << "match(" << "aa, aa):" << isMatch("aa", "aa") << std::endl;
    std::cout << "match(" << "aaa, aa):" << isMatch("aaa", "aa") << std::endl;


    std::cout << "match(" << "aa, a*):" << isMatch("aa", "a*") << std::endl;


    std::cout << "match(" << "aa, .*):" << isMatch("aa", ".*") << std::endl;
    std::cout << "match(" << "ab, .*):" << isMatch("ab", ".*") << std::endl;
    std::cout << "match(" << "aab, c*a*b):" << isMatch("aab", "c*a*b") << std::endl;


    std::cout << "match(" << "abcd, d*):" << isMatch("abcd", "d*") << std::endl;
}
