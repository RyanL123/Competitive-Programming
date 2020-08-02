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

int N, ans, a[105], e[105];

void solve(int m) {
    int r = 1;
    memset(e, -1, sizeof(e));
    e[m] = 1;
    while (true) {
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (e[i] == r) {
                flag = true;
                for (int j = i-1; j >= 0; j--) {
                    if (a[i]-a[j] <= r && e[j] == -1) e[j] = r+1;
                }
                for (int j = i+1; j < N; j++) {
                    if (a[j]-a[i] <= r && e[j] == -1) e[j] = r+1;
                }
            }
        }
        if (!flag) break;
        r++;
    }
    int tot = 0;
    for (int i = 0; i < N; i++) tot += (e[i] != -1);
    ans = max(ans, tot);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a+N);
    for (int i = 0; i < N; i++) {
        solve(i);
    }
    cout << ans << '\n';
}