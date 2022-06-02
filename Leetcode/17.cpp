class Solution {
public:
    void helper(vector<string>& ret, string cur, string &digits, int ind) {
        if (ind == digits.size()) {
            ret.push_back(cur);
            return;
        }
        string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < mp[digits[ind]-'0'].size(); i++) {
            helper(ret, cur+mp[digits[ind]-'0'][i], digits, ind+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> ret;
        helper(ret, "", digits, 0);
        return ret;
    }
};