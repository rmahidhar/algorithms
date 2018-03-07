//
// Created by mahidhar.ramesh on 2/4/2018.
//



#include <string>
#include <vector>
#include <iostream>

using namespace std;

void helper(string digits, int idx, string rs, vector<string>& rv, int n) {
    static vector<string> letters = {"_", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (idx == n) {
        rv.push_back(rs);
        cout << rs << endl;
        return;
    }

    string ls = letters[digits[idx]-'0'];
    for (int j = 0; j < ls.size(); j++) {
        string r = rs + ls[j];
        helper(digits, idx+1, r, rv, n);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    helper(digits, 0, "", result, digits.size());
    return result;
}

int main(int argc, char *argv[]) {
    letterCombinations("23");
}