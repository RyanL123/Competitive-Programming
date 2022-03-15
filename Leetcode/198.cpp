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

int rob(vector<int>& nums) {
    int n = nums.size();
    int dp[2][n+1];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        dp[1][i] = dp[0][i-1] + nums[i];
    }
    return max(dp[1][n-1], dp[0][n-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}