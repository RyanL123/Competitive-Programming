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
int a[MM];
vii adj[MM];
bool vis[MM];

// TODO
// check if every cow is in the same connected component as where they are supposed to be
bool solve(int val){
    memset(vis, false, sizeof(vis));
    queue<int> q;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    bool done = true;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != i) done = false;
    }
    if (done){
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < m; i++){
        int A, B, w;
        cin >> A >> B >> w;
        adj[A].eb(B, w);
        adj[B].eb(A, w);
    }
    int lo = 0, hi = MM;
    while (lo < hi){
        int mid = (lo+hi)/2;
        if (solve(mid)) lo = mid+1;
        else hi = mid;
    }
    cout << hi << '\n';
}
