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

const int MM = 1e5+5;
int n, m, a[MM];
vii adj[MM];
int vis[MM];

void bfs(int v, int val, int id){
    queue<int> q;
    q.push(v);
    vis[v] = id;
    while (!q.empty()){
        int w = q.front();
        q.pop();
        for (pii u : adj[w]){
            if (vis[u.first] == -1 && u.second >= val){
                vis[u.first] = id;
                q.push(u.first);
            }
        }
    }
}

bool solve(int val){
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= n; i++){
        if (vis[i] == -1) bfs(i, val, i);
    }
    for (int i = 1; i <= n; i++){
        if (vis[a[i]] != vis[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    bool done = true;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != i) done = false;
    }
    if (done){
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < m; i++){
        int A, B, w;
        cin >> A >> B >> w;
        adj[A].eb(B, w);
        adj[B].eb(A, w);
    }
    int lo = 0, hi = 1e9;
    while (lo <= hi){
        int mid = (lo+hi)/2;
        if (solve(mid)) lo = mid+1;
        else hi = mid-1;
    }
    cout << hi << '\n';
}
