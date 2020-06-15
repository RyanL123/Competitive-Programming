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
int cnt[MM], in[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int x, y;
    while (cin >> x >> y){
        if (x == 0) break;
        adj[x].pb(y);
        in[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0) {
            q.push(i);
            cnt[i] = 1;
        }
    }
    if (in[n] == 0) {
        cout << 0 << '\n';
        return 0;
    }
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (--in[u] == 0){
                q.push(u);
            }
            cnt[u] += cnt[v];
        }
    }

    cout << cnt[n] << '\n';
}
