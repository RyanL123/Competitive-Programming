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

ll dp[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, r;
    vector<tuple<int, int, int>> interval;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        interval.pb(make_tuple(e, s, v));
    }
    sort(interval.begin(), interval.end());
    for (int i = 1; i <= n; i++){
        dp[i] = max(dp[i], dp[i-1]);
        for (int j = 0; j < m; j++){
            if (get<0>(interval[j]) == i){
                int s = get<1>(interval[j]);
                int v = get<2>(interval[j]);
                if (s - r >= 1){
                    dp[i] = max(dp[i], dp[s-r]+v);
                }
                else {
                    dp[i] = max(dp[i], (ll)v);
                }
            }
        }
    }
    cout << dp[n];
}