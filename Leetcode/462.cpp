class Solution {
public:
    long long calc(vector<int> &nums, long long m) {
        int ret = 0;
        for (int i : nums) ret += abs(m-i);
        return ret;
    }
    int minMoves2(vector<int>& nums) {
        int l = -1e9, r = 1e9;
        while (l <= r) {
            int m = (l+r)/2, cur = calc(nums, m);
            if (calc(nums, m-1) < cur) {
                r = m-1;
            }
            else if (calc(nums, m+1) < cur) {
                l = m+1;
            }
            else return cur;
        }
        return -1;
    }
};