class Solution {
public:
    int first[100005], mn[100005], visited[100005], d = 0;
    vector<vector<int>> ans;
    vector<int> adj[100005];
    
    void dfs(int p, int u) {
        first[u] = mn[u] = d++;
        visited[u] = 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (!visited[v]) dfs(u, v);
            mn[u] = min(mn[v], mn[u]);
            if (first[u] < mn[v]) {
                ans.push_back({u, v});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(-1, 0);
        return ans;
    }
};