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

bool check(int x, int y, int r) {
    return x*x+y*y<=r*r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r;
    while (cin >> r) {
        if (r == 0) break;
        int x = 0, y = 0, cnt = 0;
        for (int x = r; x >= 0; x--) {
            while (check(x, y+1, r)) y++;
            cnt += y+1;
        }
        cout << cnt*4-4*r-3 << '\n';
    }
}