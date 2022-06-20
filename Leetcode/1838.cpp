class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, ret = 0;
        long sum = 0;
        sort(nums.begin(), nums.end());
        for (int r = 0; r < n; r++) {
            int cur = nums[r];
            sum += cur;
            while (l <= r && (long)(r-l+1)*cur - sum > k) {
                sum -= nums[l++];
            }
            ret = max(ret, r-l+1);
        }
        return ret;
    }
};