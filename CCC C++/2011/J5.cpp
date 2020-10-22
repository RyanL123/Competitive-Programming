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

int sz[7];
vi adj[7];

void dfs(int v, int p) {
    sz[v] = 1;
    for (int u : adj[v]) {
        if (u != p) dfs(u, v);
        sz[v] *= (sz[u]+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1, x; i < n; i++) {
        cin >> x;
        adj[x].pb(i);
    }
    dfs(n, 0);
    cout << sz[n] << '\n';
}