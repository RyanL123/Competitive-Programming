class Solution {
public:
    void helper(vector<string> &ret, string s, int ind) {
        if (ind == s.size()) {
            ret.push_back(s);
            return;
        }
        if (!isalpha(s[ind])) {
            helper(ret, s, ind+1);
            return;
        }
        s[ind] = toupper(s[ind]);
        helper(ret, s, ind+1);
        s[ind] = tolower(s[ind]);
        helper(ret, s, ind+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ret;
        helper(ret, s, 0);
        return ret;
    }
};