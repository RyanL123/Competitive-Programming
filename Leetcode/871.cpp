class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int cur = startFuel, cnt = 0, n = stations.size();
        priority_queue<int> pq;
        int i = 0;
        for (; i < n; i++) {
            if (stations[i][0] <= startFuel) pq.push(stations[i][1]);
            else break;
        }
        while (cur < target) {
            if (pq.empty()) return -1;
            cnt++;
            cur += pq.top();
            pq.pop();
            for (; i < n; i++) {
                if (stations[i][0] <= cur) pq.push(stations[i][1]);
                else break;
            }
        }
        return cnt;
    }
};