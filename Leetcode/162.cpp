class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN), nums.push_back(INT_MIN);
        int n = nums.size(), l = 1, r = n-2;
        // 4 cases
        // a[m-1] < a[m] > a[m+1]: m is peak, return m
        // a[m-1] > a[m] > a[m+1]: increasing to the left, left has peak guaranteed
        // a[m-1] < a[m] < a[m+1]: increasing to the right, right has peak guaranteed
        // a[m-1] > a[m] < a[m+1]: increasing both sides, pick arbitrarily
        while (r-l >= 2) {
            int m = (l+r)/2;
            if (nums[m-1] < nums[m] && nums[m] > nums[m+1]) return m-1;
            else if (nums[m-1] > nums[m] && nums[m] > nums[m+1]) r = m-1;
            else if (nums[m-1] < nums[m] && nums[m] < nums[m+1]) l = m+1;
            else l = m+1;
        }
        if (nums[l-1] <= nums[l] && nums[l] >= nums[l+1]) return l-1;
        return r-1;
    }
};