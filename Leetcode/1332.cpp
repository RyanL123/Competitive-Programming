class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        bool palin = true;
        for (int i = 0; i <= n/2; i++) {
            palin &= s[i] == s[n-i-1];
        }
        if (palin) return 1;
        return 2;
    }
};