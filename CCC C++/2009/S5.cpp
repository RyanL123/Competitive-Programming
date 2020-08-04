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

int M, N, K, d[30005][1005];

bool check(int x, int y, int h, int k, int r) {
    return (x-h)*(x-h)+(y-k)*(y-k)<=r*r;
}

void add(int x, int y, int r, int b) {
    int w = 0;
    for (int i = min(M+1, y+r); i >= y; i--) {
        while (check(x+w+1, i, x, y, r)) w++;
        d[i][min(x+w+1, N+1)] -= b, d[i][max(1, x-w)] += b;
    }
    w = r+1;
    for (int i = y-1; i >= max(1, y-r); i--) {
        while (!check(x+w, i, x, y, r)) w--;
        d[i][min(x+w+1, N+1)] -= b, d[i][max(1, x-w)] += b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N >> K;
    for (int i = 0, x, y, r, b; i < K; i++) {
        cin >> x >> y >> r >> b;
        add(x, y, r, b); 
    }
    int mx = 0;
    for (int i = 1; i <= M+1; i++) {
        for (int j = 1; j <= N+1; j++) {
            d[i][j] += d[i][j-1];
            mx = max(d[i][j], mx);
        }
    }
    int ans = 0;
    for (int i = 1; i <= M+1; i++) {
        for (int j = 1; j <= N+1; j++) {
           ans += (d[i][j] == mx);
        }
    }
    cout << mx << '\n' << ans << '\n';
}