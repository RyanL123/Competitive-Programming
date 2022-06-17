class Solution {
public:
    int check(vector<int>& bloomDay, int t, int k) {
        int ret = 0, cur = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= t) cur++;
            else cur = 0;
            if (cur == k) {
                ret++;
                cur = 0;
            }
        }
        return ret;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r = 1e9, ret = 0x3f3f3f3f;
        while (l <= r) {
            int mid = (l+r)/2;
            if (check(bloomDay, mid, k) >= m) {
                ret = min(ret, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        return ret == 0x3f3f3f3f ? -1 : ret;
    }
};