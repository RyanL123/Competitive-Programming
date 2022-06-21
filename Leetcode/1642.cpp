class Solution {
public:
    bool check(vector<int>& diff, int bricks, int ladders, int m) {
        vector<int> sub(diff.begin(), diff.begin()+m);
        sort(sub.begin(), sub.end());
        for (int i = m-1; i >= 0; i--) {
            if (sub[i] <= 0) break;
            if (ladders > 0) ladders--;
            else bricks -= sub[i];
        }
        return bricks >= 0 && ladders >= 0;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), l = 0, r = n-1, ret = 0;
        vector<int> diff(n, 0);
        for (int i = 0; i < n-1; i++) diff[i] = heights[i+1] - heights[i];
        while (l <= r) {
            int m = (l+r)/2;
            if (check(diff, bricks, ladders, m)) {
                ret = max(ret, m);
                l = m+1;
            }
            else r = m-1;
        }
        return ret;
    }
};