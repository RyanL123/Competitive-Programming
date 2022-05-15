class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m < n) return false;
        int frq1[30], frq2[30];
        memset(frq1, 0, sizeof(frq1));
        memset(frq2, 0, sizeof(frq2));
        for (int i = 0; i < n; i++) frq1[s1[i]-'a']++;
        for (int i = 0; i < m; i++) {
            frq2[s2[i]-'a']++;
            if (i >= n) frq2[s2[i-n]-'a']--;
            bool flag = true;
            for (int j = 0; j < 26; j++) flag &= frq1[j] == frq2[j];
            if (flag) return true;
        }
        return false;
    }
};