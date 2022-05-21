class Solution {
public:
    void helper(vector<vector<int>> &ret, vector<int> &v, vector<int> &n, int ind, int k) {
        if (k == 0 || ind >= n.size()) {
            if (k == 0) ret.push_back(v);
            return;
        }
        v.push_back(n[ind]);
        helper(ret, v, n, ind+1, k-1);
        v.pop_back();
        helper(ret, v, n, ind+1, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> v, nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        helper(ret, v, nums, 0, k);
        return ret;
    }
};