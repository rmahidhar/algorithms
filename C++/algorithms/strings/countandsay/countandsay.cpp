//
// Created by mahidhar.ramesh on 2/12/2018.
//

#include <iostream>

using namespace std;

string countAndSay(int n) {
    string result = "1";
    while(--n) {
        string ans;
        int cnt = 1;
        for (int i = 1; i < result.length(); i++) {
            if (result[i] == result[i-1]) {
                ++cnt;
            } else {
                ans += std::to_string(cnt);
                ans += result[i-1];
                cnt = 1;
            }
        }
        ans += std::to_string(cnt);
        ans += result[result.length()-1];
        result = ans;
    }
    return result;
}


int main(int argc, char* argv[]) {
    int n = 6;
    for (int i = 1; i <= n ; i++ ) {
        string result = countAndSay(i);
        cout << "countandsay for n " << i << " is " << result << endl;
    }
}