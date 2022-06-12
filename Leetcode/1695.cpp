class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int frq[10005], pfx[100005], n = nums.size();
        memset(frq, 0, sizeof(frq));
        memset(pfx, 0, sizeof(pfx));
        for (int i = 1; i <= n; i++) pfx[i] += pfx[i-1] + nums[i-1];
        int l = 0, ret = 0;
        for (int r = 0; r < n; r++) {
            if (++frq[nums[r]] > 1) {
                while (l < r && frq[nums[r]] > 1) {
                    frq[nums[l]]--;
                    l++;
                }
            }
            ret = max(ret, pfx[r+1]-pfx[l]);
        }
        return ret;
    }
};