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

const int MM = 655, MN = 5e5+5;
ll n, d[MM][MM], bit[MM][MM], r1[MN], r2[MN];

void add(int x, int y){
    for (int i = x; i <= MM; i += (i&-i)){
        for (int j = y; j <= MM; j += (j&-j)){
            bit[i][j]++;
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
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> r1[i] >> r2[i];
        d[r1[i]][r2[i]]++;
        r1[i]++, r2[i]++;
        add(r1[i], r2[i]);
    }
    for (int i = 0; i < n; i++){
        ll tl, tr, bl, br;
        tr = qry(654, 654);
        tl = qry(r1[i], 654);
        br = qry(654, r2[i]);
        bl = qry(r1[i], r2[i]);
        cout << tr - tl - br + bl + 1LL << ' ';
        ll outlier = 0;
        tr = qry(r1[i]-1, r2[i]-1);
        if (r2[i]-1 == 650) outlier += d[r1[i]-1][0];
        if (r1[i]-1 == 650) outlier += d[0][r2[i]-1];
        cout << n - tr - outlier << '\n';
    }
}