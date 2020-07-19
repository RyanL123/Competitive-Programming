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

const int mod = 1e9+7;
int dp[1005][1100][2][2], done;
string s;
int f(int pos, int mask, bool limit, bool leading){
    if (dp[pos][mask][limit][leading] != -1) return dp[pos][mask][limit][leading];
    if (pos == s.size()){
        return dp[pos][mask][limit][leading] = (mask & done) == done;
    }
    ll ret = 0;
    int mx = limit?s[pos]-'0':9;
    for (int i = 0; i <= mx; i++){
        ret += f(pos+1, leading && i == 0 ? mask : mask|(1<<i), limit && i == mx, leading && i == 0);
        ret %= mod;
    }
    return dp[pos][mask][limit][leading] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0, x; i < n; i++){
        cin >> x;
        done |= (1<<x);
    }
    cin >> s;
    cout << f(0, 0, true, true) + (done == 1) << '\n';
}