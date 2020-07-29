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

int r[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n, ans = inf;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= n; j++) {
            int dis = j<i?n-i+j:j-i;
            cur += r[j]*dis;
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}