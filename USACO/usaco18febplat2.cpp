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

const int MM = 1e5+5, LOG = 17;
int q, n, rt[MM], x[MM], y[MM], dia[MM], dep[MM], anc[LOG][MM];

int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LOG-1; i >= 0; i--){
        if (dep[anc[i][u]] >= dep[v]) u = anc[i][u];
    }
    if (u == v) return u;
    for (int i = LOG-1; i >= 0; i--){
        if (anc[i][u] != anc[i][v]){
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    return anc[0][u];
}

int dist(int u, int v){
    return dep[u] + dep[v] - 2*dep[lca(u, v)];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for (int i = 1; i <= q; i++){
        char op;
        int v;
        cin >> op >> v;
        if (op == 'B'){
            n++;
            if (v == -1){
                rt[n] = x[n] = y[n] = n;
                dep[n] = dia[n] = 0;
            }
            else {
                rt[n] = rt[v];
                dep[n] = dep[v]+1;
                anc[0][n] = v;
                for (int j = 1; j < LOG; j++){
                    anc[j][n] = anc[j-1][anc[j-1][n]];
                }
                int r = rt[n], dx = dist(x[r], n), dy = dist(y[r], n);
                if (dx > dia[r]){
                    dia[r] = dx;
                    y[r] = n;
                }
                if (dy > dia[r]){
                    dia[r] = dy;
                    x[r] = n;
                }
            }
        }
        else {
            cout << max(dist(v, x[rt[v]]), dist(v, y[rt[v]])) << '\n';
        }
    }
}