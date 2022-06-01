class Solution {
public:
    void helper(set<vector<int>> &ret, vector<int> &nums, vector<int> v, int ind) {
        if (ind == nums.size()) {
            ret.insert(v);
            return;
        }
        v.push_back(nums[ind]);
        helper(ret, nums, v, ind+1);
        v.pop_back();
        helper(ret, nums, v, ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ret;
        vector<int> v;
        helper(ret, nums, v, 0);
        vector<vector<int>> ret2;
        for (auto i : ret) {
            ret2.emplace_back(i);
        }
        return ret2;
    }
};