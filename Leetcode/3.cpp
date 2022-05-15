class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ret = 0, j = 0;
        int frq[200];
        memset(frq, 0, sizeof(frq));
        for (int i = 0; i < n; i++) {
            if (++frq[s[i]] > 1) {
                while (j < i && frq[s[i]] > 1) {
                    frq[s[j++]]--;
                }
            }
            ret = max(ret, i-j+1);
        }
        return ret;
    }
};