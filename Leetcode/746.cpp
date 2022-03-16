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

int minCostClimbingStairs(vector<int>& cost) {
    int dp[1005]; 
    memset(dp, 0, sizeof(dp));
    int n = cost.size();
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1 = {10,15,20}, v2 = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(v1) << endl;
    cout << minCostClimbingStairs(v2) << endl;
}