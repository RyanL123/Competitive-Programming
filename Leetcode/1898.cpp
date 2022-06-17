class Solution {
public:
    bool check(string s, string &p, vector<int>& removable, int m) {
        for (int i = 0; i <= m; i++) s[removable[i]] = '.';
        int n = p.size(), j = 0;
        for (int i = 0; i < n; i++) {
            while (j < s.size() && s[j] != p[i]) j++;
            if (j == s.size()) return false;
            else s[j] = '.';
        }
        return true;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size(), l = 0, r = n-1, ret = 0;
        while (l <= r) {
            int m = (l+r)/2;
            if (check(s, p, removable, m)) {
                ret = max(ret, m+1);
                l = m+1;
            }
            else r = m-1;
        }
        return ret;
    }
};