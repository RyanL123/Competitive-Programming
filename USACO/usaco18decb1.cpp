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

int c[3], m[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    for (int i = 0; i < 3; i++) cin >> c[i] >> m[i];
    for (int i = 0; i < 100; i++) {
        int nxt = (i+1)%3, cnt = min(m[i%3], c[nxt]-m[nxt]);
        m[nxt] += cnt, m[i%3] -= cnt;
    }
    cout << m[0] << '\n' << m[1] << '\n' << m[2] << '\n';
}