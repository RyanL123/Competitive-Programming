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

const int MM = 1e4+5, mod = 1e9+7;
int dp[MM][105][2], d;
string k;

int f(int pos, int m, bool limit){
    int &ret = dp[pos][m][limit];
    if (ret != -1) return ret;
    if (pos == k.size()) return ret = (m == 0);
    ret = 0;
    int bound = limit?k[pos]-'0':9;
    for (int i = 0; i <= bound; i++) {
        ret += f(pos+1, (m + i%d)%d, limit&&i==bound);
        ret %= mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0, true)-1 << "\n";
}