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

const int m = 1e9+7, MM = 1e5+5;
int dp[MM][100];

int choose(int n, int k){
    if (k == 0) return 1;
    if (n == k) return 1;
    if (k > n) return 0;
    if (dp[n][k] != 0) return dp[n][k];
    return dp[n][k] = choose(n-1, k)%m + choose(n-1, k-1)%m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, x;
    cin >> n >> k;
    vector<ll> keys;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        keys.pb(x);
    }
    srt(keys);
    for (int i = 0; i < n; i++){
        ans = (ans%m + (keys[i]%m * choose(i, k-1)%m)%m)%m;
    }
    cout << ans << '\n';
}
