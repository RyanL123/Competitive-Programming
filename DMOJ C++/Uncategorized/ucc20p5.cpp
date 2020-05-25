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
#define inf 0x3f3f3f3f

vi adj[1010];
int dis[1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, a, b, n;
    cin >> l >> a >> b >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    for (int i = 0; i <= 1000; i++){
        dis[i] = inf;
    }
    queue<int> q;
    dis[a] = 0;
    q.push(a);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (dis[u] > dis[v]+1){
                dis[u] = dis[v]+1;
                q.push(u);
            }
        }
    }
    cout << dis[b] << '\n';
}