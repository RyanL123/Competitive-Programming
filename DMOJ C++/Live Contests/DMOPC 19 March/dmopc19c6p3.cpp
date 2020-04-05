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

ll pw[500010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, m;
    ll MOD = 1e9+7;
    string n;
    cin >> s >> m >> n;
    set<int> ind;
    pw[0] = 1;
    for (int i = 1; i <= 500000; i++){
        pw[i] = (pw[i-1] + pw[i-1])%MOD;
    }
    ll ans = 0;
    for (int i = 0; i < s; i++){
        if (n[i] == '1'){
            ans = (ans + pw[s-i-1])%MOD;
        }
        else {
            ind.insert(i+1);
        }
    }
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        int x = *ind.lower_bound(l);
        while (x <= r && !ind.empty() && ind.lower_bound(l) != ind.end()){
            ans = (ans + pw[s-x])%MOD;
            ind.erase(x);
            x = *ind.lower_bound(l);
        }
        cout << ans << "\n";
    }
}