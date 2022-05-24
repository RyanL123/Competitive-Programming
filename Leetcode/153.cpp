class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1, ret = 5000;
        while (l <= r) {
            if (nums[l] <= nums[r]) return nums[l];
            else {
                int m = (l+r)/2;
                ret = min(ret, nums[m]);
                if (nums[m] >= nums[l]) l = m+1;
                else r = m;
            }
        }
        return ret;
    }
};