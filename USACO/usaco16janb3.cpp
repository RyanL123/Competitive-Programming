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

int f[2005][2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n, x = 1000, y = 1000, ans = inf, t = 0;
    cin >> n;
    memset(f, -1, sizeof(f));
    f[1000][1000] = 0;
    for (int i = 0, s; i < n; i++) {
        char d;
        cin >> d >> s;
        
        for (int j = 0; j < s; j++) {
            t++;
            if (d == 'N') {
                y++;
                if (f[x][y] != -1) ans = min(ans, t-f[x][y]);
                f[x][y] = t;
            }
            if (d == 'S') {
                y--;
                if (f[x][y] != -1) ans = min(ans, t-f[x][y]);
                f[x][y] = t;
            }
            if (d == 'E') {
                x++;
                if (f[x][y] != -1) ans = min(ans, t-f[x][y]);
                f[x][y] = t;
            }
            if (d == 'W') {
                x--;
                if (f[x][y] != -1) ans = min(ans, t-f[x][y]);
                f[x][y] = t;
            }
        }
    }
    cout << (ans==inf?-1:ans) << "\n";
}