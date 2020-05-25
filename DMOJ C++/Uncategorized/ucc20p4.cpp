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

int dp[5005], a[5005];

int group2(int a, int b){
    return a+b-min(a,b)*0.25;
}

int group3(int a, int b, int c){
    return a+b+c-min(a, min(b, c))*0.5;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[1] = a[1];
    for (int i = 2; i <= n; i++){
        int x = inf, y = inf, z = dp[i-1] + a[i];;
        if (i >= 3) x = dp[i-3] + group3(a[i], a[i-1], a[i-2]);
        if (i >= 2) y = dp[i-2] + group2(a[i], a[i-1]);
        dp[i] = min(x, min(y, z));
    }
    cout << dp[n] << "\n";
}