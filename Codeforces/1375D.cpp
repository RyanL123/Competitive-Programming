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

int mex(vi v) {
    int ret = 0;
    srt(v);
    for (int i : v) {
        if (ret == i) ret++;
    }
    return ret;
}

bool done(vi &v) {
    for (int i = 0; i < v.size(); i++) {
        if (i != v[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            v.pb(x);
        }
        vi steps;
        while (!done(v)) {
            int m = mex(v);
            if (m == n) {
                for (int i = 0; i < n; i++) {
                    if (v[i] != i) {
                        v[i] = n;
                        steps.pb(i+1);
                        break;
                    }
                }
            }
            else {
                v[m] = m;
                steps.pb(m+1);
            }
        }
        cout << steps.size() << '\n';
        for (int i : steps) cout << i << ' ';
        cout << '\n';
    }
}