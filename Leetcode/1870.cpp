class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size(), l = 1, r = 1e7, ret = 0x3f3f3f3f;
        while (l <= r) {
            int m = (l+r)/2;
            double cur = 0;
            for (int i = 0; i < n-1; i++) {
                cur += ceil((double)dist[i]/m);
            }
            cur += (double)dist[n-1]/m;
            if (cur <= hour) {
                ret = min(ret, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ret == 0x3f3f3f3f ? -1 : ret;
    }
};