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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, m;
    ll MOD = 1e9+7;
    string n;
    cin >> s >> m >> n;
    ull ans = 0;
    for (int i = 0; i < s; i++){
        if (n[i] == '1') ans += (ll)pow(2, s-i-1)%MOD;
    }
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        for (int j = l-1; j < r; j++){
            if (n[j] != '1'){
                ans += (ll)pow(2, s-j-1)%MOD;
                n[j] = '1';
            }
        }
        cout << ans%MOD << "\n";
    }
}