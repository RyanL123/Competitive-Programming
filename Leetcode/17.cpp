class Solution {
public:
    void helper(vector<string> &ret, string mp[], int ind, string &digits, string cur) {
        if (ind == digits.size()) {
            ret.push_back(cur);
            return;
        }
        int num = digits[ind] - '0';
        string letters = mp[num - 2];
        for (int i = 0; i < letters.size(); i++) {
            cur.push_back(letters[i]);
            helper(ret, mp, ind + 1, digits, cur);
            cur = cur.substr(0, cur.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        string mp[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        if (digits == "") return {};
        helper(ret, mp, 0, digits, "");
        return ret;
    }
};