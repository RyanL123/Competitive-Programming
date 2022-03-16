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

int climbStairs(int n) {
    int dp[n+10];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
    }
    return dp[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 45; i++) cout << climbStairs(i) << endl;
}