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

ll n, a[16][16], pre[1 << 17], dp[1 << 17];

// Recursively determines all subsets of not taken rabbits
void solve(int i, const vi &nt, ll score, int mask, int taken){
    if (i == nt.size()){
        dp[mask] = max(dp[mask], score + pre[taken]);
        return;
    }
    // Don't take next rabbit
    solve(i+1, nt, score, mask, taken);
    // Take next rabbit
    solve(i+1, nt, score, mask | (1 << nt[i]), taken | (1 << nt[i]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for (int mask = 0; mask < (1<<n); mask++){
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                for (int j = i+1; j < n; j++){
                    if (mask & (1 << j)){
                        pre[mask] += a[i][j];
                    }
                }
            }
        }
    }
    for (int mask = 0; mask < (1<<n); mask++){
        vi inactive;
        for (int i = 0; i < n; i++) if (!(mask & (1 << i))) inactive.pb(i);
        solve(0, inactive, dp[mask], mask, 0);
    }
    cout << dp[(1<<n)-1];
}