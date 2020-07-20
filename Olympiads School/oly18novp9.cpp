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

int dp[15][15][2][2][2];
string L, R;
int f(int pos, int lst, bool limit, bool good, bool leading, string &str) {
    int &ret = dp[pos][lst][limit][good][leading];
    if (ret != -1) return ret;
    if (pos == str.size()) return ret = good;
    ret = 0;
    int bound = limit?str[pos]-'0':9;
    for (int i = 0; i <= bound; i++) {
        bool ngood = good&&(abs(i-lst)>=2);
        if (leading) ngood = true;
        ret += f(pos+1, i, limit&&(i==bound), ngood, leading&&(i==0), str);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> R;
    memset(dp, -1, sizeof(dp));
    int r = f(0, 14, true, true, true, R);
    memset(dp, -1, sizeof(dp));
    int l = f(0, 14, true, true, true, L);
    int ans = r-l;
    bool flag = true;
    for (int i = 1; i < L.size(); i++) {
        flag &= (abs(L[i] - L[i-1]) >= 2);
    }
    ans += flag;
    cout << ans << "\n";
}
