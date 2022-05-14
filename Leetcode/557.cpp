class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), prev = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                reverse(s.begin()+prev, s.begin()+i);
                prev = i+1;
            }
        }
        reverse(s.begin()+prev, s.end());
        return s;
    }
};