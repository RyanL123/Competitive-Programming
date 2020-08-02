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

bool f(int x, int y, int x1, int y1, int x2, int y2) {
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    bool can = false;
    x1 *= 2, y1 *= 2, x2 *= 2, y2 *= 2, x3 *= 2, y3 *= 2, x4 *= 2, y4 *= 2, x5 *= 2, y5 *= 2, x6 *= 2, y6 *= 2;
    for (int i = x1; i <= x2; i++) {
        if (!f(i, y1, x3, y3, x4, y4) && !f(i, y1, x5, y5, x6, y6)) {
            can = true;
            break;
        }
        else if (!f(i, y2, x3, y3, x4, y4) && !f(i, y2, x5, y5, x6, y6)) {
            can = true;
            break;
        }
    }
    for (int i = y1; i <= y2; i++) {
        if (!f(x1, i, x3, y3, x4, y4) && !f(x1, i, x5, y5, x6, y6)) {
            can = true;
            break;
        }
        else if (!f(x2, i, x3, y3, x4, y4) && !f(x2, i, x5, y5, x6, y6)) {
            can = true;
            break;
        }
    }
    cout << (can?"YES\n":"NO\n");
}