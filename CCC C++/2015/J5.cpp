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

int dp[300][300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) dp[1][i] = 1;
    for (int i = 2; i <= k; i++){
        dp[i][i] = 1;
        for (int j = i+1; j <= n; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i][j-i];
        }
    }
    cout << dp[k][n] << '\n';
}