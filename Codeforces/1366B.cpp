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
    while (t--){
        int n, x, m;
        cin >> n >> x >> m;
        int L = x, R = x;
        for (int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            if (l > R || r < L) continue;
            L = min(L, l), R = max(r, R);
        }
        cout << R-L+1 << '\n';
    }
}