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

int s[105], c[2][105], pre = 0, cur = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        s[x] = i;
    }
    for (int i = 1; i <= n; i++) cin >> c[cur][i];
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) c[pre][s[j]] = c[cur][j];
        swap(pre, cur);
    }
    for (int i = 1; i <= n; i++) cout << c[cur][i] << '\n';
}