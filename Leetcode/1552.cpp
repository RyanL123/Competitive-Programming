class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(), l = 1, r = 1e9, ret = 0;
        sort(position.begin(), position.end());
        while (l <= r) {
            int mid = (l+r)/2, cur = m-1, last = position[0];
            for (int i = 1; i < n; i++) {
                if (position[i] - last >= mid) {
                    cur--;
                    last = position[i];
                }
            }
            if (cur <= 0) {
                ret = max(ret, mid);
                l = mid+1;
            }
            else r = mid-1;
        }
        return ret;
    }
};