#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f
const int MM = 1e6+5;

ll w[MM], n, k;
bool valid[MM], visited[MM];
vi adj[MM], ans;


bool bfs(int i){
    visited[i] = true;
    queue<int> q;
    q.push(i);
    ans.pb(i);
    ll tot = w[i];
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (w[u] + tot <= 2*k && !visited[u]){
                ans.pb(u);
                tot += w[u];
                visited[u] = true;
            }
        }
    }
    return tot >= k && tot <= 2 * k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
        if (w[i] >= k && w[i] <= 2*k){
            cout << "1\n";
            cout << i << '\n';
            return 0;
        }
        if (w[i] <= 2*k) valid[i] = true;
    }
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        if (valid[x] && valid[y]){
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }
    for (int i = 1; i <= n; i++){
        if (valid[i] && !visited[i]){
            if (bfs(i)){
                cout << ans.size() << '\n';
                for (int j : ans) cout << j << ' ';
                return 0;
            }
            else ans.clear();
        }
    }
    cout << "-1\n";
}