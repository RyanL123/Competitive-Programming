#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    int n = s.size();
    int frq[27];
    memset(frq, 0, sizeof(frq));
    for (int i = 0; i < n; i++) {
        frq[s[i]-'a']++;
    }
    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (!st.empty() && st.top() > s[i]) {
            while (!st.empty() && st.top() > s[i] && frq[st.top()-'a'] > 1) {
                frq[st.top()-'a']--;
                st.pop();
            }
        }
        st.push(s[i]);
    }
    string ret = "";
    while (!st.empty()) {
        ret += st.top();
        st.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    cout << removeDuplicateLetters("cbacdcbc") << '\n';
}