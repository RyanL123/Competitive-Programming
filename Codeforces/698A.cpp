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

int a[105], dp[105][3];
// 0 = none, 1 = contest, 2 = gym

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][1] = dp[0][2] = inf;
    for (int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+1;
        if (a[i] == 0) {
            dp[i][1] = dp[i-1][1]+1;
            dp[i][2] = dp[i-1][2]+1;
        }
        else if (a[i] == 1){
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = inf;
        }
        else if (a[i] == 2){
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = inf;
        }
        else {
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << "\n";
}