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
ll n, t, da[MM], db[MM], dc[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    for (ll i = 0, L, R, a, b, c; i < n; i++){
        cin >> L >> R >> a >> b >> c;
        ll B = -2*a*L+b;
        ll C = a*L*L - b*L + c;
        da[R+1]-=a, da[L]+=a;
        db[R+1]-=B, db[L]+=B;
        dc[R+1]-=C, dc[L]+=C;
    }
    for (ll i = 1; i <= t; i++){
        da[i] += da[i-1];
        db[i] += db[i-1];
        dc[i] += dc[i-1];
        cout << da[i]*i*i+db[i]*i+dc[i] << ' ';
    }
}