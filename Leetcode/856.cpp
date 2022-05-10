#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s) {
    if (s == "()") return 1;
    int n = s.size();
    int ret = 0;
    if (n > 1 && s[0] == '(' && s[n-1] == ')') {
        ret += scoreOfParentheses(s.substr(1, n-2)) * 2;
    }
    stack<char> st;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == '(') st.push('(');
        if (st.empty() && s[i] == ')') {
            return 0;
        }
        else if (s[i] == ')') st.pop();
        if (st.empty()) {
            int A = scoreOfParentheses(s.substr(0, i+1));
            int B = scoreOfParentheses(s.substr(i+1, n));
            return A + B;
        }
    }
    return ret;
}

int main() {
    cout << scoreOfParentheses("()()");
}