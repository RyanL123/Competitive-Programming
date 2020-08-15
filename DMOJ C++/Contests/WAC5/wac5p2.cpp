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

const int MM = 2e5+5;
int a[MM], mx[MM], mn[MM];
bool ok(int ind, int lo, int hi) {
    return lo <= mn[ind] && hi >= mx[ind];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> a[i];
    mx[N-1] = mn[N-1] = a[N-1];
    for (int i = N-2; i >= 0; i--) {
        mx[i] = max(a[i], mx[i+1]);
        mn[i] = min(a[i], mn[i+1]);
    }
    for (int i = 0, L, E; i < Q; i++) {
        cin >> L >> E;
        int l = 0, r = N-1, lo = L-E, hi = L+E;
        if (!ok(N-1, lo, hi)) {
            cout << "0\n";
            continue;
        }
        while (l <= r) {
            int m = (l+r)/2;
            if (ok(m, lo, hi)) r = m-1;
            else l = m+1;
        }
        cout << N-l << '\n';
    }
}