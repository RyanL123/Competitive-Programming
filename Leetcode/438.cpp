class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size(), frq1[30], frq2[30];
        memset(frq1, 0, sizeof(frq1));
        memset(frq2, 0, sizeof(frq2));
        vector<int> ret;
        for (int i = 0; i < m; i++) frq2[p[i]-'a']++;
        for (int i = 0; i < n; i++) {
            frq1[s[i]-'a']++;
            bool flag = true;
            if (i >= m) {
                frq1[s[i-m]-'a']--;
            }
            for (int j = 0; j < 26; j++) flag &= frq1[j] == frq2[j];
            if (flag) ret.push_back(i-m+1);
        }
        return ret;
    }
};