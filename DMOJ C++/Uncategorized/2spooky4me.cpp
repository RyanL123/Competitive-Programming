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

bool cmp(pii a, pii b) {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, L, S;
    cin >> N >> L >> S;
    vii v;
    for (int i = 0, a, b, s; i < N; i++) {
        cin >> a >> b >> s;
        v.eb(a, s);
        v.eb(b+1, -s);
    }
    sort(all(v), cmp);
    int cur = 0, lstInd = 1, ans = 0;
    for (int i = 0; i < N*2; i++) {
        if (cur < S) {
            ans += v[i].first-lstInd;
        }
        lstInd = v[i].first, cur += v[i].second;
    }
    if (cur < S) ans += L-lstInd;
    cout << ans+1 << '\n';
}