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

struct event{
    int u, v, w, f;
};
int n, m, k, s, t, lst, ans;
vector<event> v;
unordered_set<int> adj[1005];
bool vis[1005];
bool cmp(event a, event b){
    return a.w < b.w || (a.w == b.w && a.f < b.f);
}
void upd(int i){
    if (v[i].f > 0) adj[v[i].u].insert(v[i].v);
    else (adj[v[i].u]).erase(v[i].v);
}
bool bfs(int S, int T){
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (!vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return vis[t];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.pb({a, b, c, 1});
        v.pb({a, b, d+1, -1});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++){
        int cur = v[i].w;
        bool flag = vis[t];
        upd(i);
        for (; i + 1 < v.size() && v[i+1].w == cur; i++) upd(i+1);
        if (bfs(s, t)) ans += (flag ? cur - lst : 1);
        else if (flag) ans += cur - lst - 1;
        lst = cur;
    }
    cout << ans << '\n';
}
