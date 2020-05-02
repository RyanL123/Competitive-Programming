#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int M[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, j, t = 0;
    cin >> n >> m >> j;
    for (int i = 0; i <= n; i++){
        M[i] = inf;
    }
    for (int i = 0; i < m; i++){
        int p, t;
        cin >> p >> t;
        M[p] = t;
    }
    int l = 0, r = 0, cur = 0;
    while (r <= n){
        r = l+1;
        int mn = inf, ind = 0;
        while (r-l <= j){
            if (M[r] <= mn){
                mn = M[r];
                ind = r;
            }
            r++;
        }
        if (mn == inf){
            cout << -1 << '\n';
            return 0;
        }
        if (cur <= M[ind]){
            t += M[ind] - cur;
            cur = M[ind];
        }
        l = ind;
    }
    cout << t << '\n';
}