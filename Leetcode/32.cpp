class Solution {
public:
    // valid string must start with '(' and end with ')'
    // ')' has no chance of being the start of a valid string
    // every '(' can be the start of valid string
    // if we see '(', push its index in (potential starting candidate)
    // if we see ')', pop the top index
    // if the stack is empty, the string is invalid, push in the current index as a place holder
    // if the stack is not empty, everything in between the current index and top index has been valid
    int longestValidParentheses(string s) {
        int n = s.size(), ret = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else ret = max(ret, i-st.top());
            }
        }
        return ret;
    }
};