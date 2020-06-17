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

const ll MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<ll, ll>> obj;
    for (int i = 0; i < N; i++){
        ll v, d;
        cin >> v >> d;
        obj.eb(d, v);
    }
    ll t = 0;
    ll ans = 0;
    srt(obj);
    for (int i = N-1; i >= 0; i--){
        ans += (obj[i].second - t*obj[i].first)%MOD;
        if (i > 0) obj[i-1].second += obj[i-1].first;
        t++;
    }
    cout << ((ans%MOD)+MOD)%MOD << '\n';
}