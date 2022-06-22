class Solution {
public:
    struct interval {
        int l, r, id;
    };
    static bool cmp(const interval &a, const interval &b) {
        return a.l < b.l;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<interval> v;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            v.push_back(interval{intervals[i][0], intervals[i][1], i});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            int start = v[i].l, end = v[i].r, id = v[i].id;
            int l = i, r = n-1, cur = -1;
            while (l <= r) {
                int m = (l+r)/2;
                if (v[m].l >= end) {
                    cur = v[m].id;
                    r = m-1;
                }
                else l = m+1;
            }
            ret[id] = cur;
        }
        return ret;
    }
};