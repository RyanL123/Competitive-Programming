class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long MOD = 1e9+7, n = nums1.size(), sum = 0, ret = LONG_LONG_MAX;
        vector<int> v = nums1;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            sum += abs(nums1[i]-nums2[i]);
        }
        for (int i = 0; i < n; i++) {
            int l = 0, r = n-1, mn = 0x3f3f3f3f;
            while (l <= r) {
                int m = (l+r)/2;
                int diff = v[m] - nums2[i];
                mn = min(mn, abs(diff));
                if (diff <= 0) { // v_m too small, move right
                    l = m+1;
                }
                else r = m-1;
            }
            ret = min(ret, sum-abs(nums1[i]-nums2[i])+mn);
        }
        return ret%MOD;
    }
};