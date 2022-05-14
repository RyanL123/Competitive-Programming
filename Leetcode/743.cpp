class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[105];
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj[u].push_back({v, w});
        }
        int time[105];
        memset(time, 0x3f, sizeof(time));
        queue<pair<int, int>> q;
        q.push({k, 0});
        time[k] = 0;
        while (!q.empty()) {
            int u = q.front().first;
            int w = q.front().second;
            q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                if (w+adj[u][i].second < time[adj[u][i].first]) {
                    time[adj[u][i].first] = w+adj[u][i].second;
                    q.push({adj[u][i].first, w+adj[u][i].second});
                }
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (time[i] == 0x3f3f3f3f) return -1;
            ans = max(ans, time[i]);
        }
        return ans;
    }
};