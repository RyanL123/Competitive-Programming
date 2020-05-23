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

struct e{
    int a, b, c, id;
};
bool cmp(e x, e y){
    return x.c < y.c;
}
bool check(e x, e y){
    return (x.a == y.a && x.b == y.b) || (x.a == y.b && x.b == y.a);
}

bool done[150];
int pa[150];

int find(int v){
    if (pa[v] == v) return v;
    return pa[v] = find(pa[v]);
}

int join(e E){
    int px = find(E.a);
    int py = find(E.b);
    if (px != py){
        pa[px] = py;
        return E.c;
    }
    return inf;
}

int MST(vector<e> &edges, int nodes){
    sort(edges.begin(), edges.end(), cmp);
    int cnt = 0, ans = 0;
    for (e E : edges){
        int cost = join(E);
        if (cost != inf){
            cnt++;
            ans += cost;
        }
        if (cnt == nodes-1){
            return ans;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M;
    cin >> M;
    vector<e> edges;
    vector<e> MSTedges;
    vector<e> outside;
    for (int i = 1; i <= M; i++){
        pa[i] = i;
        int E;
        cin >> E;
        vi corner;
        for (int j = 0; j < E; j++){
            int p;
            cin >> p;
            corner.pb(p);
        }
        int cur = 0;
        for (int j = 0; j < E; j++){
            int c;
            cin >> c;
            if (cur < E-1) edges.pb({corner[cur], corner[cur+1], c, i});
            else edges.pb({corner[0], corner[E-1], c, i});
            cur++;
        }
    }
    for (int i = 0; i < edges.size(); i++){
        bool flag = false;
        for (int j = i+1; j < edges.size(); j++){
            if (check(edges[i], edges[j])){
                MSTedges.pb({edges[i].id, edges[j].id, edges[i].c, 0});
                outside.pb({edges[i].id, edges[j].id, edges[i].c, 0});
                flag = true;
                done[i] = done[j] = true;
                break;
            }
        }
        if (!flag && !done[i]){
            outside.pb({edges[i].id, 0, edges[i].c, 0});
        }
    }
    int mn = inf;
    mn = min(mn, MST(MSTedges, M));
    for (int i = 1; i <= M; i++){
        pa[i] = i;
    }
    mn = min(mn, MST(outside, M+1));
    cout << mn << '\n';
}