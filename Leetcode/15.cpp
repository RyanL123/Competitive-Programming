class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            int l = i+1, r = n-1, target = -nums[i];
            while (l < r) {
                int val = nums[l] + nums[r];
                if (val == target) { 
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == ret.back()[1]) l++;
                    while (l < r && nums[r] == ret.back()[2]) r--;
                }
                else if (val < target) l++;
                else r--;
            }
            while (i < n-1 && nums[i+1] == nums[i]) i++;
        }
        return ret;
    }
};