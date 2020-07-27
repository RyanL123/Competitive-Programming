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

struct e {
    int i, x, y;
};
bool cmp1(e a, e b) {
    return a.x > b.x;
}
bool cmp2(e a, e b) {
    return a.y > b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<e> v;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        v.pb({i, x, y});
    }
    sort(all(v), cmp1);
    sort(v.begin(), v.begin()+k, cmp2);
    cout << v.front().i << '\n';
}