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

string longestPalindrome(string s) {
    bool dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    int n = s.size();
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        if (i < n-1) dp[i][i+1] = s[i] == s[i+1];
    }
    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= i; j--) {
            if (i > 0 && j < n-1) dp[i-1][j+1] = dp[i][j] && s[i-1] == s[j+1];
        }
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] && j-i > r-l) l = i, r = j;
        }
    }
    return s.substr(l, r-l+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << longestPalindrome("aaaaa") << endl;
}