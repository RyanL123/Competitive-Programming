class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = nums[i], b = nums[j], l = j+1, r = n-1, mx = j;
                while (l <= r) {
                    int m = (l+r)/2, c = nums[m];
                    if (a+b > c) {
                        mx = max(mx, m);
                        l = m+1;
                    }
                    else {
                        r = m-1;
                    }
                }
                ret += mx-j;
            }
        }
        return ret;
    }
};