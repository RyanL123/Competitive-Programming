class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), l = 1, r = 1e6, ret = 0x3f3f3f3f;
        while (l <= r) {
            int m = (l+r)/2;
            int sum = 0;
            for (int i = 0; i < n; i++) sum += ceil((double)nums[i]/m);
            if (sum <= threshold) {
                ret = min(ret, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ret;
    }
};