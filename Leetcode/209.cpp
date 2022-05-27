class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX, n = nums.size(), sum = 0, r = 0;
        for (int l = 0; l < n; l++) {
            while (r < n && sum < target) {
                sum += nums[r++];
            }
            if (sum >= target) ret = min(ret, r-l);
            sum -= nums[l];
        }
        return ret == INT_MAX ? 0 : ret;
    }
};