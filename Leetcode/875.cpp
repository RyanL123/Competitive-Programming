class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9, n = piles.size(), ret = 1e9;
        while (l <= r) {
            int m = (l+r)/2;
            long long cur = 0;
            for (int i = 0; i < n; i++) {
                cur += ceil((double)piles[i]/m);
            }
            if (cur <= h) ret = min(ret, m);
            if (cur <= h) r = m-1;
            else l = m+1;
        }
        return ret;
    }
};