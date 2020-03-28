#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

ll stones[200010], dp[200010];

ll calc(ll x, ll y, ll c){
    return (x-y)*(x-y) + c;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++){
        cin >> stones[i];
    }
    // No convex hull optimization
    for (int i = 2; i <= n; i++){
        ll minCost = LONG_LONG_MAX;
        for (int j = 1; j < i; j++){
            ll cost = dp[j] + calc(stones[i], stones[j], c);
            minCost = min(cost, minCost);
        }
        dp[i] = minCost;
    }
    cout << dp[n];
}
