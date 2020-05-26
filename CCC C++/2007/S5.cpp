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
#define inf 0x3f3f3f3f

int dp[505][30005], psa[30005];

int f(int i, int j){
    return psa[i] - psa[j-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k, w;
        cin >> n >> k >> w;
        memset(dp, 0, sizeof(dp));
        memset(psa, 0, sizeof(psa));
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            psa[i] = psa[i-1] + x;
        }
        for (int i = 1; i <= k; i++){
            for (int j = 1; j <= n; j++){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if (j >= w){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w] + f(j, j-w+1));
                }
            }
        }
        cout << dp[k][n] << '\n';
    }
}