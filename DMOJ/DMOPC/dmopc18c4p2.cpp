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

int dp[710], a[710];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = a[1]-a[2];
    for (int i = 2; i <= n; i++){
        int day1 = dp[i-1]+a[i];
        int day2 = dp[i-1]-a[i];
        if (abs(day1) < abs(day2)) dp[i] = day1;
        else dp[i] = day2;
    }
    cout << dp[n];
}