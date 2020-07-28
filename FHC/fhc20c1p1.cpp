#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

string bfs(vi adj[], int start, int n){
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
    string ret = "";
    for (int i = 0; i < n; i++) {
        ret += (visited[i]?"Y":"N");
    }
    return ret;
}

void solve(int id) {
    int n;
    cin >> n;
    string ans[n+1];
    string I, O;
    cin >> I >> O;
    vi adj[n+1];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (abs(i-j) <= 1 && I[j] == 'Y' && O[i] == 'Y') {
                adj[i].pb(j);
            }
            if (abs(i-j) <= 1 && I[i] == 'Y' && O[j] == 'Y') {
                adj[j].pb(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i] = bfs(adj, i, n);
    }
    cout << "Case #" << id << ": \n";
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    freopen("output.txt", "w", stdout);
    for (int i = 1; i <= t; i++) solve(i);
}