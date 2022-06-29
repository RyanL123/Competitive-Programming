class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1, ret = 0x3f3f3f3f;
        while (l <= r) {
            int m = (l+r)/2;
            ret = min(ret, nums[m]);
            // rotated
            if (nums[l] > nums[r]) {
                if (nums[m] >= nums[l]) l = m+1;
                else r = m-1;
            }
            // not rotated
            else if (nums[l] < nums[r]) r = m-1;
            // could be rotated
            else {
                // unknown
                if (nums[l] == nums[m]) l++, r--;
                else if (nums[m] > nums[r]) l = m+1;
                else r = m-1;
            }
        }
        return ret;
    }
};