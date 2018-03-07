//
// Created by mahidhar.ramesh on 2/5/2018.
//

#include <iostream>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
    stack<char> st;
    string longestParen;
    string currParen;
    int i = 0;
    while(i < s.length()) {
        if (s[i] == '(') {
            st.push(s[i]);
            currParen += s[i];
        } else if (s[i] == ')') {
            if (!st.empty()) {
                char top = st.top();
                cout << "stack empty:" << st.empty() << endl;
                if (top != '(') {
                    while (!st.empty()) {
                        st.pop();
                    }
                    if (currParen.length() > longestParen.length()) {
                        longestParen = currParen;
                    }
                    currParen = "";
                } else {
                    currParen += top;
                    st.pop();
                }
            }
        } else {
            cout << "invalid paren" << endl;
        }
        i++;
    }
    if (currParen.length() > longestParen.length()) {
        longestParen = currParen;
    }
    return longestParen.length();
}


int main() {
    string str = ")()()";
    cout << "longest valid paren:" << longestValidParentheses(str) << endl;
}