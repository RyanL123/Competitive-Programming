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

string k;
const int MM = 1e5+5, mod = 1e9+7;
int dp[MM][2][2][2][2];

int f(int pos, bool one, bool ten, bool hundred, bool limit){
    int &ret = dp[pos][one][ten][hundred][limit];
    if (ret != -1) return ret;
    if (pos == k.size()) return ret = (ten && !hundred);
    ret = 0;
    int bound = limit?k[pos]-'0':9;
    for (int i = 0; i <= bound; i++) {
        ret += f(pos+1, one|(i==1), ten|(one&&(i==0)), hundred|(ten&&(i==0)), limit&&i==bound);
        ret %= mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    memset(dp, -1, sizeof(dp));
    cout << f(0, false, false, false, true) << '\n';
}