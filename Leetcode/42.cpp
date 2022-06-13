class Solution {
public:
    int trap(vector<int>& height) {
        int l[100005], r[100005], n = height.size();
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        for (int i = 1; i <= n; i++) {
            l[i] = max(l[i-1], height[i-1]);
            r[n-i+1] = max(r[n-i+2], height[n-i]);
        }
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (min(l[i], r[i]) > height[i-1]) ret += min(l[i], r[i]) - height[i-1];
        }
        return ret;
    }
};