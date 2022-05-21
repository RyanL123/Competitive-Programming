class Solution {
public:
    void helper(vector<vector<int>> &ret, vector<int> n, int ind) {
        if (ind == n.size()) {
            ret.push_back(n);
            return;
        }
        for (int i = ind; i < n.size(); i++) {
            swap(n[i], n[ind]);
            helper(ret, n, ind+1);
            swap(n[i], n[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        helper(ret, nums, 0);
        return ret;
    }
};