class Solution {
public:
    static bool cmp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
    // dp[word] = max chain ending at word
    int longestStrChain(vector<string>& words) {
        int n = words.size(), ret = 0;
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> dp;
        for (int i = 0; i < n; i++) {
            string s2 = words[i];
            dp[s2] = 1;
            for (int j = 0; j < s2.size(); j++) {
                string s1 = s2.substr(0, j) + s2.substr(j+1);
                if (dp.find(s1) != dp.end()) dp[s2] = max(dp[s2], dp[s1]+1);
            }
            ret = max(ret, dp[s2]);
        }
        return ret;
    }
};