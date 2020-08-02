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

bool g[2005][2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2;
    for (int i = 0; i < 3; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000, x2 += 1000, y1 += 1000, y2 += 1000;
        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) g[j][k] = (i==2?false:true);
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) ans += g[i][j];
    }
    cout << ans << '\n';
}