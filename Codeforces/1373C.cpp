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
        ll n = s.size(), res = n;
        int pfx[n+1], f[n+1];
        pfx[0] = 0;
        memset(f, -1, sizeof(f));
        for (int i = 1; i <= n; i++){
            pfx[i] = s[i-1]=='+'?1:-1;
            pfx[i] += pfx[i-1];
            if (pfx[i] < 0 && f[-pfx[i]] == -1){
                f[-pfx[i]] = i;
            }
        }
        for (int i = 1; i <= n; i++){
            if (f[i] == -1) break;
            res += f[i];
        }
        cout << res << "\n";
    }
}