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
    ll r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    ld d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    cout << ceil(d/(r*2)) << '\n';
}