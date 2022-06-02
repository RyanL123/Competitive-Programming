class Solution {
public:
    void helper(vector<string> &ret, int open, int close, int n, string cur) {
        if (cur.size() == 2*n) {
            ret.push_back(cur);
            return;
        }
        if (open < n) helper(ret, open+1, close, n, cur+'(');
        if (close < open) helper(ret, open, close+1, n, cur+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        helper(ret, 0, 0, n, "");
        return ret;
    }
};