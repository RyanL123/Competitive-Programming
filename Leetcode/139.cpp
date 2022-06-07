class Solution {
public:
    int dp[305][305];
    bool rec(string &s, int i, int j, unordered_set<string> &dict) {
        if (dp[i][j] != -1) return dp[i][j];
        string sub = s.substr(i, j-i+1);
        if (dict.count(sub)) return dp[i][j] = true;
        else {
            bool ret = false;
            for (int k = 1; k <= sub.size(); k++) {
                string sub1 = s.substr(i, k);
                if (dict.count(sub1)) ret |= rec(s, i+k, j, dict);
            }
            return dp[i][j] = ret;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string i : wordDict) {
            dict.insert(i);
        }
        memset(dp, -1, sizeof(dp));
        return rec(s, 0, s.size()-1, dict);
    }
};