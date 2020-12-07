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

const int MM = 1e6+5;
int st[MM], ed[MM], c[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    memset(st, -1, sizeof(st));
    memset(ed, -1, sizeof(ed));
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        if (st[c[i]] == -1) st[c[i]] = i;
    }
    for (int i = N-1; i >= 0; i--) {
        if (ed[c[i]] == -1) ed[c[i]] = i;
    }
    int mx = 0;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        if (st[a] == -1 || st[b] == -1) continue;
        else mx = max(mx, ed[b]-st[a]+1);
    }
    cout << mx << '\n';
}