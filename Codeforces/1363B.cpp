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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int n = s.length();
        int pfx0[n+1], pfx1[n+1];
        memset(pfx0, 0, sizeof(pfx0));
        memset(pfx1, 0, sizeof(pfx1));
        for (int i = 1; i <= n; i++){
            pfx0[i] = pfx0[i-1] + (s[i-1]=='0');
            pfx1[i] = pfx1[i-1] + (s[i-1]=='1');
        }
        int ans = min(pfx1[n], pfx0[n]);
        for (int i = 1; i <= n; i++){
            ans = min(ans, pfx0[i]+pfx1[n]-pfx1[i]);
            ans = min(ans, pfx1[i]+pfx0[n]-pfx0[i]);
        }
        cout << ans << "\n";
    }
}