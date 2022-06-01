class Solution {
public:
    void helper(vector<vector<int>> &ret, vector<int>& nums, vector<int> v, int ind) {
        if (ind == nums.size()) {
            ret.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        helper(ret, nums, v, ind+1);
        v.pop_back();
        helper(ret, nums, v, ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> v;
        helper(ret, nums, v, 0);
        return ret;
    }
};