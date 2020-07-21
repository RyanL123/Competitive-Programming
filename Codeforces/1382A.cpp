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
    while (t--) {
        int n, m;
        cin >> n >> m;
        int frq[1005];
        memset(frq, 0, sizeof(frq));
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            frq[x]++;
        }
        int ans = -1;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (frq[x] != 0) ans = x;
        }
        cout << (ans==-1?"NO":"YES") << "\n";
        if (ans != -1) cout << 1 << ' ' << ans << '\n';
    }
}