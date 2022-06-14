class Solution {
public:
    // guess how many operations it takes to make all numbers <= n
    // if guess takes too many operatinos, decrease n
    // if guess takes too few operations, increase n
    // if a <= n, takes no operations
    // if a > n, takes ceil(a/n)-1 operations
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9, ret = 0x3f3f3f3f;
        while (l <= r) {
            int m = (l+r)/2;
            int cur = 0;
            for (int i : nums) {
                if (i > m) cur += ceil((double)i/m)-1;
            }
            if (cur <= maxOperations) ret = min(ret, m);
            if (cur > maxOperations) l = m+1;
            else r = m-1;
        }
        return ret;
    }
};