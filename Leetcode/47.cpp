class Solution {
public:
    void helper(vector<vector<int>> &ret, set<vector<int>> &st, vector<int> cur, int ind) {
        if (ind == cur.size()) {
            st.insert(cur);
            return;
        }
        unordered_set<int> s;
        for (int i = ind; i < cur.size(); i++) {
            if (s.count(cur[i]) != 0) continue;
            s.insert(cur[i]);
            swap(cur[i], cur[ind]);
            helper(ret, st, cur, ind+1);
            swap(cur[i], cur[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        set<vector<int>> st;
        helper(ret, st, nums, 0);
        for (auto i : st) {
            ret.emplace_back(i);
        }
        return ret;
    }
};