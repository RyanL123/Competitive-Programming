class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        set<int> st;
        int ret = 0;
        for (int i = 0; i < s.size(); i++) v[s[i]-'a']++;
        for (int i : v) {
            if (i == 0) continue;
            else if (st.count(i) == 0) st.insert(i);
            else {
                while (st.count(i) == 1 && i > 0) {
                    i--;
                    ret++;
                }
                st.insert(i);
            }
        }
        return ret;
    }
};