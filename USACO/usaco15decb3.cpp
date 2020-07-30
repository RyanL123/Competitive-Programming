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

vii e[55];
int bad[55], drank[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    int n, m, d, s;
    cin >> n >> m >> d >> s;
    for (int i = 0, p, mm, t; i < d; i++) {
        cin >> p >> mm >> t;
        e[p].eb(t, mm);
    }
    for (int i = 0, p, t; i < s; i++) {
        cin >> p >> t;
        for (int j = 0; j < e[p].size(); j++) {
            if (e[p][j].first < t && !drank[p][e[p][j].second]) {
                bad[e[p][j].second]++;
                drank[p][e[p][j].second] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            if (bad[e[i][j].second] == s) {
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
}