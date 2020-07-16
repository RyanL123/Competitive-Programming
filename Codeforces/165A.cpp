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

int n, ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vii v;
    for (int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        v.eb(x, y);
    }
    for (int i = 0; i < n; i++){
        int x = v[i].first, y = v[i].second;
        bool t = false, b = false, l = false, r = false;
        for (int j = 0; j < n; j++){
            if (j != i) {
                t |= (v[j].first == x && v[j].second > y);
                b |= (v[j].first == x && v[j].second < y);
                l |= (v[j].first < x && v[j].second == y);
                r |= (v[j].first > x && v[j].second == y);
            }
        }
        ans += (t && b && l && r);
    }
    cout << ans << '\n';
}