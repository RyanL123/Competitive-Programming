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

const int MM = 1e5+5;
int s[MM][6];
map<ull, vi> m;

ull calc(int a[]) {
    vi v;
    for (int i = 0; i < 6; i++) {
        v.pb(a[i]);
    }
    srt(v);
    ull ret = 0;
    for (int i = 0; i < 6; i++) {
        ret += v[i];
        ret *= 31;
    }
    return ret;
}

bool right(int id1, int id2, int st) {
    for (int i = 0; i < 6; i++) {
        if (s[id1][i] != s[id2][(st+i)%6]) return false;
    }
    return true;
}

bool left(int id1, int id2, int st) {
    for (int i = 0; i < 6; i++) {
        int ind = st-i;
        if (ind < 0) ind += 6;
        if (s[id1][i] != s[id2][ind]) return false;
    }
    return true;
}

bool cmp(int id1, int id2) {
    for (int i = 0; i < 6; i++) {
        if (right(id1, id2, i) || left(id1, id2, i)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> s[i][j];
        }
        ll hsh = calc(s[i]);
        m[hsh].pb(i);
    }
    for (pair<ull, vi> p : m) {
        int sz = p.second.size();
        for (int j = 0; j < sz; j++) {
            for (int k = j+1; k < sz; k++) {
                if (cmp(p.second[j], p.second[k])) {
                    cout << "Twin snowflakes found.\n";
                    return 0;
                }
            }
        }
    }
    cout << "No two snowflakes are alike.\n";
}