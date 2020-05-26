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
#define inf 0x3f3f3f3f

bool solve(int a, int b, int c, int d, vii r){
    int x = r[0].first, y = r[0].second;
    int x1 = r[1].first, y1 = r[1].second;
    int x2 = r[2].first, y2 = r[2].second;
    int up = d-c, right = b-a;
    if (a != 0 && x1 == x && x2 == x) return false;
    if (b != 0 && x1 == x && x2 == x) return false;
    if (c != 0 && y1 == y && y2 == y) return false;
    if (d != 0 && y1 == y && y2 == y) return false;
    return !(up > y2-y || up < y1-y || right > x2-x || right < x1-x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int right = b-a;
        int up = d-c;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        vii r;
        r.eb(x, y), r.eb(x1, y1), r.eb(x2, y2);
        if (solve(a, b, c, d, r)) cout << "YES\n";
        else cout << "NO\n";
    }
}