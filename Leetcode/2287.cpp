class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int frq1[30], frq2[30];
        memset(frq1, 0, sizeof(frq1));
        memset(frq2, 0, sizeof(frq2));
        for (int i = 0; i < s.size(); i++) {
            frq1[s[i]-'a']++;
        }
        for (int i = 0; i < target.size(); i++) {
            frq2[target[i]-'a']++;
        }
        int mx = 0x3f3f3f3f;
        for (int i = 0; i <= 26; i++) {
            if (frq2[i] == 0) continue;
            mx = min(frq1[i]/frq2[i], mx);
        }
        return mx;
    }
};