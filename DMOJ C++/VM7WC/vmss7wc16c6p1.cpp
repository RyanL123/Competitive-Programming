#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vii v;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    ld ans = 0;
    for (int i = 0; i < n-1; i++){
        ans += v[i].first * v[i+1].second;
        ans -= v[i].second * v[i+1].first;
    }
    ans += v[n-1].first * v[0].second;
    ans -= v[n-1].second * v[0].first;
    ans = abs(ans);
    ans /= 2;
    cout << ceil(ans);
}
