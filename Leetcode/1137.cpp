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

int tribonacci(int n) {
    int dp[50];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0, dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}