class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        int l = 0, r = n-1;
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                ret.push_back(nums[l]*nums[l]);
                l++;
            } else {
                ret.push_back(nums[r]*nums[r]);
                r--;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};