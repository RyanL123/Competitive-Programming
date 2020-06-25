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
    int n, d;
    cin >> n >> d;
    vii f;
    for (int i = 0; i < n; i++){
        int m, s;
        cin >> m >> s;
        f.eb(m, s);
    }
    srt(f);
    ll tot = 0, ans = 0;
    for (int l = 0, r = 0; r < n; r++){
        tot += f[r].second;
        while (f[r].first - f[l].first >= d){
            tot -= f[l].second;
            l++;
        }
        ans = max(ans, tot);
    }
    cout << ans << '\n';
}