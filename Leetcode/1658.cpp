class Solution {
public:
    int pfx[100005];
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        memset(pfx, 0, sizeof(pfx));
        for (int i = 1; i <= n; i++) {
            pfx[i] += pfx[i-1] + nums[i-1];
        }
        int target = pfx[n]-x, l = 1, mx = -1;
        for (int r = 1; r <= n; r++) {
            while (l <= r && pfx[r] - pfx[l-1] > target) l++;
            if (pfx[r] - pfx[l-1] == target) {
                mx = max(mx, r-l+1);
            }
        }
        if (mx == -1) return -1;
        return n-mx;
    }
};