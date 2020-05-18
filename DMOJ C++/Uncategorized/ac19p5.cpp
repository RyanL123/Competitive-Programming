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
const int MM = 1.5 * 1e3 + 5;
int m[MM][MM], n, steps[MM][MM];

int dfs(int x, int y){
    int best = 0;
    if (steps[x][y] != -1) return steps[x][y];
    if (x+1 < n && m[x+1][y] > m[x][y]) best = max(best, dfs(x+1, y)+1);
    if (x-1 >= 0 && m[x-1][y] > m[x][y]) best = max(best, dfs(x-1, y)+1);
    if (y+1 < n && m[x][y+1] > m[x][y]) best = max(best, dfs(x, y+1)+1);
    if (y-1 >= 0 && m[x][y-1] > m[x][y]) best = max(best, dfs(x, y-1)+1);
    return steps[x][y] = best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }
    memset(steps, -1, sizeof(steps));
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << "\n";
}