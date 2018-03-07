//
// Created by mahidhar.ramesh on 2/28/2018.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getHash(char c) {
    return c - 'a';
}

string sub_str_atmost_k_chars(string str, int k) {
    vector<int> map(26, 0);
    int b = 0, e = 0;
    int len = str.length();
    int num_unique_chars = 0;
    int max_len = 0;
    string result;
    while (e < len) {
        if (map[getHash(str[e++])]++ == 0) {
            num_unique_chars++;
        };

        if (num_unique_chars == k) {
            if (max_len < e-b) {
                max_len = e-b;
                result = str.substr(b, max_len);
            }
        }

        while(num_unique_chars > k) {
            if (map[getHash(str[b++])]-- ==  1) {
                num_unique_chars--;
            }
        }
    }
    return result;
}


int main(int argc, char* argv[]) {
    string str = "abcbbbbcccbdddadacb";
    //string str = "bbbbb";
    cout << str << ":" << sub_str_atmost_k_chars(str, 4);
}