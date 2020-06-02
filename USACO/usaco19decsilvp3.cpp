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
vi adj[MM];
int cmp[MM];
string s;

void dfs(int v, int p, char type, int id){
    cmp[v] = id;
    for (int u : adj[v]){
        if (u != p && s[u-1] == type){
            dfs(u, v, type, id);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    cin >> n >> m >> s;
    memset(cmp, -1, sizeof(cmp));
    for (int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++){
        if (cmp[i] == -1){
            dfs(i, -1, s[i-1], i);
        }
    }
    char c;
    string ans;
    for (int i = 0, a, b; i < m; i++){
        cin >> a >> b >> c;
        if (cmp[a] != cmp[b]) ans += '1';
        else if (s[a-1] == c) ans += '1';
        else ans += '0';
    }
    cout << ans << '\n';
}
