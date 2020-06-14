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

const int MM = 1026;
int bit[MM][MM];

void upd(int x, int y, int val){
    for (int i = x; i <= MM; i += (i&-i)){
        for (int j = y; j <= MM; j += (j&-j)){
            bit[i][j] += val;
        }
    }
}

ll qry(int x, int y){
    ll ret = 0;
    for (int i = x; i; i -= (i&-i)){
        for (int j = y; j; j -= (j&-j)){
            ret += bit[i][j];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, x, y, a, l, b, r, t;
    cin >> q;
    cin >> q;
    while (cin >> q){
        if (q == 1){
            cin >> x >> y >> a;
            x++, y++;
            upd(x, y, a);
        }
        if (q == 2){
            cin >> l >> b >> r >> t;
            r++, t++;
            cout << qry(r, t) - qry(l, t) - qry(r, b) + qry(l, b) << '\n';
        }
        if (q == 3) return 0;
    }
}
