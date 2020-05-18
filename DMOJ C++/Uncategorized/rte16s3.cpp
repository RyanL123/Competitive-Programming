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

const int MM = 6e3+5;
vii adj[MM];
unsigned int ans[MM][MM], d[MM];

void dfs(int v, int p, int w){
    d[v] = w;
    for (pii u : adj[v]){
        if (u.first != p){
            dfs(u.first, v, w+u.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    for (int i = 0; i < n; i++){
        memset(d, 0, sizeof(d));
        dfs(i, i, 0);
        for (int j = 0; j < n; j++){
            ans[i][j] = d[j];
        }
    }
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << "\n";
    }
}