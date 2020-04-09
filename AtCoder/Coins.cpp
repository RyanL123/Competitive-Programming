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

long double dp[3010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        double prob;
        cin >> prob;
        for (int j = n+1; j >= 0; j--){
            if (i == 0) dp[j] = dp[j] * (1 - prob);
            else dp[j] = dp[j-1] * prob + dp[j] * (1 - prob);
        }
    }
    long double ans = 0;
    for (int i = ceil((double)n/2); i <= n; i++){
        ans += dp[i];
    }
    cout << setprecision(10) << ans;
}