class Solution {
public:
    void helper(vector<vector<int>> &ret, vector<int> &candidates, vector<int> v, int sum, int ind) {
        if (sum < 0) return;
        if (sum == 0) {
            ret.emplace_back(v);
            return;
        }
        if (ind == candidates.size()) return;
        for (int i = ind; i < candidates.size(); i++) {
            if (i > 0 && i > ind && candidates[i] == candidates[i-1]) continue;
            v.push_back(candidates[i]); // take cur element
            helper(ret, candidates, v, sum-candidates[i], i+1);
            v.pop_back(); // dont take
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> v;
        helper(ret, candidates, v, target, 0);
        return ret;
    }
};