class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        for (string s : st) {
            for (int i = 1; i < s.size(); i++) {
                st.erase(s.substr(i));
            }
        }
        int ret = 0;
        for (string s : st) ret += s.size()+1;
        return ret;
    }
};