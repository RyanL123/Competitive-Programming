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

struct guess{
    int a, b, g;
};

int solve(vector<guess> &v, int initial) {
    int a[4] = {0, 0, 0, 0};
    a[initial] = 1;
    int ret = 0;
    for (int i = 0; i < v.size(); i++) {
        swap(a[v[i].a], a[v[i].b]);
        ret += a[v[i].g];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    cin >> n;
    vector<guess> v;
    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        v.pb({a, b, g});
    }
    cout << max(solve(v, 1), max(solve(v, 2), solve(v, 3))) << '\n';
}