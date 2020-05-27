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

int dp[5005][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n, a = 0, b = 1, c = 2;
    cin >> n >> s;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j+i <= n; j++){
            dp[j][c] = i;
            if (s[j] == s[j+i-1]) dp[j][c] = dp[j+1][a];
            else dp[j][c] = 1 + min(dp[j+1][b], dp[j][b]);
        }
        a++, b++, c++;
        if (a == 3) a = 0;
        if (b == 3) b = 0;
        if (c == 3) c = 0;
    }
    cout << dp[0][n%3] << '\n';
}