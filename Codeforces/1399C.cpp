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
        int n;
        cin >> n;
        int frq[205];
        memset(frq, 0, sizeof(frq));
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            frq[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= 200; i++) {
            int cur = 0;
            for (int j = 1; j <= i/2; j++) {
                if (j == i-j) cur += frq[j]/2;
                else cur += min(frq[j], frq[i-j]);
            }
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
}