class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int l = intervals[0][0], r = intervals[0][1];
        vector<vector<int>> ret;
        for (int i = 1; i < n; i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (L <= r) {
                r = max(r, R);
            }
            else {
                ret.push_back({l, r});
                l = L, r = R;
            }
        }
        ret.push_back({l, r});
        return ret;
    }
};