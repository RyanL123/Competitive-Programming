class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v;
        int n = difficulty.size(), m = worker.size();
        for (int i = 0; i < n; i++) {
            v.push_back({profit[i], difficulty[i]});
        }
        sort(worker.begin(), worker.end());
        sort(v.begin(), v.end(), cmp);
        int ret = 0, r = m-1, last = m;
        for (int i = n-1; i >= 0; i--) {
            int l = 0, cur = -1, diff = v[i].second;
            while (l <= r) {
                int mid = (l+r)/2;
                if (worker[mid] >= diff) {
                    cur = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
            if (cur != -1) {
                ret += (last-cur)*v[i].first;
                last = cur;
            }
        }
        return ret;
    }
};