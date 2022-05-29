class Solution {
public:
    void dfs(vector<int> (&adj)[205], int (&mark)[205], int p, int u, int id) {
        mark[u] = id;
        for (int v : adj[u]) {
            if (v != p && mark[v] == 0) {
                dfs(adj, mark, u, v, id);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int mark[205];
        memset(mark, 0, sizeof(mark));
        vector<int> adj[205];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isConnected[i][j]) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            if (mark[i] == 0) {
                dfs(adj, mark, -1, i, cur++);
            }
        }
        return cur-1;
    }
};