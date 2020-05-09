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

const int MM = (2001*2002)/2+2005, MOD = 1e9+7;

ll bit[MM], a[MM];

ll qry(int pos){
    ll ret = 0;
    for (int i = pos; i; i -= i&-i) ret += bit[i];
    return ret;
}

void upd(int pos, int val){
    for (int i = pos; i <= MM; i += i&-i) bit[i] += val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int q;
        cin >> q;
        if (q == 1){
            int r, c, t;
            cin >> r >> c >> t;
            r += c-1;
            int pos = (r*(r+1))/2-c+1;
            upd(pos, t);
        }
        else {
            int r, c, x;
            cin >> r >> c >> x;
            r += c-1;
            int pos1 = (r*(r+1))/2-c+1;
            int pos2 = pos1-x;
            ans = ((qry(pos1) - qry(pos2-1))%MOD + ans%MOD)%MOD;
        }
    }
    cout << ans%MOD << '\n';
}
