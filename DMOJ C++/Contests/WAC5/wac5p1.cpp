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

const int MM = 1e3+5;
bool done[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vi v;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        v.pb(x);
    }
    srt(v);
    int cnt = 0, ans = 0;
    while (cnt < N) {
        int ptr = N-1;
        while (done[ptr]) ptr--;
        if (ptr < 0) break;
        done[ptr] = true;
        cnt++;
        int mx = v[ptr], cur = mx;
        while (ptr >= 0) {
            if (!done[ptr] && v[ptr] < cur) {
                done[ptr] = true;
                cur = v[ptr];
                cnt++;
            }
            ptr--;
        }
        ans += mx;
    }
    cout << ans << '\n';
}