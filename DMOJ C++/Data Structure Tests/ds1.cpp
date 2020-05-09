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

const int MM = 1e5+5;

ll a[MM], bit1[MM], bit2[MM], n, m;

void upd(int pos, int val, ll bit[]){
    for (int i = pos; i <= MM; i += i&-i) bit[i] += val;
}

ll q(int pos, ll bit[]){
    ll ret = 0;
    for (int i = pos; i; i -= i&-i) ret += bit[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        upd(i, a[i], bit1);
        upd(a[i], 1, bit2);
    }
    for (int i = 0; i < m; i++){
        char c;
        cin >> c;
        if (c == 'C'){
            int x, v;
            cin >> x >> v;
            upd(a[x], -1, bit2);
            upd(v, 1, bit2);
            upd(x, v-a[x], bit1);
            a[x] = v;
        }
        else if (c == 'S'){
            int l, r;
            cin >> l >> r;
            cout << q(r, bit1) - q(l-1, bit1) << '\n';
        }
        else {
            int v;
            cin >> v;
            cout << q(v, bit2) << '\n';
        }
    }
}