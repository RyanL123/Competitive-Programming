class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        int cnt1 = 0, cnt2 = 0, p1 = n-1, p2 = m-1;
        while (true) {
            while (p1 >= 0) {
                if (s[p1] == '#') {
                    cnt1++, p1--;
                }
                else if (cnt1 > 0) {
                    cnt1--, p1--;
                }
                else break;
            }
            while (p2 >= 0) {
                if (t[p2] == '#') {
                    cnt2++, p2--;
                }
                else if (cnt2 > 0) {
                    cnt2--, p2--;
                }
                else break;
            }
            if (p1 >= 0 && p2 >= 0 && s[p1] == t[p2]) {
                p1--, p2--;
            }
            else break;
        }
        return p1 < 0 && p2 < 0;
    }
};