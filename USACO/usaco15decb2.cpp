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

int lim[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m, prev = 1;
    cin >> n >> m;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        for (int j = prev; j < prev+x; j++) lim[j] = y;
        prev += x;
    }
    int ans = 0;
    prev = 1;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        for (int j = prev; j < prev+x; j++) ans = max(ans, y-lim[j]);
        prev += x;
    }
    cout << ans << '\n';
}