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

int pa[1000010], pb[1000010], pc[1000010], ans = inf;

void check (int x[], int y[], int i, int n){
    int nx = x[n], ny = y[n];
    // Make x and y perfect groups
    int swap = ny - (y[i] - y[i-ny]) + nx - (x[i-ny] - x[i-ny-nx]);
    // Subtract overlap from union
    // i.e. x in y or y in x will get counted twice
    swap -= min(x[i] - x[i-ny], y[i-ny] - y[i-ny-nx]);
    ans = min(ans, swap);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n; i++){
        if (s[i-1] == 'A') pa[i] = 1;
        if (s[i-1] == 'B') pb[i] = 1;
        if (s[i-1] == 'C') pc[i] = 1;
        pa[i] += pa[i-1];
        pb[i] += pb[i-1];
        pc[i] += pc[i-1];
    }
    int na = pa[n], nb = pb[n], nc = pc[n];
    for (int i = 1; i <= n; i++){
        if (i >= na + nb){
            check(pa, pb, i, n);
            check(pb, pa, i, n);
        }
        if (i >= na + nc) {
            check(pa, pc, i, n);
            check(pc, pa, i, n);
        }
        if (i >= nb + nc){
            check(pb, pc, i, n);
            check(pc, pb, i, n);
        }
    }
    cout << ans << endl;
}