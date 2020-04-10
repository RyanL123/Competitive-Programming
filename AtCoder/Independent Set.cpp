#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

vi g[100010];
ull dp[2][100010], m = 1e9+7;

void dfs(int u, int p){
    for (int v : g[u]){
        if (v != p){
            dfs(v, u);
            dp[0][u] = (dp[0][u]%m * dp[1][v]%m)%m;
            dp[1][u] = ((dp[0][v]%m + dp[1][v]%m)%m * dp[1][u]%m)%m;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);

    }
    for (int i = 1; i <= n; i++) dp[1][i] = dp[0][i] = 1;
    dfs(1, 0);
    cout << (dp[0][1]%m + dp[1][1]%m)%m;
}
