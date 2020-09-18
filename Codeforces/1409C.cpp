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
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int space = n-1;
        while ((y-x)%space != 0) space--;
        int inc = (y-x)/space;
        vi ans;
        for (int i = x; i <= y; i+= inc) ans.pb(i); 
        int cur = x-inc;
        while (ans.size() < n && cur > 0) {
            ans.pb(cur);
            cur -= inc;
        }
        cur = y+inc;
        while (ans.size() < n) {
            ans.pb(cur);
            cur += inc;
        }
        srt(ans);
        for (int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}