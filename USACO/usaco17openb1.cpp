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
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y, step = 1, ans = 0;
    cin >> x >> y;
    int cur = x;
    while (cur != y) {
        int nxt = x+step;
        while (cur != nxt) {
            if (cur == y) break;
            ans++, cur += abs(step)/step;
        }
        step *= -2;
    }
    cout << ans << "\n";
}