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
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;
    vii v;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        v.eb(x, y);
    }
    srt(v);
    int t = 0;
    for (int i = 0; i < n; i++) {
        pii p = v[i];
        t = max(t, p.first);
        t += p.second;
    }
    cout << t << "\n";
}