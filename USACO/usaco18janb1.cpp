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
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int c = 0;
    c += f(x1, y1, x3, y3, x4, y4);
    c += f(x1, y2, x3, y3, x4, y4);
    c += f(x2, y2, x3, y3, x4, y4);
    c += f(x2, y1, x3, y3, x4, y4);
    if (c == 4) cout << "0\n";
    else if (c < 2) cout << (x2-x1)*(y2-y1) << "\n";
    else cout << (x2-x1)*(y2-y1) - (min(x2, x4)-max(x1, x3))*(min(y2, y4)-max(y1, y3)) << '\n';
}